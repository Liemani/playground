#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
  // Replace "/dev/tty.usbmodem1101" with the correct port on your system
  const char* port = "/dev/tty.usbmodem1101";
  int fd = open(port, O_RDWR | O_NOCTTY | O_SYNC);
  if (fd == -1) {
    perror("open");
    return 1;
  }

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
  cfsetispeed(&tty, 2000000);
  cfsetospeed(&tty, 2000000);

  // Apply changes
  if (tcsetattr(fd, TCSANOW, &tty) < 0) {
    perror("tcsetattr");
    return 1;
  }

  char buffer[3];
  int n;

  int count = 0;

  while (true) {
    if (count == 20000) break;
    n = read(fd, buffer, 3);
    printf("%hd\n", *(short*)&buffer);
    ++count;
  }

  close(fd);
  return 0;
}
