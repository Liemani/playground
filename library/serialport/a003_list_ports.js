const SerialPort = require("serialport").SerialPort;

async function listPorts() {
  const portList = await SerialPort.list();
  console.log(portList);
}

listPorts();
