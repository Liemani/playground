package main;

import java.io.InputStream;
import java.lang.Character;

class Main {
    public static void main(String args[]) {
        String greeting = "Nice to meet you, Liemani!";

        char charArray[] = greeting.toCharArray();

        StringBuilder string = new StringBuilder();

        for (char currentChar: charArray) {
            string.append(Character.toUpperCase(currentChar));
        }

        System.out.println(string.toString());
    }
}
