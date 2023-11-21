package lmi;

public class Point {
    public double x;
    public double y;

    Point() {}
    Point(double x, double y) { this.x = x; this.y = y; }

    public void callOverrideThis() {
        this.overrideThis();
    }

    final public void overrideThis() {
        System.out.println("[Point::overrideThis()]");
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
