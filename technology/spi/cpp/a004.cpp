#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <unistd.h>
#include <cstring>

#define SPI_PATH "/dev/spidev0.0"  // SPI 디바이스 파일 경로

class PmodAD1 {

public:
  PmodAD1(const char* device, uint8_t mode, uint32_t speed) {
    if ((spi_fd = open(device, O_RDWR)) < 0) {
      std::cerr << "Failed to open SPI device" << std::endl;
      exit(1);
    }

    if (ioctl(spi_fd, SPI_IOC_RD_MODE, &mode) < 0) {
      std::cerr << "Failed to set SPI mode" << std::endl;
      close(spi_fd);
      exit(1);
    }

    if (ioctl(spi_fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed) < 0) {
      std::cerr << "Failed to set SPI speed" << std::endl;
      close(spi_fd);
      exit(1);
    }

    uint8_t bits = 8;
    if (ioctl(spi_fd, SPI_IOC_RD_BITS_PER_WORD, &bits) < 0) {
      std::cerr << "Failed to set SPI bits per word" << std::endl;
      close(spi_fd);
      exit(1);
    }
  }

  ~PmodAD1() {
    close(spi_fd);
  }

  int read_channel() {
    uint8_t tx[] = {0x00, 0x00};
    uint8_t rx[sizeof(tx)] = {0, 0};

    struct spi_ioc_transfer spi_transfer = {};
    spi_transfer.tx_buf = reinterpret_cast<__u64>(tx);
    spi_transfer.rx_buf = reinterpret_cast<__u64>(rx);
    spi_transfer.len = sizeof(tx);
    spi_transfer.speed_hz = speed;
    spi_transfer.bits_per_word = 8;
    spi_transfer.delay_usecs = 0;

    if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spi_transfer) < 0) {
      std::cerr << "Failed to transfer SPI message" << std::endl;
      return -1;
    }

    printf("%#02x%02x", rx[0], rx[1]);
    int adc_value = (rx[0] << 8 | rx[1]) & 0x0FFF;  // 12비트 데이터 추출

    return adc_value;
  }

private:
  int spi_fd;
  uint32_t speed;

};

int main() {
  const char* device = SPI_PATH;
  uint8_t mode = SPI_MODE_0;
  uint32_t speed = 500000;  // 500 kHz

  PmodAD1 adc(device, mode, speed);

  while (true) {
    int adc_value = adc.read_channel();
    if (adc_value >= 0) {
      printf(" = %4d\n", adc_value);
    } else {
      std::cerr << "Error reading ADC value" << std::endl;
    }
    usleep(50000);  // 20kHz 샘플링 주기 (50ms)
  }

  return 0;
}
