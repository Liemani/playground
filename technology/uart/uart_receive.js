const SerialPort = require("serialport").SerialPort;

    const serialPort = new SerialPort({
      path : '/dev/serial0',
      baudRate : 9600,
    });


// 데이터 파싱을 위한 Readline 파서

// 시리얼포트에서 데이터 받기
serialPort.on('data', (data) => {
  console.log(data.toString());
});

serialPort.on('open', (err) => {
    console.log('UART connection opened:', err);
});

serialPort.on('error', (err) => {
    console.log('UART error', err);
});

// 프로세스가 종료될 때 시리얼 포트 닫기
process.on('SIGINT', () => {
    port.close(() => {
        console.log('UART connection closed');
        process.exit();
    });
});
