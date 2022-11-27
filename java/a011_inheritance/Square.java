package shape;

public class Square extends Rectangle {
    public Square(double side) { super(side, side); }

    public String debugDescription() {
        String description = "";

        description += "{";
        description += "\"side_:\"";
        description += width_;
        description += "}";

        return description;
    }
}
