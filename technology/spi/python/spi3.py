import spidev
import struct
import time

# 상수 정의
sample_queue_size = 1000
device = "/dev/spidev0.0"
sampling_rate = 2000000  # 2MHz (SPI 최대 속도)

# SPI 설정
spi = spidev.SpiDev()
spi.open(0, 0)  # SPI 장치 열기
spi.max_speed_hz = sampling_rate

# 출력 파일 경로
output_path = "output.out"

# 데이터 수집
samples = []

start_time = time.time()

count = 0
for _ in range(sample_queue_size):
    # SPI 통신으로 데이터 읽기
    response = spi.xfer2([0x00, 0x00])  # SPI 통신으로 데이터 읽기 (실제 명령어에 맞게 수정 필요)
    value = ((response[0] & 0x0F) << 8) | response[1]  # 12비트 데이터로 변환
    samples.append(value)
    print(f"count : {count}, value : {value}");
    count += 1;

end_time = time.time()

# 시간 측정 및 출력
elapsed_time = end_time - start_time
print(f"time elapsed: {elapsed_time:.6f} seconds")

# 파일에 데이터 저장
with open(output_path, "wb") as f:
    for value in samples:
        f.write(struct.pack('<H', value))  # 16비트 값을 바이너리 형식으로 저장 (하위 12비트 사용)

# SPI 닫기
spi.close()
