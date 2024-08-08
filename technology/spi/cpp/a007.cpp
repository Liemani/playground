#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define PATH "/dev/spidev0.0"
#define BUFFER_SIZE 16

int main() {
  int result;

  uint32_t mode;
  uint8_t bits = 8;
  uint32_t speed = 500000;

  int fd = open(PATH, O_RDWR);
  if (fd == -1) {
    perror("open(PATH, O_RDONLY)");
    exit(-1);
  }

  result = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
  if (result == -1) {
    perror("ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits)");
    exit(-1);
  }

  result = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
  if (result == -1) {
    perror("ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed)");
    exit(-1);
  }

  int index = 0;
  char buffer[BUFFER_SIZE];
  while(1) {
    result = read(fd, &buffer, BUFFER_SIZE);

    if (result == -1) {
      perror("read() ");
      break;
    }

    if (index == 32) {
      break;
    }

    printf("[%2d %d] ", index, result);
    for (int i = 0; i < BUFFER_SIZE; ++i) {
      printf("%02x ", buffer[i]);
    }
    printf("\n");

    ++index;
  }

  close(fd);

  return 0;
}
