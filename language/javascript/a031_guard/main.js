function testNumber(myNumber) {
  if (myNumber > 42) {}
  else {
    console.log("guarded");
    return;
  }

  console.log("pass");
}

testNumber(40);
testNumber(50);
