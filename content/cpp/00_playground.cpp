#include <iostream>
#include <cassert>

#define GROUND025

//	template
#ifdef GROUND999
class Object	{
public:
};



int	main(void) {
	return 0;
}
#endif

#ifdef GROUND025
//	string practice
//
//	결과:
//	str.size() 는 13 이며, 실제 차지하는 공간은 16 byte 이기 때문에 npos 와 max_size() 가 16 만큼 차이가 난다.
int	main(void) {
	std::string	str = std::string("hello, world!");
	std::cout << "value of str: [" << str << "]" << std::endl;
	std::cout << "size of str: [" << str.size() << "]" << std::endl;
	std::cout << "max_size of str: [" << str.max_size() << "]" << std::endl;
	std::cout << "npos of string: [" << std::string::npos << "]" << std::endl;

	return 0;
}
#endif

#ifdef GROUND024
//	궁금: 없는 namespace 의 맴버를 선언하고 사용할 수 있을까?
int	main(void) {
	int	name::first = 42;	// error: use of undeclared identifier 'name'

	return 0;
}
#endif

#ifdef GROUND023
//	궁금: 있는 namespace 의 맴버를 추가 선언하고 사용할 수 있을까?
namespace name {
	int	first;
}

int	main(void) {
	std::cout << "name::first: " << name::first << std::endl;
	name::first = 42;
	std::cout << "name::first: " << name::first << std::endl;
	int	name::second = 1;	// error: definition or redeclaration of 'second' not allowed inside a function

	return 0;
}
#endif

#ifdef GROUND022
//	pointer practice
//
//	결과:
//	Object pointer 는 c 처럼 애매하게 사용할 수 없고, 딱 정해진 방식으로 사용해야 compile 이 진행된다.(& 와 * 를 정확한 위치에 정확한 갯수로 명시해야 한다.)
//	compiler 는 'void (*)(Object *const)' 와 'void (Object::*)() const' 를 다른 type 으로 처리한다.
class Object	{
public:
	int	value;

	Object(void);

	void	function(void) const;
};



Object::Object(void): value(0) {
	std::cout << "Object(void) is called" << std::endl;
}

void	Object::function(void) const {
	std::cout << "Object.function() is called" << std::endl;
}



int	main(void) {
	Object	object;
	Object	*pObject = &object;
	std::cout << "object.value: " << object.value << std::endl;
	std::cout << "pObject->value: " << pObject->value << std::endl;
	object.function();
	pObject->function();

	int	*ptr = &object.value;
	std::cout << "*ptr: " << *ptr << std::endl;
	*ptr = 42;
	std::cout << "*ptr: " << *ptr << std::endl;
	std::cout << "object.value: " << object.value << std::endl;

	int	Object::*pValue;
	pValue = &Object::value;
	std::cout << "object.*pValue = " << object.*pValue << std::endl;
	//	pObject->*pValue

	void	(Object::*f)(void) const;
	f = &Object::function;
	(object.*f)();
	//	(pObject->*f)();

//		void	(*newF)(Object *const);
//		newF = &Object::function;	// error: assigning to 'void (*)(Object *const)' from incompatible type 'void (Object::*)() const'
//		(*newF)(object);

	return 0;
}
#endif

#ifdef GROUND021
//	static member practice
//	static member attribute 는 꼭 'type Object::attr' 로 class declaration 밖에서 선언을 해주어야 한다.
//	그렇지 않으면 Undefined symbol link error 가 발생한다.
//	값은 c 처럼 compiler 가 알아서 초기화해 줄까?
class Object {
private:
	static int	_value;
public:
	static int	getValue(void);
};



int	Object::_value;

int	Object::getValue(void) {
	return Object::_value;
}



int	main(void) {
	std::cout << Object::getValue() << std::endl;

	return 0;
}
#endif

