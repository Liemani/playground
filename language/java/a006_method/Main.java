public class Main {
    public static void main(String[] args) {
        print("Hello, world!");
        print("Nice to meet you!");
        print(debugDescription());
    }

    static void print(String string) {
        System.out.println(string);
    }

    static String debugDescription() {
        return "nothing";
    }
}
