import spidev
import time
import Jetson.GPIO as GPIO

# SPI 초기화
spi = spidev.SpiDev()
spi.open(0, 0)  # bus=0, device=0
spi.max_speed_hz = 50000

def read_adc(channel):
    assert 0 <= channel <= 1, "ADC channel must be 0 or 1"
    # MCP3002의 경우 control byte를 전송해야 함
    control_byte = 0b11000000 | (channel << 6)
    response = spi.xfer2([control_byte, 0])
    # response는 10비트 값을 포함하고 있음 (2바이트 중 10비트)
    adc_value = ((response[0] & 0x0F) << 8) | response[1]
    return adc_value

try:
    while True:
        adc_value_ch0 = read_adc(0)
        adc_value_ch1 = read_adc(1)
        print(f"ADC Channel 0: {adc_value_ch0}")
        print(f"ADC Channel 1: {adc_value_ch1}")
        time.sleep(1)
except KeyboardInterrupt:
    pass
finally:
    spi.close()
    GPIO.cleanup()
