package lmi;

public class Main {
    public static void main(String[] args) {
        test002();
    }

    private static void test001() {
        try {
            System.out.println("[try block]");
        } catch (Exception e) {
            System.out.println("[catch block]");
            return;
        } finally {
            System.out.println("[finally block]");
        }

        System.out.println("[out of block]");

        try {
            System.out.println("[try block]");
            throw new Exception();
        } catch (Exception e) {
            System.out.println("[catch block]");
            return;
        } finally {
            System.out.println("[finally block]");
        }

        // unreachable here
    }

    private static void test002() {
        try {
            try {
                throw new RuntimeException();
            } catch (NullPointerException e) {
                System.out.println("[NullPointerException catch]");
            } finally {
                System.out.println("[NullPointerException catch try finally]");
            }
        } catch (RuntimeException e) {
                System.out.println("[RuntimeException catch]");
        }
    }
}
