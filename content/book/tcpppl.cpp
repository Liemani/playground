#include <iostream>

#define	EXECUTE	a000

//	# 2021-12-15
//		40p ~
//		21p ~
//	- bool
//	- char
//	- int
//	- double
//	
//	# 2021-12-14
//		37p ~
//	- tcpppl 에서는 int main() { } 을 소개하는데, main 의 괄호 안에는 void 를 생략해도 되는 것일까?
//		- c 에서는 저 괄호 안에 void 를 써야하는 이유가, 쓰지 않으면 컴파일러가 잘못 사용됐을 때 에러를 잡아주지 못했다. int function() 으로 선언된 함수에 인자를 줬을 때 cpp 에서는 컴파일 단계에서 에러로 잡아주는지 확인해보도록 하고, 만약 에러를 잡아내지 못한다면 굳이 괄호 안에 void 를 써서 또 에러를 잡아주는지 확인하고 잡아주는 방법대로 구현하도록 하자
//	- 컴파일을 하기 위해 어떤 컴파일러를 사용할까? 물론 서브젝트에 나와있겠지만 tcpppl 에서는 어떤 컴파일러를 사용하도록 소개되어 있는지 보고 싶다.

// Let's print "Hello, World!\n"
int	a000()
{
	std::cout << "Hello, World!\n";
}

// If return is not expressed, the system who expect a return value
// will receive a value indicating successful completion
int	main()
{
	EXECUTE();
}
