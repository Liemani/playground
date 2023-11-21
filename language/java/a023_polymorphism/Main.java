package lmi;

public class Main {
    public static void main(String[] args) {
        Point point = new Point();
        point.callOverrideThis();

        SpecialPoint specialPoint = new SpecialPoint();
        specialPoint.callOverrideThis();
    }
}
