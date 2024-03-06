const array1 = [];
array1[0] = "Hello";
array1[1] = "World";
console.log(array1);
console.log(Object.keys(array1));



const array2 = [];
array2["0"] = "Hello";
array2["1"] = "World";
console.log(array2);
console.log(Object.keys(array2));

console.log(array1 == array2);



const array3 = [];
array3["a"] = "Hello";
array3["b"] = "World";
console.log(array3);
array3.a = "Nice";
console.log(array3);



const object1 = {};
object1.a = "Hello";
object1.b = "World";
console.log(object1);

object1["a"] = "Nice";
console.log(object1);



for (const variable in object1) {
  console.log(variable);
}
