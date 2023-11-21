import java.lang.reflect.*;

/** 
Compile with this:
C:\Documents and Settings\glow\My Documents\j>javac DumpMethods.java

Run like this, and results follow
C:\Documents and Settings\glow\My Documents\j>java DumpMethods
public void DumpMethods.foo()
public int DumpMethods.bar()
public java.lang.String DumpMethods.baz()
public static void DumpMethods.main(java.lang.String[])
*/

public class DumpMethods {
    static int first;
    int second;
    public int third;

    private void foo() { }

    private int bar() { return 12; }

    private String baz() { return ""; }

    private String hello() { return "hello"; }

    private static String world() { return "world"; }

//      public static void test1(Object o) { System.out.println("o"); }
//      public static void test1(Class c) { System.out.println("c"); }

    public static void main(String args[]) {
        try {
            DumpMethods dumpMethods = new DumpMethods();

//              test1(dumpMethods.getClass());
//              test1((Object)dumpMethods.getClass());

            Class DumpMethodsClass = DumpMethods.class;
            Method methodArray[] = DumpMethodsClass.getDeclaredMethods();
            Field[] fieldArray = DumpMethodsClass.getDeclaredFields();
            System.out.println(fieldArray.length);
            for (Field field : fieldArray) {
                System.out.println(field.getName());
            }

            System.out.println(void.class);
            System.out.println(void.class.getClass());
            System.out.println(void.class.getSuperclass());
            System.out.println(void.class.getGenericSuperclass());

            java.awt.Frame frame = new java.awt.Frame();
            System.out.println(frame.getClass());
            System.out.println(frame.getClass().getSuperclass());
//              Class temp = (Class)frame.getClass().getGenericSuperclass();
//              System.out.println(temp.getGenericSuperclass());
            System.out.println(((Class)frame.getClass().getGenericSuperclass()).getGenericSuperclass());

            System.out.println(DumpMethodsClass.getGenericSuperclass());
            System.out.println(((Class)DumpMethodsClass.getGenericSuperclass()).getGenericSuperclass());
            System.out.println(DumpMethodsClass.getGenericSuperclass().getClass());
            System.out.println(DumpMethodsClass.getGenericSuperclass().getClass().getGenericSuperclass());

            for (Method method : methodArray) {
                try {
                    System.out.println(method.toString());
                    if ((method.getModifiers() & Modifier.PRIVATE) != 0) {
                        Object object;
                        if ((method.getModifiers() & Modifier.STATIC) != 0)
                            object = method.invoke(null);
                        else
                            object = method.invoke(dumpMethods);
                        System.out.println(method.getName() + ": " + object);
                    }
//                      String name = method.getName();
//                      System.out.print(name + ": ");
//                      Object object = method.invoke(dumpMethods);
//                      System.out.println(object);
                }
                catch (Exception e) {
                    System.out.println("<access denied>");
                }
            }
        } catch (Throwable e) {
            System.err.println(e);
        }
    }
}
