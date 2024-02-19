exports.hi = "hi";
exports.printHi = printHi;
exports.printHello = printHello;

function printHi() {
  console.log(this.hi);
}

function printHello() {
  console.log("hello");
}
