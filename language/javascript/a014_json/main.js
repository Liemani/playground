// customObject
const customObject = {
  "variable1" : "Hello, world!",
  "variable2" : 42,
};

console.log(customObject);
console.log(customObject.variable1);
console.log(customObject.variable2);

// customObject2
const customObject2 = {
  variable1 : "Hello, world!",
  variable2 : 42,
};

console.log(customObject2);
console.log(customObject2.variable1);
console.log(customObject2.variable2);

// several test
customObject2.test = "hi";
console.log(customObject2.test);
//customObject = {};  // TypeError: Assignment to constant variable.    
