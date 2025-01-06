[compile]
// compile name.java to name.class
javac name.java
// run name.class
java name

# 이해하지 못한 것

## access modifier
- default

## inner class
- (https://www.w3schools.com/java/java_inner_classes.asp)[https://www.w3schools.com/java/java_inner_classes.asp]
- 이게 static이랑 non-static이 둘 다 존재하네?
    - java에서는 class를 정의하는 것이 실제 구현이로 이어지는 모양이다.
        - 그래서 non-static이면 실제 instance를 생성할 때 내부적으로 메모리를 차지하고.. 아니.. 그럴 필요는 없는데..
        - 그냥 java가 그런식으로 해석할 뿐일지도
- inner class가 outer class의 attribute에 접근할 수 있다고 한다..
    - 그래서 non-static inner class는 outer class를 new 해야만 new 할 수 있구나!
