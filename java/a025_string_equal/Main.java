package lmi;

public class Main {
    public static void main(String[] args) {
        playground001();
    }

    private static void playground000() {
        String string1 = new String("liemani");
        String string2 = new String("liemani");

        System.out.println("string1 == string2: " + (string1 == string2));
        System.out.println("string1.equals(string2): " + string1.equals(string2));
    }

    private static void playground001() {
        final int a = +4;
        final int b = -4;

        System.out.println("a / 3: " + a / 3);
        System.out.println("a % 3: " + a % 3);
        System.out.println("b / 3: " + b / 3);
        System.out.println("b % 3: " + b % 3);
    }
}
