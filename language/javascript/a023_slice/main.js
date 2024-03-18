const str = "This is a string\nwith a newline.";

const withoutPrefix = str.slice(str.indexOf('\n') + 1);

console.log(withoutPrefix);  // Output: "with a newline."
