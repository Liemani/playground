#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <unistd.h>
#include <cstdint>
#include <cstring>

class SPI {
public:
    SPI(const char* device, uint32_t speed) : speed(speed) {
        if ((fd = open(device, O_RDWR)) < 0) {
            std::cerr << "Failed to open SPI device" << std::endl;
            exit(1);
        }

        // Set SPI mode
        uint8_t mode = SPI_MODE_0;
        if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0) {
            std::cerr << "Failed to set SPI mode" << std::endl;
            exit(1);
        }

        // Set SPI speed
        if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
            std::cerr << "Failed to set SPI speed" << std::endl;
            exit(1);
        }
    }

    ~SPI() {
        close(fd);
    }

    uint16_t readADC(uint8_t channel) {
        uint8_t tx[] = { static_cast<uint8_t>(0xC0 | (channel << 6)), 0x00 };
        uint8_t rx[2] = {0, 0};
        
        struct spi_ioc_transfer tr;
        std::memset(&tr, 0, sizeof(tr));
        tr.tx_buf = reinterpret_cast<unsigned long>(tx);
        tr.rx_buf = reinterpret_cast<unsigned long>(rx);
        tr.len = 2;
        tr.delay_usecs = 0;
        tr.speed_hz = speed;
        tr.bits_per_word = 8;

        if (ioctl(fd, SPI_IOC_MESSAGE(1), &tr) < 0) {
            std::cerr << "Failed to send SPI message" << std::endl;
            exit(1);
        }

        return ((rx[0] & 0x0F) << 8) | rx[1];
    }

private:
    int fd;
    uint32_t speed;
};

int main() {
    const char* device = "/dev/spidev0.0";
    uint32_t speed = 50000;
    SPI spi(device, speed);

    while (true) {
        uint16_t adcValueCh0 = spi.readADC(0);
        uint16_t adcValueCh1 = spi.readADC(1);

        std::cout << "ADC Channel 0: " << adcValueCh0 << std::endl;
        std::cout << "ADC Channel 1: " << adcValueCh1 << std::endl;

        usleep(1000000); // 1초 대기
    }

    return 0;
}
