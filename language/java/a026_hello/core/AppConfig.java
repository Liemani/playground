package a026_hello.core;

import a026_hello.core.order.OrderService;
import a026_hello.core.order.OrderServiceImpl;

import a026_hello.core.discount.DiscountPolicy;
import a026_hello.core.discount.FixDiscountPolicy;
import a026_hello.core.discount.RateDiscountPolicy;

import a026_hello.core.member.MemberService;
import a026_hello.core.member.MemberServiceImpl;
import a026_hello.core.member.MemberRepository;
import a026_hello.core.member.MemoryMemberRepository;

public class AppConfig {
  public MemberService memberService() {
    return new MemberServiceImpl(this.memberRepository());
  }

  public MemberRepository memberRepository() {
    return new MemoryMemberRepository();
  }

  public OrderService orderService() {
    return new OrderServiceImpl(this.memberRepository(), this.discountPolicy());
  }

  public DiscountPolicy discountPolicy() {
    return new RateDiscountPolicy();
  }
}
