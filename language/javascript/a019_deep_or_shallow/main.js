let first = { value1 : "1", value2 : "2" };
let second = first;

second.value1 = "3";

console.log(first);
console.log(second);

let third = { value1 : first.value1, value2 : first.value2 };
third.value2 = 4;

console.log(first);
console.log(second);
console.log(third);
