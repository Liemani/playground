import Jetson.GPIO as GPIO
import spidev
import time

SPI_BUS = 0
SPI_DEVICE = 0
SPI_SPEED_HZ = 65000000  # 5 MHz
NUM_READS = 2000

# Initialize SPI
spi = spidev.SpiDev()
spi.open(SPI_BUS, SPI_DEVICE)
spi.max_speed_hz = SPI_SPEED_HZ

# Perform reads
start_time = time.time()
for _ in range(NUM_READS):
    response = spi.xfer2([0x00, 0x00])  # Send dummy bytes
    value = (response[0] << 8) | response[1]
    print(f"Read value: {value}")

end_time = time.time()
elapsed_time = end_time - start_time
print(f"Time taken to read {NUM_READS} samples: {elapsed_time} seconds")

# Clean up
spi.close()
