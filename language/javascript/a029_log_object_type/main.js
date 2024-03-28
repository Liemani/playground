console.log('[test1]');
const test1 = 'Hi';
console.log('type :', typeof test1);
console.log('value :', test1);

console.log('[test2]');
const test2 = {};
console.log('type :', typeof test2);
console.log('value :', test2);

console.log('[test3]');
const test3 = 42;
console.log('type :', typeof test3);
console.log('value :', test3);

console.log('[test4]');
const test4 = [];
console.log('type :', typeof test4);
console.log('value :', test4);

console.log('[test5]');
const test5 = typeof test4;
console.log('type :', typeof test5);
console.log('value :', test5);

console.log('[test6]');
const test6 = null;
console.log('type :', typeof test6);
console.log('value :', test6);

class Test { }
console.log('[test7]');
const test7 = Test;
console.log('type :', typeof test7);
console.log('value :', test7);

function testFunction() { }
console.log('[test8]');
const test8 = testFunction;
console.log('type :', typeof test8);
console.log('value :', test8);

console.log('[test9]');
const test9 = undefined;
console.log('type :', typeof test9);
console.log('value :', test9);

class Test2 {
  method() { }
}
console.log('[test10]');
const test10 = new Test2().method;
console.log('type :', typeof test10);
console.log('value :', test10);

console.log('[test11]');
const test11 = true;
console.log('type :', typeof test11);
console.log('value :', test11);

console.log('[test12]');
const test12 = { true : false };
console.log('type :', typeof test12);
console.log('value :', test12);

console.log('[test13]');
const test13 = [ true ];
console.log('type :', typeof test13);
console.log('value :', test13);

console.log('[test14]');
const test14 = () => {};
console.log('type :', typeof test14);
console.log('value :', test14);

console.log('[test15]');
const test15 = new Test2();
console.log('type :', typeof test15);
console.log('value :', test15);

console.log('[test16]');
const test16 = Symbol();
console.log('type :', typeof test16);
console.log('value :', test16);

console.log('[test17]');
const test17 = Buffer.alloc(10);
console.log('type :', typeof test17);
console.log('value :', test17);

console.log('[test18]');
test10.first = 1;
test10.second = 2;
const test18 = Object.keys(test10)[0]
console.log('type :', typeof test18);
console.log('value :', test18);

console.log('[test19]');
let test19 = 'test';
test19 = null;
console.log('type :', typeof test19);
console.log('value :', test19);
