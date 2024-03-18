const myInstance = {};

console.log("myInstance.a == undefined :", myInstance.a == undefined);
console.log("myInstance.a == null :", myInstance.a == null);
console.log("myInstance.a === undefined :", myInstance.a === undefined);
console.log("myInstance.a === null :", myInstance.a === null);
console.log("myInstance :", myInstance);

myInstance.b = null;
console.log("myInstance.b == undefined :", myInstance.b == undefined);
console.log("myInstance.b == null :", myInstance.b == null);
console.log("myInstance.b === undefined :", myInstance.b === undefined);
console.log("myInstance.b === null :", myInstance.b === null);
console.log("myInstance :", myInstance);
