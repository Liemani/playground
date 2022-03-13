#include "03_User1.hpp"
#include "03_User2.hpp"

//	class Layer
//	User1, User2
//	Constant
//	Value
//	Constant에 있는 'static const Value value = Value();'가 User1 file과 User2 file에서 각각 호출될까? 아니면 프로그램 통틀어서 한 번만 호출될까?
//
//	결과:
//	error: static data member of type 'const Value' must be initialized out of line
//	'static const Object' type은 class interface에서 정의할 수 없다.
//	'static const int'는 literal 표현이 가능하기 때문에 class 선언에 정의할 수 있는 모양이다.

int	main(void) {

	return 0;
}
