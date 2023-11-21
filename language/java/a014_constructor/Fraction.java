package fraction;

public class Fraction {
    private double numerator_;
    private double denominator_;

    public Fraction() { numerator_ = 0; denominator_ = 1; };
    public Fraction(double numerator, double denominator) { numerator_ = numerator; denominator_ = denominator; }

    public String debugDescription() {
        String description = "";

        description += "{";
        description += "\"numerator_\":";
        description += numerator_;
        description += ",";
        description += "\"denominator_\":";
        description += denominator_;
        description += "}";

        return description;
    }
}
