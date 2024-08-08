#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <cstring>
#include <chrono>

const char *SPI_DEVICE = "/dev/spidev0.0";
//const uint32_t SPI_SPEED = 5000000; // 5 MHz
const uint32_t SPI_SPEED = 65000000; // 5 MHz
const uint8_t SPI_MODE = SPI_MODE_0;
const uint8_t BITS_PER_WORD = 8;
const size_t NUM_READS = 2000;

int main() {
    int spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        std::cerr << "Failed to open SPI device" << std::endl;
        return -1;
    }

    // Set SPI mode
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &SPI_MODE) < 0) {
        std::cerr << "Failed to set SPI mode" << std::endl;
        close(spi_fd);
        return -1;
    }

    // Set bits per word
    if (ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &BITS_PER_WORD) < 0) {
        std::cerr << "Failed to set bits per word" << std::endl;
        close(spi_fd);
        return -1;
    }

    // Set SPI speed
    if (ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &SPI_SPEED) < 0) {
        std::cerr << "Failed to set SPI speed" << std::endl;
        close(spi_fd);
        return -1;
    }

    uint8_t tx_buffer[2] = {0x00, 0x00}; // 16-bit dummy data for clocking in data
    uint8_t rx_buffer[2];
    struct spi_ioc_transfer spi_transfer;
    memset(&spi_transfer, 0, sizeof(spi_transfer));
    spi_transfer.tx_buf = reinterpret_cast<unsigned long>(tx_buffer);
    spi_transfer.rx_buf = reinterpret_cast<unsigned long>(rx_buffer);
    spi_transfer.len = 2; // 2 bytes for 16-bit read
    spi_transfer.speed_hz = SPI_SPEED;
    spi_transfer.bits_per_word = BITS_PER_WORD;

    // Start timing
    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < NUM_READS; ++i) {
        if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spi_transfer) < 0) {
            std::cerr << "Failed to transfer SPI message" << std::endl;
            close(spi_fd);
            return -1;
        }

        uint16_t value = (rx_buffer[0] << 8) | rx_buffer[1];
//        std::cout << "Read value: " << value << std::endl;
    }

    // End timing
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    std::cout << "Time taken to read " << NUM_READS << " samples: " << elapsed_time.count() << " seconds" << std::endl;

    close(spi_fd);
    return 0;
}
