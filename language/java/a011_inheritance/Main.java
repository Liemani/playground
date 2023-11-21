package lmi;

import shape.*;

public class Main {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(42, 24);
        System.out.println(rectangle.debugDescription());

        Square square = new Square(42);
        System.out.println(square.debugDescription());

        rectangle = square;
        System.out.println(rectangle.debugDescription());
    }
}
