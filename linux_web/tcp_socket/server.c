#include <stdio.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define SERV_PORT 6666

void sys_err(const char *str) {
  perror(str);
  exit(1);
}

int main(int argc, char* argv[]) {
  int lfd = 0, cfd = 0;
  int ret = 0;
  char buf[BUFSIZ];
  
  struct sockaddr_in serv_addr, clit_addr;
  socklen_t clit_add_len;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(9999);
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd == -1) {
    sys_err("socket error!");
  }

  bind(lfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
  listen(lfd, 128);

  clit_add_len = sizeof(clit_addr);
  cfd = accept(lfd, (struct sockaddr *) &clit_addr, &clit_add_len);

  if (cfd == -1) { 
    sys_err("accept error");
  }

  while (1) {
    ret = read(cfd, buf, sizeof(buf));

    write(STDOUT_FILENO, buf, ret);

    for (int i=0; i <ret; i++) {
      buf[i] = toupper(buf[i]);
    }

    write(cfd, buf, ret);
  }

  close(cfd);
  close(lfd);
  
  return 0;
}
