#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

const int baudRate = 9600;

int main() {
  fprintf(stderr, "%d\n", __LINE__);

  // Replace "/dev/tty.usbmodem1101" with the correct port on your system
  const char* port = "/dev/tty.usbmodem1101";
  int fd = open(port, O_RDWR | O_NOCTTY | O_SYNC);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  fprintf(stderr, "%d\n", __LINE__);

  struct termios tty;
  if (tcgetattr(fd, &tty) < 0) {
    perror("tcgetattr");
    return 1;
  }

  tty.c_cflag &= ~CSIZE; // Clear character size bits
  tty.c_cflag |= CS8; // Set 8 data bits
  tty.c_cflag &= ~PARENB; // Disable parity
  tty.c_cflag &= ~CSTOPB; // Disable stop bit
  tty.c_cflag |= CREAD | CLOCAL; // Enable receiver and ignore modem status lines
  tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
  tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // Raw input
  tty.c_oflag &= ~OPOST; // Raw output

  // Set baud rate
  cfsetispeed(&tty, baudRate);
  cfsetospeed(&tty, baudRate);

  fprintf(stderr, "%d\n", __LINE__);

  // Apply changes
  if (tcsetattr(fd, TCSANOW, &tty) < 0) {
    perror("tcsetattr");
    return 1;
  }

  char buffer[513];
  int n;

  while (true) {
    printf("start\n");
    n = read(fd, buffer, 3);
    buffer[n] = '\0';
    printf("[%s]", buffer);
  }

  close(fd);
  return 0;
}
