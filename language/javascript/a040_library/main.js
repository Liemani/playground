let a_module = require('./a_module');

a_module.hello1();
a_module.hello2();
console.log(new a_module.hello().message);

let a_function = require('./a_function'); 
a_function();
