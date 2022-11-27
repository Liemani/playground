package lmi;

public class Main {
    public static void main(String[] args) {
        Person person = new Person("john");
        System.out.println(person.name());

//          person.name() = "mike";
//          System.out.println(person.name());
//  Main.java:6: error: unexpected type
//          person.name() = "mike";
//                     ^
//    required: variable
//    found:    value
//  1 error
    }
}
