import java.lang.reflect.Method;

public class Temp {

    public void method1(String message) {
        System.out.println(message);
    }

    public void method2(Object object, Method method, String message) throws Exception {
        Object[] parameters = new Object[1];
        parameters[0] = message;
        method.invoke(object, parameters);
    }

    public static void main(String[] args) throws Exception{
        Class[] parameterTypes = new Class[1];
        parameterTypes[0] = String.class;
        Method method1 = Temp.class.getMethod("method1", parameterTypes);

        Temp temp = new Temp();
        temp.method2(temp, method1, "Hello World");
    }
}
