# README.md

## Abstract

serial을 통해 읽은 값을 5초마다 특정 주소의 서버로 전송하는 프로그램. 비정기적으로 들어오는 serial 데이터로부터 커스텀 프로토콜인 dht_protocol에 따라 온습도 값을 얻고, 이를 nCube-Thyme의 tas 프로그램으로 전송한다.

## Environment

## Usage

0. 선행 준비
  - 모비우스 플랫폼을 준비한다
  - 아두이노에 코드 업로드 및 실행 및 시리얼 연결
  - dht_protocol.js 붙여넣기
1. list_ports.js를 실행하여 출력되는 아두이노의 포트 경로로 dht_serial_client.js:7을 수정한다.
  - node list_ports
2. 실행
  - node dht_serial_client
3. 결과 확인
  - tas
