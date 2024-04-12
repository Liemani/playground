// 5초마다 값을 특정 주소의 서버로 전송하는 프로그램

const dhtSensor = require("node-dht-sensor");
const net = require("net");

const dhtSensorType = 11;
const dhtDataPinNumber = 2;

const remoteServerIpAddress = "192.168.0.46";
const remoteServerPortNumber = 3233;

const dhtLoopInterval = 1000;
const remoteServerSocketLoopInterval = 5000;



class Dht {

  constructor(dhtDataPinNumber) {
    this.dhtDataPinNumber = dhtDataPinNumber;
    this.data = {
      "temperature" : 0.0,
      "humidity" : 0.0,
    };
  }



  read() {
    const data = this.data;

    dhtSensor.read(dhtSensorType, dhtDataPinNumber, function(error, temperature, humidity) {
        if (!error) {
          data.temperature = temperature;
          data.humidity = humidity;

          console.log(data);
        }
        else {
          console.log(error);
        }
      }
    );
  }

  // test use
  readFake() {
    const data = this.data;

    data.temperature += 1;
    data.humidity += 1;

    console.log(this.data);
  }

}



class Client {

  constructor(remoteServerIpAddress, remoteServerPortNumber) {
    this.remoteServerIpAddress = remoteServerIpAddress;
    this.remoteServerPortNumber = remoteServerPortNumber;
    this.socket = new net.Socket();

    this.setupSocketEvent();

    this.data = null;

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
  writeDataToRemoteServer() {
    const stringData = JSON.stringify(this.data);
    const dataToWrite = stringData + '\n';
    this.socket.write(dataToWrite);
  }

}

Client.state = {
  "SETUP" : "setup",
  "PREPARING" : "preparing",
  "READY" : "ready",
  "FAILED" : "failed",
};



// main
const dht = new Dht(dhtDataPinNumber);
setInterval(dhtLoop, dhtLoopInterval);

const client = new Client(remoteServerIpAddress, remoteServerPortNumber);
client.data = dht.data;
setInterval(remoteServerSocketLoop, remoteServerSocketLoopInterval);

function dhtLoop() {
  dht.read();
}

function remoteServerSocketLoop() {
  switch (client.state) {
    case Client.state.SETUP :
      client.connectToRemoteServer();
      break;
    case Client.state.PREPARING :
      break;
    case Client.state.READY :
      client.writeDataToRemoteServer()
      break;
    case Client.state.FAILED :
      break;
    default :
      console.log("[unknown state] " + client.state);
  }
}
