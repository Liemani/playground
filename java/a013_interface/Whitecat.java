package animal;

import whiteThing.*;

public class WhiteCat implements Animal, WhiteThing {
    public void makeSound() {
        System.out.println("Meow!");
        System.out.println(species_);
//          species_ = "hi";
//  Cat.java:7: error: cannot assign a value to final variable species_
    }

    HasColor.Color color() {
        return Color.RED;
    }
}
