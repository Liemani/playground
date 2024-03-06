// ES6 이전에는 var이 있었다.
// var는 재선언 시 update 된다.
console.log("[var]");

var first = "first";

console.log(first);

if (true) {
  var first = "second";
}
console.log(first);

// let은 재선언 시 update 되지 않는다.
console.log("[let]");

let second = "first";

console.log(second);

if (true) {
  let second = "second";
}
console.log(second);

// const 는 update 되지 않는다.
console.log("[const]");

const third = "first";

console.log(third);

if (true) {
  const third = "second";
}
console.log(third);