#ifdef GROUND020
//	궁금:
//	어떤 object 를 정의할 때 어떤 변수를 private 으로 정의하여 Object.cpp 로 Object.o 파일을 생성한 후, main.cpp 에서 사용할 때 해당 변수 선언을 public 으로 바꾸고 main.o 파일을 생성할 수 있을까?
//	그렇게 생성된 Object.o 파일과 mainc.o 파일을 link 하여 a.out 파일을 생성할 수 있을까?
//	생성된다면 이 파일이 실행될까?
//	02_main.cpp 로 테스트를 진행했다.
//	private 에 있던 변수를 public 으로 옮기면 당연히 잘 작동할 것 같다.
//	public 에 선언된 변수를 private 으로 옮기면 문제가 발생할 수 있을까?
//	가령 'Object(Object const &object) {}' 이런 복사 생성자에서 인자인 object 에 직접 접근 가능한 public 상태로 Object class 를 컴파일하고 main 은 private 으로 바꿔서 컴파일하면 어떨까?
//	아니다 이것은 어리석은 생각이다.
//	오류가 나든 나지 않든 크게 얻을 것이 없는 생각인 것 같다.
//	실제 저런 식으로 프로그램을 실행시킬 일은 없기 때문이다.
//	보안상으로도 private 으로 구현된 object 의 변수를 public 으로 수정하여 강제로 내부 변수에 직접 접근하는 방식을 제외하고는 큰 의미가 없다.
//	반대로 public 을 private 으로 바꾼다면 오히려 접근 권한을 더 줄일 뿐이다.
//
//	결과:
//	private 으로 선언된 attribute 를 public 으로 변경하여 main.o 를 생성하고 미리 컴파일해둔 Object.o 와 link 를 하니 해당 attribute 에 직접 접근하는 코드가 에러 없이 실행되는 것을 볼 수 있었다.
#endif

#ifdef GROUND019
//	궁금:
//	member variable 이 primitive type 이라면 초기화를 하지 않지만, instance 라면 default constructor 를 호출하지 않을까?
//
//	결과:
//	Container 의 default constructor 를 호출하기만 하고 member variable 인 content 의 값을 초기화하지 않았지만 content 의 type 이 object type 이기 때문에 default constructor 가 호출되었다.
//	그럼 structure 는 어떨까? 나중에 structure 를 사용할 일이 있으면 자세히 알아보도록 하자.
class	Content {
private:
public:
	Content(void);
	~Content(void);
};

Content::Content(void) {
	std::cout << "Content(void) is called" << std::endl;
}

Content::~Content(void) {
	std::cout << "~Content(void) is called" << std::endl;
}



class	Container {
private:
	Content	content;
public:
	Container(void);
	~Container(void);
};

Container::Container(void) {
	std::cout << "Container(void) is called" << std::endl;
}

Container::~Container(void) {
	std::cout << "~Container(void) is called" << std::endl;
}



int	main(void) {
	Container	container = Container();

	container = Container();

	return 0;
}
#endif

#ifdef GROUND018
//	Let's test cin
int	main(void) {
	char	buf[512];

	std::cout << "Input a word: ";
	std::cin >> buf;
	std::cout << "You input [" << buf << "]" << std::endl;

	return 0;
}
#endif

#ifdef GROUND017
//	namespace alias practice
namespace	Shape {
	class Point {public: double x, y;};
	class Circle {public: Point center; double radius;};
}

namespace	ShapeNew = Shape;

int	main(void) {
	ShapeNew::Circle	circle;

	std::cout << circle.radius << std::endl;

	return 0;
}
#endif

#ifdef GROUND016
//	namespace practice
namespace	Shape {
	class Point {public: double x, y;};
	class Circle {public: Point center; double radius;};
}

int	main(void) {
	Shape::Circle	circle;

	std::cout << circle.radius << std::endl;

	return 0;
}
#endif

#ifdef GROUND015
//	궁금: c++ 도 c 처럼 지역 변수는 따로 초기화하지 않는 것일까?
//	결과: c 와 마찬가지로 자동으로 초기화하지는 않는다
void	function(void) {
	int	local;

	std::cout << "Initial local variable: " << local << std::endl;
	local = 42;
	std::cout << "After set local variable: " << local << std::endl;
}

int	main(void) {
	function();
	function();

	return 0;
}
#endif

#ifdef GROUND014
//	궁금:
//	Object	object1;
//	Object	object2 = Object();
//	
//	object1 = Object();
//	
//	object1 은 default constructor 와 operator=() 가 호출될 것 같다
//	object2 는 default constructor 만 호출될 것 같다
//
//	결과:
//	- 예상과 일치
//		error 관련:
//		- 'Object object = Object();' 처럼 declaration 과 assignment 를 동시에 한 후
//			object 를 사용하지 않으면 unused variable error 가 발생한다
//		- 'Object object; object = Object();' 처럼 declaration 과 assignment 를
//			나눠 실시하면 이 후 object 를 사용하지 않아도
//			unused variable error 가 발생하지 않는다
class Object	{
public:
	int	_value;

	Object(void);
	~Object(void);

	Object	&operator=(Object const &rhs);

	int	getValue(void) const;
};



