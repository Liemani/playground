package main;

import java.io.InputStream;

class Main {
    static int intField = 0;

    public static void main(String args[]) {
        Class mainClass = Main.class;
        System.out.println("The name of this class is " + mainClass.toString() + ".");

        String nameOfAttribute = "no";
        InputStream attribute = mainClass.getResourceAsStream(nameOfAttribute);
        System.out.println(nameOfAttribute + ": " + attribute);

        nameOfAttribute = "intField";
        attribute = mainClass.getResourceAsStream(nameOfAttribute);
        System.out.println(nameOfAttribute + ": " + attribute);

        nameOfAttribute = "main";
        attribute = mainClass.getResourceAsStream(nameOfAttribute);
        System.out.println(nameOfAttribute + ": " + attribute);
    }
}
