package shape;

public class Rectangle {
    protected double width_;
    protected double height_;

    public Rectangle(double width, double height) { width_ = width; height_ = height; }

    public String debugDescription() {
        String description = "";

        description += "{";
        description += "\"width_:\"";
        description += width_;
        description += ",";
        description += "\"height_:\"";
        description += height_;
        description += "}";

        return description;
    }
}
