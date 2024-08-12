#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <iostream>
#include <unistd.h>

#define CHANNEL 0  // SPI channel (0 or 1)
#define SPEED 500000  // SPI speed in Hz

// Function to read data from PMOD AD1
int read_adc(int adc_channel) {
    uint8_t buffer[3];
    buffer[0] = 0x06 | ((adc_channel & 0x04) >> 2);  // Start bit, single-ended mode
    buffer[1] = (adc_channel & 0x03) << 6;  // Channel selection
    buffer[2] = 0x00;  // Dummy byte

    wiringPiSPIDataRW(CHANNEL, buffer, 3); 

    int result = ((buffer[1] & 0x0F) << 8) | buffer[2];
    return result;
}

int main() {
    // Initialize wiringPi library
    if (wiringPiSetup() == -1) {
        std::cerr << "wiringPi setup failed!" << std::endl;
        return 1;
    }   

    // Initialize SPI
    if (wiringPiSPISetup(CHANNEL, SPEED) == -1) {
        std::cerr << "SPI setup failed!" << std::endl;
        return 1;
    }   

    while (true) {
        // Read data from both channels
        int adc_value_ch0 = read_adc(0);
        int adc_value_ch1 = read_adc(1);

        // Print the ADC values
        std::cout << "Channel 0: " << adc_value_ch0 << " | Channel 1: " << adc_value_ch1 << std::endl;

        usleep(1000000);  // Delay for 1 second
    }   

    return 0;
}