Object::Object(void) {
	std::cout << "Object(void) is called" << std::endl;

	return;
}

Object::~Object(void) {
	std::cout << "~Object(void) is called" << std::endl;

	return;
}

Object	&Object::operator=(Object const &rhs) {
	std::cout << "Object::operator=(rhs) is called" << std::endl;
	this->_value = rhs.getValue();

	return *this;
}

int	Object::getValue(void) const {
	return this->_value;
}



int	main(void) {
	Object	object1;
	Object	object2 = Object();

	object1 = Object();
	std::cout << "object1._value: " << object1.getValue() << std::endl;
	std::cout << "object2._value: " << object2.getValue() << std::endl;

	return 0;
}
#endif

#ifdef GROUND013
// What if call a function with more than the arguments which is required? 
// Let's call a function with argument wich requires no argument
//
// result:
//	in c: calling 'function(42)' from 'function()' is warning -> not intended work
//		- forced specifying 'void' on declaration of empty argument
//	in cpp: calling 'function(42)' from 'function()' is error -> consistent with intend
void	function() {
	std::cout << "function() is called" << std::endl;
}

int	main(void) {
	function(42);

	return 0;
}
#endif

#ifdef GROUND012
// If there is a parametric constructor that all argument's default value is specified, and call default constructor,
// and there is user-defined default constructor,
// would the parametric constructor called?
// or would the user-defined default constructor called?
//
// result: ambiguous error occured!
class Object {
public:
	int	_value;

	Object(void);
	Object(int value = 1);
};



Object::Object(void) {
	std::cout << "Object::Object(void) is called" << std::endl;

	return;
}

Object::Object(int value) {
	std::cout << "Object::Object(" << value << ") is called" << std::endl;

	return;
}


int	main(void) {
	Object	object;	// error: call to constructor of 'Object' is ambiguous

	return 0;
}
#endif

#ifdef GROUND011
// If there is a parametric constructor that all argument's default value is specified, and call default constructor,
// would the parametric constructor called?
// Let's declared a instance that implemented default argument parametric constructor
// parametric constructor is called!
// result:
// If don't use after construct instance by user-defined constructor would not occur error
// If don't use object after 'Object object(2)', don't occur unused variable error
// If don't use object after 'Object object = Object(2)' occur unused variable error
class Object {
public:
	int	_value;

	Object(int value = 1);
};



Object::Object(int value): _value(value) {
	std::cout << "Object(" << value << ") is called" << std::endl;
	return;
}



int	main(void) {
	Object	object = Object(2);

	std::cout << object._value << std::endl;
	object = Object(10);
	std::cout << object._value << std::endl;

	return 0;
}
#endif

#ifdef GROUND010
// What happen if i call a constructor that get some type which is not implemented as argument?
class Object {
public:
	int	_value;
};



int	main(int argc, char **argv) {
	Object	object = Object(42);	// error: no matching conversion for functional-style cast from 'int' to 'Object'

	std::cout << "object._value: " << object._value << std::endl;

	return 0;
}
#endif

#ifdef GROUND009
// Let's make simple class and it's parametric constructor
// There is compiler defined default constructor,
// but if define at least a user-defined constructor,
// compiler would not generate default constructor
class Object {
public:
	int	_value;

	Object(int value);
};



Object::Object(int value): _value(value) {
	return;
}



int	main(void) {
	Object	object;	// error: no matching constructor for initialization of 'Object'

	std::cout << object._value << std::endl;

	return 0;
}
#endif

#ifdef GROUND008
// Let's put NULL value to the function implemented at GROUND007
// We can know that NULL is of type 'void *'
// Because "void (*)(int &)" and "void (*)(int *)" is different, compiler can't find matching function for function(NULL)
void	function(int &referenceInt) {
	std::cout << "Value of parameter: " << referenceInt << std::endl;
}

int	main(void) {
	function(NULL);	// error: no matching function for call to 'function'

	return 0;
}
#endif

#ifdef GROUND007
// let's make simple function that takes reference type as argument
void	function(int &referenceInt) {
	std::cout << "Value of parameter: " << referenceInt << std::endl;
}

int	main(void) {
	int	i;

	i = 42;
	function(i);
}
#endif

#ifdef GROUND006
// let's see the value of member variable of simple class without user-defined constructor
// Default constructor made by compiler set the member variable as 0
class Object {
private:
	int	_value;
public:
	int	getValue(void) const;
};



int	Object::getValue(void) const {
	return this->_value;
}



