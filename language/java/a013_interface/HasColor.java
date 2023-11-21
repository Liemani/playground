package hasColor;

public interface HasColor {
    static enum Color {
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        VIOLET,
    }

    Color color();
}
