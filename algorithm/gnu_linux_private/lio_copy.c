/*ommand line to build the program:
 * cc -o lio_copy lio_copy.c -non_shared -O0 -L/usr/ccs/lib \
 *       -laio -pthread
 */


#include <unistd.h>
#include <aio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>
#include <malloc.h>

#define FOR_EACH_FILE   for (i = 0; i < out_cnt; i++)

#define BUF_CNT 2                     /* number of buffers */


int main(int argc, char **argv) {
	register int    i, rec_cnt = 0, out_cnt = 0;
	char            outname[128], temp[8];
	int             in_file, out_file[AIO_LISTIO_MAX], len;
	typedef char   *buf_p;
	buf_p           buf[BUF_CNT];
	aiocb_t         a_write[AIO_LISTIO_MAX], *wait_list[AIO_LISTIO_MAX];
	size_t          xfer_size;
	int             buf_index, total[AIO_LISTIO_MAX], ret;
	struct sigevent lio_sigevent = {0,0};

	/* * * * Check the number of input arguments * * * */

	if (argc < 5) {
		fprintf(stderr, "Usage: %s in_file out_file buffsz-in-kb
                        #-out-files\n", argv[0]);
                exit(0);
	}

    /* * * * Open the input file * * * */

	if ((in_file = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(errno);
    }
    printf("\tOpened Input File %s\n", argv[1]);

    /* * * * Open the output files * * * */

    out_cnt = atoi(argv[4]);
    if ((out_cnt <=  0) || (out_cnt > AIO_LISTIO_MAX)) {
		fprintf(stderr, "Number of output files must be 1-%d.\n",AIO_LISTIO_MAX);
		exit(EINVAL);
    }

    outname[0] = '\0';
    len = strlen(argv[2]);
    strcpy(outname, argv[2]);

	for (i = 0; i < out_cnt; i++) {
		sprintf(&outname[len], "%d", i);
		if ((out_file[i] = open(outname, O_WRONLY|O_CREAT, 0777)) == -1) {
			perror(outname);
			exit(errno);
		}
		printf("\tOpened output file %s\n", outname);
	}

    /* * * * Calculate the transfer size (# bufs * 1024) * * * */

	xfer_size = atol(argv[3]) * 1024;

    /* * * * Allocate buffers for file copy * * * */

    for (buf_index = 0; buf_index < BUF_CNT; buf_index++) {
		buf[buf_index] = (buf_p) malloc(xfer_size);
		if (buf[buf_index] == NULL) {
			perror("malloc");
			exit(1);
		}
	}

    buf_index = 0;

    /* * * * Init the aio control blocks and wait list * * * */

    FOR_EACH_FILE {
            a_write[i].aio_fildes = out_file[i];
            a_write[i].aio_lio_opcode = LIO_WRITE;
            a_write[i].aio_sigevent.sigev_signo = 0;
            wait_list[i] = &a_write[i];
            total[i] = 0;
    }

    /* * * * Copy from in_file to out_file * * * */

    while (in_file != -1) {
            int buf_len;

    /* * * * Read the next buffer of information * * * */

            buf_len = read(in_file, buf[buf_index], xfer_size);

            if (rec_cnt) {  /* will be >1 on all but the first write... */

    /* * * * Update the bytes written to set new offset * * * */

                    FOR_EACH_FILE {
                            errno = aio_error(&a_write[i]);
                            ret = aio_return(&a_write[i]);
                            if (ret == -1) {
                                    perror("Write error");
                                    exit(1);
                            } else {
                                    total[i] += ret;
                            }
                    }
            }

     * * * Check for end-of-file (won't have filled buffer) * * */

            if (buf_len <= 0)
                    break;

     * * * Set the buffer up for the next write * * * */

            FOR_EACH_FILE {
                    a_write[i].aio_nbytes = buf_len;
                    a_write[i].aio_buf = buf[buf_index];
                    /* if opened for append, ignore offset field */
                    a_write[i].aio_offset = total[i];
            }

            ret = lio_listio(LIO_WAIT, wait_list, out_cnt, &lio_sigevent);
            if (ret) /* report failure status, but don't exit yet */
                    perror("lio_listio");

     * * Update record count, and position to next buffer * * */

            buf_index ^= 1;
            rec_cnt++;
    }

    /* * * * Close the files * * * */

    close(in_file);
    printf("\tClosed input file\n");
    FOR_EACH_FILE {
            close(out_file[i]);
    }
    printf("\tClosed output files\n");
    printf("Copied %d records to %d files\n", rec_cnt * out_cnt, out_cnt);
}
