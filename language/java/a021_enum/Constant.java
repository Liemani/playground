package lmi;

public enum Constant {
    // enum value
    DIG("dig"),
    MINE("mine");

    // fields
    private String action_;

    // constructor
    Constant(String action) {
        action_ = action;
    }

    public static void main(String[] args) {
        Constant constant = Constant.DIG;
        System.out.println(constant);
    }
}
