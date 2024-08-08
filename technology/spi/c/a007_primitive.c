// spi primitive
#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>

const char* spiPath = "/dev/spidev0.0";
const int readCount = 20000;
const int spiSpeed = 16000000;

int _fd;
uint8_t _tx[2];
uint8_t _rx[2];

void initSPI() {
  _fd = open(spiPath, O_RDWR);

  uint8_t mode = SPI_MODE_0;
  assert(ioctl(_fd, SPI_IOC_WR_MODE, &mode) != -1);

  // Set SPI speed
  assert(ioctl(_fd, SPI_IOC_WR_MAX_SPEED_HZ, &spiSpeed) != -1);

  // Set SPI bits
  uint8_t wordBits = 8;
  assert(ioctl(_fd, SPI_IOC_WR_BITS_PER_WORD, &wordBits) != -1);
}

int readAD(int fd) {
  struct spi_ioc_transfer tr = {
    .tx_buf = (unsigned long)_tx,
    .rx_buf = (unsigned long)_rx,
    .len = 2,
    .speed_hz = spiSpeed,
    .delay_usecs = 0,
    .bits_per_word = 8,
  };

  assert(ioctl(_fd, SPI_IOC_MESSAGE(1), &tr) >= 1);

  int result = ((_rx[0] & 0x0F) << 8) | _rx[1];
  return result;
}

int main() {
  initSPI();

  while (1) {
    for (int i = 0; i < readCount; ++i) {
      readAD(_fd);
    }
  }

  close(_fd);

  return 0;
}
