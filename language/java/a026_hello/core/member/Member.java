package a026_hello.core.member;

import a026_hello.core.member.Grade;

public class Member {
  private Long id;
  private String name;
  private Grade grade;

  public Member(Long id, String name, Grade grade) {
    this.id = id;
    this.name = name;
    this.grade = grade;
  }

  public Long getId() {
    return this.id;
  }

  public void setId(Long id) {
    this.id = id;
  }

  public String getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public Grade getGrade() {
    return this.grade;
  }

  public void setGrade(Grade grade) {
    this.grade = grade;
  }
}
