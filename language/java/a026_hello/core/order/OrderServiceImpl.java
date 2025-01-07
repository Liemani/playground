package a026_hello.core.order;

import a026_hello.core.order.Order;

import a026_hello.core.discount.DiscountPolicy;

import a026_hello.core.member.MemberRepository;
import a026_hello.core.member.Member;

public class OrderServiceImpl implements OrderService {
  private MemberRepository memberRepository;
  private DiscountPolicy  discountPolicy;

  public OrderServiceImpl(MemberRepository memberRepository, DiscountPolicy discountPolicy) {
    this.memberRepository = memberRepository;
    this.discountPolicy = discountPolicy;
  }

  @Override
  public Order createOrder(Long memberId, String itemName, int itemPrice) {
    Member member = this.memberRepository.findById(memberId);
    int discountPrice = this.discountPolicy.discount(member, itemPrice);

    return new Order(memberId, itemName, itemPrice, discountPrice);
  }
}