int	main(int argc, char **argv) {
	Object	object;

	std::cout << object.getValue() << std::endl;

	return 0;
}
#endif

#ifdef GROUND005
// empty class
// If don't use after construct instance by default constructor made by compiler will occur error
class Object {
public:
};



int	main(void) {
	Object	object;	// error: unused variable 'object'

	return 0;
}
#endif

#ifdef GROUND004
// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-canonical-form/videos/canonical-form
class Object {
private:
	int	_value;
public:
	Object(void);
	Object(int const value);
	Object(Object const &src);
	~Object(void);

	Object	&operator=(Object const &rhs);

	int	getValue(void) const;
};

std::ostream	&operator<<(std::ostream &out, Object const &rhs);



Object::Object(void): _value(0) {
	std::cout << "Default Constructor called" << std::endl;

	return;
}

Object::Object(int const value): _value(value) {
	std::cout << "Parametric Constructor called" << std::endl;

	return;
}

Object::Object(Object const &src) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return;
}

Object::~Object(void) {
	std::cout << "Destructor called" << std::endl;

	return;
}

Object	&Object::operator=(Object const &rhs) {
	this->_value = rhs.getValue();
	return *this;
}

int	Object::getValue(void) const {
	return this->_value;
}

std::ostream	&operator<<(std::ostream &out, Object const &rhs) {
	out << "The value: " << rhs.getValue();
	return out;
}



int	main(void) {
	Object	instance1;
	Object	instance2 = Object(42);
	Object	instance3 = Object(instance1);

	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;

	return;
}
#endif

#ifdef GROUND003
// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-operator-overload/videos/operator-overload
// practice Integer class
class Object {
private:
	int	_n;

public:
	Object(int const n);
	~Object(void);

	int	getValue(void) const;

	Object	&operator=(Object const &rhs);
	Object	operator+(Object const &rhs) const;
};

std::ostream	&operator<<(std::ostream &out, Object const &rhs);



Object::Object(int const n): _n(n) {
	std::cout << "Constructor called with value " << n << std::endl;
	return;
}

Object::~Object(void) {
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return;
}

int	Object::getValue(void) const {
	return this->_n;
}

Object	&Object::operator=(Object const &rhs) {
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return *this;
}

Object	Object::operator+(Object const &rhs) const {
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	const Object result = Object(this->_n + rhs.getValue());
	return result;
}

std::ostream	&operator<<(std::ostream &out, Object const &rhs) {
	out << rhs.getValue();
	return out;
}



int	main(void) {
	Object	x = Object(10);
	Object y = Object(20);
	Object z = Object(30);

	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of y: " << y << std::endl;
	y = Object(40);
	std::cout << "Value of y: " << y << std::endl;
	std::cout << "Value of z: " << z << std::endl;
	z = x + y;
	std::cout << "Value of z: " << z << std::endl;

	return 0;
}
#endif

#ifdef GROUND002
// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-ad-hoc-polymorphism/videos/ad-hoc-polymorphisme
// practice Object class
class Object {

public:

	Object(void);
	~Object(void);

	void	bar(char const c) const;
	void	bar(int const n) const;
	void	bar(float const z) const;
	void	bar(double const d) const;
	void	bar(Object const &i) const;
};



Object::Object(void) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Object::~Object(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Object::bar(char const c) const {
	std::cout << "Member function bar called with char overload : " << c << std::endl;
	return;
}

void	Object::bar(int const n) const {
	std::cout << "Member function bar called with int overload : " << n << std::endl;
	return;
}

void	Object::bar(float const z) const {
	std::cout << "Member function bar called with float overload : " << z << std::endl;
	return;
}

void	Object::bar(double const d) const {
	std::cout << "Member function bar called with double overload : " << d << std::endl;
	return;
}

void	Object::bar(Object const &i) const {
	(void)i;
	std::cout << "Member function bar called with Object overload" << std::endl;
	return;
}



int	main(void) {
	Object	object;

	object.bar('a');
	object.bar(42);
	object.bar(3.14);
	object.bar(3.12345678901234567890);
	object.bar(object);

	return 0;
}
#endif

#ifdef GROUND001
// let's print the return value of cin::operator>>()
// If wrong type input, will it return NULL?
int	main(void) {
	int	num;

	std::cout << (std::cin >> num) << std::endl;

	return 0;
}
#endif

#ifdef GROUND000
// use assert()
int	main(int argc, char **argv) {
	assert(argc != 1);
	(void)argv;

	return 0;
}
#endif
