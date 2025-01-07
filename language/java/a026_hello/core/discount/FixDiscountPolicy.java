package a026_hello.core.discount;

import a026_hello.core.member.Member;
import a026_hello.core.member.Grade;

public class FixDiscountPolicy implements DiscountPolicy {
  private final int discountFixAmount = 1000;

  @Override
  public int discount(Member member, int price) {
    if (member.getGrade() == Grade.VIP) {
      return discountFixAmount;
    } else  {
      return 0;
    }
  }
}
