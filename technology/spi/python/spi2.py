import spidev
import time
import Jetson.GPIO as GPIO

# SPI 초기화
spi = spidev.SpiDev()
spi.open(0, 0)  # bus=0, device=0
spi.max_speed_hz = 1000000

control_byte = 0b11000000 | (0 << 6)

def read_adc():
    response = spi.xfer2([control_byte, 0])
    # response는 12비트 값을 포함하고 있음 (2바이트 중 12비트)
    adc_value = ((response[0] & 0x0F) << 8) | response[1]
    return adc_value

start_time = time.time()
count = 0;

try:
    while True:
        if count > 20000 :
            break;

        adc_value_ch0 = read_adc()

        if count % 1000 == 0 :
          print(f"ADC Channel 0: {adc_value_ch0}")

        count += 1;
except KeyboardInterrupt:
    pass
finally:
    spi.close()
    GPIO.cleanup()

elapsed_time = time.time() - start_time
print("Elapsed time :", elapsed_time, "seconds");
