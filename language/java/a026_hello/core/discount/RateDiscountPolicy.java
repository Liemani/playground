package a026_hello.core.discount;

import a026_hello.core.member.Member;
import a026_hello.core.member.Grade;

public class RateDiscountPolicy implements DiscountPolicy {
  private final static int discountPercent = 10;

  public int discount(Member member, int price) {
    if (member.getGrade() == Grade.VIP) {
      return price / 100 * discountPercent;
    } else {
      return 0;
    }
  }
}
