package main;

import fraction.Fraction;

class Main {
    public static void main(String args[]) {
        Fraction fraction = new Fraction(4, 2);
        Fraction fraction2 = new Fraction();
        Fraction fractionArray[] = null;

        System.out.format("%s\n", fraction.debugDescription());
        System.out.println(fraction2.debugDescription());
        if (fractionArray == null)
            System.out.println("fractionArray == null");
    }
}
