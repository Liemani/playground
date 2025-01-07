package a026_hello.core;

import a026_hello.core.AppConfig;

import a026_hello.core.order.Order;
import a026_hello.core.order.OrderService;

import a026_hello.core.member.Member;
import a026_hello.core.member.Grade;
import a026_hello.core.member.MemberService;

public class OrderApp {
  public static void main(String[] args) {
    AppConfig appConfig = new AppConfig();
    MemberService memberService = appConfig.memberService();

    //
    Long memberId = 1L;
    String memberName = "john";
    Grade memberGrade = Grade.VIP;

    Member member = new Member(memberId, memberName, memberGrade);
    memberService.join(member);

    //
    String itemName = "book";
    int itemPrice = 10000;
    OrderService orderService = appConfig.orderService();

    Order order = orderService.createOrder(member.getId(), itemName, itemPrice);

    System.out.println("order=" + order);
    System.out.println("order.calculatePrice()=" + order.calculatePrice());
  }
}
