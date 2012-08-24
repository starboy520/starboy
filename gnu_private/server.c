#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
int main(int argc, char* argv[]) {
  int listenfd;
  int connectedfd;
  int sockfd;
  int nready, client[FD_SETSIZE];
  ssize_t n;
  fd_set rset, allset;
  
  struct sockaddr_in clientaddr;
  struct sockaddr_in serveraddr;

  listenfd = socket(PF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    exit(-1);
  }

  bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = PF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(7890);

  if (bind(listenfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) != 0) {
    perror("bind");
    exit(-1);
  }
  
  if (listen(listenfd, 512) != 0) {
   perror("listen");
   exit(-1);
  }

  int maxfd = listenfd;
  int maxi = -1;
  
  int i;
  for (i = 0; i < FD_SETSIZE, i++) {
    client[i] = -1;
  }

  FD_ZERO(&allset);
  FD_SET(listenfd, &allset);
  
  for (; ; ) {
    rset = allset;

    nready = select(listenfd, &rset, NULL, NULL, NULL);

    if (FD_ISSET(listenfd, &rset)) {
      clilen = sizeof(clientaddr);
      connectedfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clilen);
      for (int i = 0; i < FD_SETSIZE; i++) {
        if (client[i] < 0) {
          client[i] = connectedfd;
          break;
        }
      }

      if (i == FD_SETSIZE) {
            printf("too many client\n");
            exit(-1);
      }
      FD_SET(connectedfd, &allset);
      if (connectedfd > maxfd) {
        maxfd = connectedfd;
      }

      if (i >maxi) {
        maxi = i;
      }

      if (--nready <= 0) {
        continue;
      }
    }

    for (int i = 0; i < maxi; i++) {
      if ((sockfd = client[i]) < 0) {
        continue;
      }

      if (FD_ISSET(sockfd, &rset)) {
          if ((n = read(sockfd, buf, 100)) == 0) {
            close(sockfd);
            FD_CLR(sockfd, &allset);
            client[i] = -1;
          } else {
            write(sockfd, buf, n);
          }
          if (--nready <= 0) {
            break;
          }
      }
    }
  }
}
          
