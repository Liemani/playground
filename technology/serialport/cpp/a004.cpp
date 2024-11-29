#include <cstdio>
#include <cstdlib>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

const char* path = "/dev/tty.usbmodem1101";
int baudRate = 115200;

void pabortif(bool expression) {
  if (expression) {
    perror("");
    abort();
  }
}

int init(const char* path, int baudRate) {
  int sfd = open(path, (O_RDWR | O_NOCTTY | O_NONBLOCK));
  pabortif(sfd == -1);

  struct termios options;
  tcgetattr(sfd, &options);
  cfsetispeed(&options, baudRate);
  cfsetospeed(&options, baudRate);

  options.c_iflag &= ~(INLCR | ICRNL);
  options.c_iflag |= IGNPAR | IGNBRK;
  options.c_oflag &= ~(OPOST | ONLCR | OCRNL);
  options.c_cflag &= ~(PARENB | PARODD | CSTOPB | CSIZE | CRTSCTS);
  options.c_cflag |= CLOCAL | CREAD | CS8;
  options.c_lflag &= ~(ICANON | ISIG | ECHO);
  options.c_cc[VTIME] = 1;
  options.c_cc[VMIN]  = 0;

  pabortif(tcsetattr(sfd, TCSANOW, &options) == -1);

  return sfd;
}

int main() {
  int sfd = init(path, baudRate);

  char buffer[513];

  while (true) {
    ssize_t numBytesRead = read(sfd, buffer, 512);
    if (numBytesRead == -1) {
      perror("");
      close (sfd);
      return 0;
    }
    buffer[numBytesRead] = '\0';
    printf("%s", buffer);
  }

  return 0;
}
