#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <select.h>

void utility_fd_setNonBlock(int fd) {
  int flags = fcntl(fd, F_GETFL);
  fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void utility_fd_setCanon(int fd) {
  struct termios termios;
  tcgetattr(fd, &termios);
  termios.c_lflag |= ICANON;
	tcsetattr(fd, TCSANOW, &termios);
}

int main() {
  FILE* file = fdopen(0, "r");

  utility_fd_setNonBlock(0);
  utility_fd_setCanon(0);

  char* line = NULL;
  size_t lineCap = 0;
  ssize_t numberRead= getline(&line, &lineCap, file);

  printf("numberRead : %zd, line : %s\n", numberRead, line);

  free(line);

  return 0;
}
