const yesJSON = "{\"hi\": \"there\"}";
const yes = JSON.parse(yesJSON);
console.log(yes);

const noJSON = "{hi: there}}";
const no = JSON.parse(noJSON);
console.log(no);

console.log("[terminating]");
