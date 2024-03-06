function sleep(ms) {
  new Promise(resolve => setTimeout(resolve, ms));
}

function sleep2(ms) {
  setTimeout(() => log(5), ms);
}

function sleep3(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function log(message) {
  console.log("[" + Date.now() + "] " + message);
}

async function main() {
  log(1);
  sleep(1000);
  log();
  log(2);
//  sleep2(1000);
  log(3);
  log(4);
  await sleep3(1000);
  log(6);
}

let index = 42;
setInterval(function() {
    log(index);
    index += 1;
    }, 1000);


log("start");
main();
log("end");
