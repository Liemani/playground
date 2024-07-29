#include <stdio.h>
#include <unistd.h> // sleep()
#include <fcntl.h>  // fcntl()
#include <stdlib.h> // EXIT_FAILURE
#include <termios.h>  // struct termios

#define READ_BUFFER_SIZE 512

static void	initTermios(void)
{
  struct termios termios;

  tcgetattr(0, &termios);
  termios.c_lflag &= ~ICANON;
  termios.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &termios);
}

int main() {
  initTermios();
  char readBuffer[READ_BUFFER_SIZE];

  int flag = fcntl(0, F_GETFL);
	const int fcntlReturnValue = fcntl(0, F_SETFL, (flag | O_NONBLOCK | O_ASYNC));
  if (fcntlReturnValue == -1) {
  }

  while (1) {
    const ssize_t readBytes = read(0, readBuffer, READ_BUFFER_SIZE);
    printf("readBytes : %zd\n", readBytes);

    sleep(1);
  }

  return 0;
}
