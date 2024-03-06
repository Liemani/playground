const net = require("net");

const host = "192.168.0.42";
const port = 3231;

const socket = new net.Socket();

let state = "connecting";

setupSocket(socket);
function setupSocket(socket) {
  socket.on("error", () => console.log("error"));
}

socket.connect(port, host, () => state = "connected");

setInterval(loop, 1000);

function loop() {
  switch (state) {
    case "setup" :
      console.log(state);
      break;
    case "connected" :
      socket.write("Hello, world!");
      break;
    case "error" :
      break;
    case "disconnected" :
      break;
    default :
      console.log(state);
  }
}
