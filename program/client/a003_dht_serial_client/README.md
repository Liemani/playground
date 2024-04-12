# README.md

## Abstract

serial을 통해 읽은 값을 5초마다 특정 주소의 서버로 전송하는 프로그램. 비정기적으로 들어오는 serial 데이터로부터 커스텀 프로토콜인 dht_protocol에 따라 온습도 값을 얻고, 이를 nCube-Thyme의 tas 프로그램으로 전송한다.

## Environment

## Usage

0. 선행 준비
  - 모비우스 플랫폼을 준비한다
  - 아두이노에 코드 업로드
1. list_ports.js를 실행하여 아두이노의 포트 경로를 출력한다.
  - node list_ports
