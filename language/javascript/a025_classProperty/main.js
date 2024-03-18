class myClass {
  static myVariable = "test";

  static log() {
    console.log(this.myVariable);
  }
}

myClass.log()
