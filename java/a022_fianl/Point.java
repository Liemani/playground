package lmi;

public class Point {
    public double x;
    public double y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void updateAdd(Point rhs) {
        this.x += rhs.x;
        this.y += rhs.y;
    }

    String debugDescription() {
        StringBuilder description = new StringBuilder();
        description.append("(");
        description.append(this.x);
        description.append(", ");
        description.append(this.y);
        description.append(")");

        return description.toString();
    }
}
