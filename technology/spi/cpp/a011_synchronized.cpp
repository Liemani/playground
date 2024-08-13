#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <sys/time.h>

#include "Timer.hpp"

const char* spiPath = "/dev/spidev0.0";
const int readCount = 20000;
const int spiSpeed = 50000000;
const int spiBufferSize = 2;

int _fd;
uint8_t _tx[spiBufferSize];
uint8_t _rx[spiBufferSize];

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
    struct spi_ioc_transfer tr = {};
    tr.tx_buf = (unsigned long)_tx;
    tr.rx_buf = (unsigned long)_rx;
    tr.len = spiBufferSize;
    tr.speed_hz = spiSpeed;
    tr.delay_usecs = 0;
    tr.bits_per_word = 8;

    assert(ioctl(_fd, SPI_IOC_MESSAGE(1), &tr) >= 1);

    int result = ((_rx[0] & 0x0F) << 8) | _rx[1];
    return result;
}

int main() {
  initSPI();
  Timer timer = Timer(50);

  timer.set();
  for (int i = 0; i < readCount; ++i) {
    readAD(_fd);
    int result = ((_rx[0] & 0x0F) << 8) | _rx[1];
//    printf("%d\n", result);

    struct timeval currentTime;
    assert(gettimeofday(&currentTime, NULL) != -1);
    if (currentTime < timer.targetTime()) {
      timer.busySleep();
      timer.update();
    } else {
      timer.set();
    }
  }

  close(_fd);

  return 0;
}
