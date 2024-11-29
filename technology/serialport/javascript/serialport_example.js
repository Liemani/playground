/* usage :
 *   select function which you prefer for the 'data' notification
 */
// package
const SerialPort = require("serialport").SerialPort;

// constant
const comPortPath = "/dev/tty.usbmodem1101";
const baudrate = 9600;

// main()
const serialPort = new SerialPort({
  path : comPortPath,
  baudRate : baudrate 
});

serialPort.on("data", showRawData);

function showRawData(data) {
  console.log("[received data]", typeof data, data);
  console.log(data.toString('utf-8'));
}

function showString(data) {
  const string = data.toString();
  console.log(string);
}
