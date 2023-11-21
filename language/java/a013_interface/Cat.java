package animal;

import hasColor.*;

public class Cat implements Animal, HasColor {
    HasColor.Color color_;

    public Cat(HasColor.Color color) { color_ = color; }

    public void makeSound() {
        System.out.println("Meow!");
        System.out.println(species_);
//          species_ = "hi";
//  Cat.java:7: error: cannot assign a value to final variable species_
    }

    public HasColor.Color color() {
        return color_;
    }
}
