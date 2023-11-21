public class Main {
    public static void main(String[] args) {
        String[] fruits = {"apple", "banana", "cherry", "dragon fruit", "eggplant", "fig"};
        int index = 1;

        for (String fruit: fruits) {
            System.out.print(index);
            System.out.print(": ");
            System.out.println(fruit);
            ++index;
        }

        fruits = null;

        for (String fruit: fruits) {
            System.out.print(index);
            System.out.print(": ");
            System.out.println(fruit);
            ++index;
        }
//          Exception in thread "main" java.lang.NullPointerException: Cannot read the array length because "<local3>" is null at Main.main(Main.java:15)
    }
}
