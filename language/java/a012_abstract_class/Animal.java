package animal;

public abstract class Animal {
    protected String species_;

    public Animal(String species) { species_ = species; }

    public abstract void makeSound();

    public String debugDescription() {
        String description = "";

        description += "{";
        description += "\"species\":";
        description += species_;
        description += "}";

        return description;
    }
}
