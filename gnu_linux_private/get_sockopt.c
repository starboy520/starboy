//Write a program that prints the default TCP, UDP, and SCTP send and receive buffer sizes and run it on the systems to which you have access.
//
//

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h>
int main(int argc, char* argv[]) {
  
  
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  int rcvbuf;
  int len = sizeof(rcvbuf);
  int ret = getsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &len);

  int mss;
  len = sizeof(mss);
  getsockopt(sock_fd, IPPROTO_TCP, TCP_MAXSEG, &mss, &len);
  printf("defaults: SO_RCVBUF=%d, TCP_MAXSEG=%d\n", rcvbuf, mss);

  struct sockaddr_in servaddr;
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(13);
  inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
  connect(sock_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));

  len=sizeof(rcvbuf);
  getsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &len);
  len = sizeof(mss);
  getsockopt(sock_fd, IPPROTO_TCP, TCP_MAXSEG, &mss, &len);
  printf("defaults, SO_RCVBUF=%d, TCP_MAXSEG=%d\n", rcvbuf, mss);
  return 0;
  return 0;

}
