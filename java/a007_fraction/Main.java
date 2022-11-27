public class Main {
    public static void main(String[] args) {
        Fraction fraction = new Fraction();
        print(fraction.debugDescription());
    }

    static void print(String string) {
        System.out.println(string);
    }

    static String debugDescription() {
        return "nothing";
    }
}
