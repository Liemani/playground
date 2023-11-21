public class Main {
    public static void main(String[] args) {
        byte byteInstance = -120;
        short shortInstance = -30000;
        int intInstance = -2100000000;
        long longInstance = -9223372036854775808L;

        float floatInstance = 12.34f;
        double doubleInstance = 1234.5678d;

        System.out.print("byteInstance: ");
        System.out.println(byteInstance);
        System.out.print("shortInstance: ");
        System.out.println(shortInstance);
        System.out.print("intInstance: ");
        System.out.println(intInstance);
        System.out.print("longInstance: ");
        System.out.println(longInstance);
        System.out.print("floatInstance: ");
        System.out.println(floatInstance);
        System.out.print("doubleInstance: ");
        System.out.println(doubleInstance);
        System.out.println();

        longInstance -= 1;
        System.out.print("longInstance: ");
        System.out.println(longInstance);
        System.out.println();

//          float floatInstance2 = 12.34;
//          Main.java:30: error: incompatible types: possible lossy conversion from double to float
        float floatInstance2 = 12.34f;
        double doubleInstance2 = 1234.5678;

        System.out.print("floatInstance: ");
        System.out.println(floatInstance);
        System.out.print("doubleInstance: ");
        System.out.println(doubleInstance);
        System.out.println();
    }
}
