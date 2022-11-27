public class Fraction {
    int numerator = 0;
    int denominator = 1;

    public String debugDescription()  {
        String result = "";

        result += "{";
        result += "\"numerator\":";
        result += numerator;
        result += ",";
        result += "\"denominator\":";
        result += denominator;
        result += "}";

        return result;
    }
}
