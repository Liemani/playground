console.log("This is a_module.js");

class hello
{
  constructor() {
    this.message = "Hello, world!";
  }
}

function hello1()
{
  console.log("Hello, world1!");
}

function hello2()
{
  console.log("Hello, world2!");
}

let a_module = {
  hello1 : hello1,
  hello2 : hello2,
  hello : hello,
};

module.exports = a_module;

// Export for use in other files
//if (typeof module !== 'undefined' && module.exports) {
//  module.exports = CONSTANTS;
//}
