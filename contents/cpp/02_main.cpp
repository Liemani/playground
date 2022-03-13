//	궁금:
//	어떤 object 를 정의할 때 어떤 변수를 private 으로 정의하여 Object.cpp 로 Object.o 파일을 생성한 후, main.cpp 에서 사용할 때 해당 변수 선언을 public 으로 바꾸고 main.o 파일을 생성할 수 있을까?
//	그렇게 생성된 Object.o 파일과 mainc.o 파일을 link 하여 a.out 파일을 생성할 수 있을까?
//	생성된다면 이 파일이 실행될까?

#include <iostream>

class Object {
public:
	int	_value;

	int	getValue(void) const;
};

int	main(void) {
	Object	object;

	std::cout << object._value << std::endl;

	return 0;
}
