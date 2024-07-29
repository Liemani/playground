#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <unistd.h>
#include <cstring>

#define SPI_PATH "/dev/spidev0.0"  // SPI 디바이스 파일 경로 (필요에 따라 수정)

int main() {
    int spi_fd = open(SPI_PATH, O_RDONLY);
    if (spi_fd < 0) {
        std::cerr << "Failed to open SPI device" << std::endl;
        return -1;
    }

    uint8_t mode = SPI_MODE_0;
    uint8_t bits = 8;
    uint32_t speed = 500000;  // 20 kHz
    uint16_t delay = 0;

    // SPI 모드 설정
    if (ioctl(spi_fd, SPI_IOC_RD_MODE, &mode) < 0) {
        std::cerr << "Failed to set SPI mode" << std::endl;
        close(spi_fd);
        return -1;
    }

    // 비트 수 설정
    if (ioctl(spi_fd, SPI_IOC_RD_BITS_PER_WORD, &bits) < 0) {
        std::cerr << "Failed to set bits per word" << std::endl;
        close(spi_fd);
        return -1;
    }

    // 속도 설정
    if (ioctl(spi_fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed) < 0) {
        std::cerr << "Failed to set max speed" << std::endl;
        close(spi_fd);
        return -1;
    }

    // 송수신 데이터 설정
    uint8_t tx[] = {0x00, 0x00, 0x00};  // 송신할 데이터
    uint8_t rx[sizeof(tx)] = {0, };

    struct spi_ioc_transfer spi_transfer = {};
    spi_transfer.tx_buf = reinterpret_cast<__u64>(tx);
    spi_transfer.rx_buf = reinterpret_cast<__u64>(rx);
    spi_transfer.len = sizeof(tx);
    spi_transfer.speed_hz = speed;
    spi_transfer.bits_per_word = bits;
    spi_transfer.delay_usecs = delay;

    while (true) {
      // SPI 송수신
      if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spi_transfer) < 0) {
          std::cerr << "Failed to transfer SPI message" << std::endl;
          close(spi_fd);
          return -1;
      }

      // 수신 데이터 출력
      int adc_value = (rx[0] << 8 | rx[1]) & 0x0FFF;  // 12비트 데이터 추출
      printf("[value : %02x %02x %02x = %d]\n", rx[0], rx[1], rx[2], adc_value);

//      std::cout << "Received data: ";
//      for (size_t i = 0; i < sizeof(rx); i++) {
//          std::cout << std::hex << static_cast<int>(rx[i]) << " ";
//      }
//      std::cout << std::dec << std::endl;
      usleep(50000);
    }

    close(spi_fd);
    return 0;
}
