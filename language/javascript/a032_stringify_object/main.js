const myObject = { "first" : 1, "second" : 2};
const stringifiedObject = JSON.stringify(myObject);
console.log(stringifiedObject);
console.log("test : " + JSON.stringify(myObject) + "\n");


const upload_arr = ["hi"];
const nValue = { temperature : 20, humidity : 25 };

var cin = {ctname: upload_arr[0].ctname, con: nValue.toString()};
console.log('SEND : ' + JSON.stringify(cin) + ' ---->');
