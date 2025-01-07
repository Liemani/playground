package a026_hello.core.discount;

import a026_hello.core.member.Member;

public interface DiscountPolicy {
  int discount(Member member, int price);
}
