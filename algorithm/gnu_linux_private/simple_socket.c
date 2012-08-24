#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

static const char* HOST = "bbs.hoopchina.com";
static const char* PAGE = "3333490.html";
static const int PORT = 80;
static const int BUFSIZE = 10485760;

int main(int argc, char** argv) {
  char *buf = (char*)malloc(sizeof(char)*BUFSIZE);
  memset(buf, 0, BUFSIZE);

  char* ip;
  const char* host = HOST ;
  const char* page = PAGE;

  if (argc != 3) {
    fprintf(stderr, "usage, %s hostname path\n", argv[0]);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "error opening socket");
    exit(1);
  }
  
  int ipeln = 15;
  ip = (char*)malloc(ipeln+1);
  struct hostent* hent = gethostbyname(argv[1]);
  if (hent == NULL) {
    fprintf(stderr, "error, no such host");
    exit(1);
  }
  inet_ntop(AF_INET, (void*)hent->h_addr_list[0], ip, ipeln);

  printf("ip addr is %s\n", ip);
  
  struct sockaddr_in remote;
  remote.sin_family = AF_INET;
  inet_pton(AF_INET, ip, (void*)(&(remote.sin_addr.s_addr)));
  remote.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr*)remote, sizeof(struct sockaddr))<0) {
    printf("could not connet");
    exit(1);
  }

  char querystring[100] ;
  sprintf(querystring, "GET %s HTTP/1.1\r\nHost:%s\r\n\r\n", argv[2], argv[1]);

  int sent = 0;
  int seds = 0;
  while (sent < strlen(querystring)) {
      seds = send(sockfd, querystring, strlen(querystring), 0);
      if (seds == -1) {
      perror("can not send query\n");
      exit(-1);
      }
      sent += seds;
  }

  memset(buf, 0, sizeof(buf));
  char all[102400] = {0};
  all[0] = '0';
  FILE* fp = fopen("1.html", "w");
  char *a=all;
  while ( (seds = recv(sockfd, buf, BUFSIZE, 0)) > 0) {
      sprintf(a,  "%s", buf);
      a = a+ seds;

      memset(buf, 0, seds);
  }

  char*end = strstr(all, "\r\n\r\n");
  char* begin = end + 4;
  end = strstr(begin, "\r\n");
  while (end != NULL) {
    begin = end + 2;
    end = strstr(begin, "\r\n");
    fwrite(begin, 1, end-begin, fp);
    
    begin = end +2;
    if (*begin == '0')
      break;
    end = strstr(begin, "\r\n");
  }
  //fprintf(fp, "%s", begin);
  fclose(fp);
  close(sockfd);
  return 0;
}
