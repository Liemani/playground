package lmi;

public class Main {
    public static void main(String args[]) {
        playground008();
    }

    Main() {
        System.out.println("constructor of Main is called");
    }

    static void playground001() {
        double doubleValue = 0x1.0p-10;
        System.out.println(doubleValue);
        System.out.println(Double.toHexString(Double.doubleToRawLongBits(doubleValue)));

        double doubleValue2 = (0x1.0p-10) * 11;
        System.out.println(doubleValue2);
        System.out.println(Double.toHexString(Double.doubleToRawLongBits(doubleValue2)));

        float doubleValue3 = 0x1.0p-10f;
        System.out.println(doubleValue3);
        System.out.println(Long.toBinaryString(Double.doubleToRawLongBits(doubleValue3)));
    }

    static void printTypeIfInt(Object object) {
        if (object instanceof Integer)
            System.out.print(object.getClass().getName());
    }

    static void playground002() {
        int i = 1;
        printTypeIfInt(i);
        System.out.println(i);
    }

    static void playground003() {
        Main main = new Main();
        System.out.println(main.hashCode());
        System.out.println(main);
        System.out.println(String.format("%08x", main.hashCode()));
    }

//      static <T> void playground004(T t) {
//          System.out.println(T.class);
//      }

    static void playground005() {
        Test<Object> test = new Test<Object>();

        System.out.println("test.getClass().getName(): " + test.getClass().getName());
        System.out.println("test.getMytype(): " + test.getMyType());
        System.out.println("test.getClass().getSimpleName(): " + test.getClass().getSimpleName());
        System.out.println("test.getClass().getTypeName(): " + test.getClass().getTypeName());
        System.out.println("test.getClass().toString(): " + test.getClass().toString());
        System.out.println("test.getClass().toGenericString(): " + test.getClass().toGenericString());
        System.out.println("test.getClass().getGenericSuperclass(): " + test.getClass().getGenericSuperclass());
        System.out.println("test.getClass(): " + test.getClass());
        System.out.println("test.getClass().getTypeParameters(): " + test.getClass().getTypeParameters());
        java.lang.reflect.TypeVariable[] parameterTypeArray = test.getClass().getTypeParameters();
        for (java.lang.reflect.TypeVariable type : parameterTypeArray)
            System.out.println(type.getGenericDeclaration());
    }

    static void playground006() {
        String hi = "hi";

        System.out.println(hi.contentEquals(null));
    }

    static void playground007() {
        byte[] string = "hi".getBytes(java.nio.charset.StandardCharsets.UTF_8);

        System.out.println(string.length);
    }

    static void playground008() {
        {
            return;
        }
//          System.out.println("hi");
    }
}
