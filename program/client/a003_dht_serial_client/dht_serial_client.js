// include modules
const SerialPort = require("serialport").SerialPort;
const net = require("net");
const dhtProtocol = require("./dht_protocol");

// constant
const comPortPath = "/dev/ttyACM0";
const baudRate = 9600;

const remoteServerIpAddress = "192.168.0.46";
const remoteServerPortNumber = 3233;

// loop interval
const dhtLoopInterval = 1000;
const remoteServerSocketLoopInterval = 5000;



// class implementation
class IoTDhtDevice {

  constructor(comPortPath) {
    this.data = {
      "temperature" : 0.0,
      "humidity" : 0.0,
    };

    this.isReady = false;

    const serialPort = new SerialPort({
      path : comPortPath,
      baudRate : baudRate,
    });

    this.buffer = "";

    const iotDhtDevice = this;

    serialPort.on("data", (data) => {
      iotDhtDevice.buffer += data.toString();

      if (!dhtProtocol.isReadAMessage(iotDhtDevice.buffer)) {
        return;
      }

      const message = dhtProtocol.getAMessageFrom(iotDhtDevice.buffer);
      iotDhtDevice.buffer = dhtProtocol.removeAMessageFrom(iotDhtDevice.buffer);

      if (!dhtProtocol.isValid(message)) {
        return;
      }

      iotDhtDevice.data = dhtProtocol.objectFrom(message);

      if (!iotDhtDevice.isReady) {
        iotDhtDevice.isReady = true;
        console.log("iotDhtDevice is ready");
      }
    });

    this.serialPort = serialPort;
  }

}



class Client {

  constructor(remoteServerIpAddress, remoteServerPortNumber) {
    this.remoteServerIpAddress = remoteServerIpAddress;
    this.remoteServerPortNumber = remoteServerPortNumber;
    this.socket = new net.Socket();

    this.setupSocketEvent();


    this.state = Client.state.SETUP;
  }

  setupSocketEvent() {
    const client = this;
    const socket = client.socket;

    socket.on("close", function(hadError) {
        client.socket.destroy();
        client.state = Client.state.SETUP;
      }
    );

    socket.on("connect", function() {
        client.state = Client.state.READY;
      }
    );

    socket.on("error", function(error) {
        console.log(error);
        this.state = Client.state.FAILED;
      }
    );
  }



  connectToRemoteServer() {
    this.state = Client.state.PREPARING;
    this.socket.connect(
        this.remoteServerPortNumber, this.remoteServerIpAddress);
  }

  // format : "data object as json" + '\n'
  writeDataToRemoteServer(data) {
    const stringData = JSON.stringify(data);
    const dataToWrite = stringData + '\n';
    this.socket.write(dataToWrite);
    console.log("message [" + dataToWrite + "] is written.");
  }

}

Client.state = {
  "SETUP" : "setup",
  "PREPARING" : "preparing",
  "READY" : "ready",
  "FAILED" : "failed",
};



// main
const iotDhtDevice = new IoTDhtDevice(comPortPath);

const client = new Client(remoteServerIpAddress, remoteServerPortNumber);
setInterval(remoteServerSocketLoop, remoteServerSocketLoopInterval);

function remoteServerSocketLoop() {
  switch (client.state) {
    case Client.state.SETUP :
      client.connectToRemoteServer();
      break;
    case Client.state.PREPARING :
      break;
    case Client.state.READY :
      if (!iotDhtDevice.isReady) {
        console.log("iotDhtDevice is not ready");
        break;
      }

      client.writeDataToRemoteServer(iotDhtDevice.data)
      break;
    case Client.state.FAILED :
      break;
    default :
      console.log("[unknown state] " + client.state);
  }
}
