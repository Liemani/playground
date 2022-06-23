//	type argument에 '='를 사용하여 lvalue로 사용하는 template에는 array를 인자로 전달할 수 없다.
//	type parameter가 array argument로 치환되면서 lvalue로 사용될 경우 compiler는 아래와 같은 error를 출력할 수 있다.
//	error: array type 'int [42]' is not assignable
#include "A007_Type.hpp"

int main(void) {
	A007_Type<int> instance1 = A007_Type<int>();
	A007_Type<int> instance2 = A007_Type<int>(instance1);
	A007_Type<int*> instance3 = A007_Type<int*>();
	A007_Type<int*> instance4 = A007_Type<int*>(instance3);
// 	A007_Type<int[42]> instance5 = A007_Type<int[42]>();
// 	A007_Type<int[42]> instance6 = A007_Type<int[42]>(instance5);

	instance1.describe();
	instance2.describe();
	instance3.describe();
	instance4.describe();
// 	instance5.describe();
// 	instance6.describe();

	instance1 = instance2;
	instance3 = instance4;
// 	instance5 = instance6;

	return 0;
}
