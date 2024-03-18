const target = "{\"temperature\":value,\"humidity\":value}\n";

const pattern = "^{\"temperature\":[^,]*,\"humidity\":[^}]*}\n$";
const regexp = new RegExp(pattern);
const result = regexp.test(target);

console.log(result);
