class Rectangle {
  constructor(width, height) {
    this.width = width;
    this.height = height;
  }

  describe() {
    console.log("{ width : " + this.width + ", height : " + this.height + " }");
  }
}

const rectangle = new Rectangle(4, 2);
rectangle.describe()
