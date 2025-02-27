let test1=null
let test2
let test3="null";

console.log(test1);
console.log(typeof test1);
console.log(test2);
console.log(typeof test2);
console.log(test3);
console.log(typeof test3);

console.log(typeof test2 === 'undefined');
console.log(test2 === undefined);
console.log(typeof (typeof test2));
console.log(typeof (typeof test2 == 'undefined'));
console.log(typeof false);

let test4="name";
test4=undefined
console.log(test4 === undefined);

let test_array = ["a", "b"];

for (const element of test_array) {
  console.log(element);
}

let test5 = {};
test5.member = "hi";
console.log(test5.member);

console.log(new Date());
let number = 2;
console.log(typeof number);
let stringFromNumber = number.toString();
console.log(stringFromNumber);
console.log(typeof stringFromNumber);

let data = {"a" : "b", "c" : "d"};
let ep4 = {};

for (const key in data) {
  const value = data[key];
  ep4[key] = value;
}

console.log(ep4.a);
console.log(ep4.c);
