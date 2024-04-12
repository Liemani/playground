class MyClass {

  constructor() {
    this.data = { first : 1, second : 2 };
    return 1;
  }

  myFunction() {
    const data = this.data;
    data.first = 42;
  }

  log() {
    console.log(this.data);
  }

}

// main
console.log("[first test]");

const myClass = new MyClass();
myClass.log();
myClass.myFunction();
myClass.log();
console.log();

console.log("[second test]");

const myClass2 = { data : { first : 1, second : 2 } };
const data = myClass2.data;
data.first = 42;
console.log(myClass2);
console.log();

console.log("[second test]");
const dataObject = { first : 1, second : 2 };
const data2 = dataObject;
data2.first = 42;
console.log(dataObject);
console.log();

console.log("[second test]");
data2.third = 3;
console.log(dataObject);
console.log();
