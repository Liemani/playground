package main;

import animal.Animal;
import animal.Cat;
import hasColor.HasColor.Color;

public class Main {
    public static void main(String[] args) {
        Animal firstCat = new Cat(Color.BLUE);
        Cat cat = new Cat(Color.RED);

        cat.makeSound();

        if (cat.color() == Color.RED)
            System.out.println("This cat has red color.");

        System.out.println(cat.color());

        for (Color color: Color.values()) {
            System.out.println(color);
        }
    }
}
