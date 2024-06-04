/*
회로도 : https://www.npmjs.com/package/node-dht-sensor
pin
vcc : 3.3v, 5v
data :
gnd :

가능한 한 3.3v 먼저 사용할 것
정확한 해당 제품의 specification 문서가 있다면 좋다
web에 5v 라고 많이 소개되지만 내가 가진 DHT11의 경우 3.3v여야 정상 작동했다
그런데 5v에 연결해도 정상 작동했다
이전에 5v 에서 정상 작동하지 않았던 경우는 무슨 에러였던 거지?
*/
const sensor = require("node-dht-sensor");

const sensorType = 11;
const dhtDataPinNumber = 2;
 
sensor.read(sensorType, dhtDataPinNumber, function(err, temperature, humidity) {
  if (!err) {
    console.log(`temp: ${temperature}°C, humidity: ${humidity}%`);
  }
  else {
    console.log(err);
  }
});
