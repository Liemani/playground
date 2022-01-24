#include <iostream>
#include <iomanip>
#include <cassert>

#define NDEBUG

#define GROUND049

//	template
#ifdef GROUND999
class Object {
public:
};



int main(void) {
	return 0;
}
#endif

#ifdef GROUND049
//	C++ Primer Plus 5ed 175p/6
struct CandyBar {
	std::string	name;
	double	weight;
	int	calorie;
};

void	CandyBarDescribe(CandyBar* candyBar, int index) {
	std::cout << index << ". Name: " << candyBar->name << std::endl;
	std::cout << index << ". Weight: " << candyBar->weight << std::endl;
	std::cout << index << ". Calories: " << candyBar->calorie << std::endl;
}

int	main(void) {
	CandyBar*	candyBars = new CandyBar[3];

	candyBars[0].name = "sneakers";
	candyBars[0].weight = 1.2;
	candyBars[0].calorie = 100;
	candyBars[1].name = "hot break";
	candyBars[1].weight = 2.3;
	candyBars[1].calorie = 200;
	candyBars[2].name = "free time";
	candyBars[2].weight = 3.4;
	candyBars[2].calorie = 300;

	CandyBarDescribe(candyBars, 1);
	std::cout << std::endl;
	CandyBarDescribe(candyBars + 1, 2);
	std::cout << std::endl;
	CandyBarDescribe(candyBars + 2, 3);

	delete [] candyBars;

	return 0;
}
#endif

#ifdef GROUND048
//	C++ Primer Plus 5ed 175p/7
struct Pizza {
	std::string	nameOfCompany;
	double	diameter;
	double	weight;
};

int	main(void) {
	Pizza*	pizza = new Pizza;

	std::cout << "Enter the diameter of pizza: ";
	std::cin >> pizza->diameter;
	std::cin.get();
	std::cout << "Enter the name of pizza company: ";
	std::getline(std::cin, pizza->nameOfCompany);
	std::cout << "Enter the weight of pizza: ";
	std::cin >> pizza->weight;

	std::cout << "Name: " << pizza->nameOfCompany << std::endl;
	std::cout << "Diameter: " << pizza->diameter << std::endl;
	std::cout << "Weight: " << pizza->weight << std::endl;

	delete pizza;

	return 0;
}
#endif

#ifdef GROUND047
//	C++ Primer Plus 5ed 175p/7
struct Pizza {
	std::string	nameOfCompany;
	double	diameter;
	double	weight;
};

int	main(void) {
	Pizza	pizza;

	std::cout << "Enter the name of pizza company: ";
	std::getline(std::cin, pizza.nameOfCompany);
	std::cout << "Enter the diameter of pizza: ";
	std::cin >> pizza.diameter;
	std::cout << "Enter the weight of pizza: ";
	std::cin >> pizza.weight;

	std::cout << "Name: " << pizza.nameOfCompany << std::endl;
	std::cout << "Diameter: " << pizza.diameter << std::endl;
	std::cout << "Weight: " << pizza.weight << std::endl;

	return 0;
}
#endif

#ifdef GROUND046
//	C++ Primer Plus 5ed 175p/6
struct CandyBar {
	std::string	name;
	double	weight;
	int	calorie;
};

void	CandyBarDescribe(CandyBar* candyBar, int index) {
	std::cout << index << ". Name: " << candyBar->name << std::endl;
	std::cout << index << ". Weight: " << candyBar->weight << std::endl;
	std::cout << index << ". Calories: " << candyBar->calorie << std::endl;
}

int	main(void) {
	CandyBar	candyBars[3] = {
		{"sneakers", 1.2, 100},
		{"hot break", 2.3, 200},
		{"free time", 3.4, 300},
	};

	CandyBarDescribe(candyBars, 1);
	std::cout << std::endl;
	CandyBarDescribe(candyBars + 1, 2);
	std::cout << std::endl;
	CandyBarDescribe(candyBars + 2, 3);

	return 0;
}
#endif

#ifdef GROUND045
//	C++ Primer Plus 5ed 175p/5
struct CandyBar {
	std::string	name;
	double	weight;
	int	calorie;
};

int	main(void) {
	CandyBar	snack = {"Mocha Munch", 2.3, 350};

	std::cout << "Name: " << snack.name << std::endl;
	std::cout << "Weight: " << snack.weight << std::endl;
	std::cout << "Calories: " << snack.calorie << std::endl;

	return 0;
}
#endif

#ifdef GROUND044
//	C++ Primer Plus 5ed 174p/4
int	main(void) {
	std::string	firstName;
	std::string	lastName;
	std::string	name;

	std::cout << "Enter your first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter your last name: ";
	std::getline(std::cin, lastName);
	name = lastName + ", " + firstName;
	std::cout << "Here's the information in a single string: " << name << std::endl;

	return 0;
}
#endif

#ifdef GROUND043
//	C++ Primer Plus 5ed 174p/3
int	main(void) {
	const int	lineMaxCount = 80;
	char	firstName[lineMaxCount];
	char	lastName[lineMaxCount];
	char	name[lineMaxCount];
	char*	namePointer;

	std::cout << "Enter your first name: ";
	std::cin.getline(firstName, lineMaxCount);
	std::cout << "Enter your last name: ";
	std::cin.getline(lastName, lineMaxCount);
	namePointer = name;
	strcpy(namePointer, lastName);
	namePointer += strlen(lastName);
	*namePointer++ = ',';
	*namePointer++ = ' ';
	strcpy(namePointer, firstName);
	std::cout << "Here's the information in a single string: " << name << std::endl;

	return 0;
}
#endif

#ifdef GROUND042
//	C++ Primer Plus 5ed 174p/2
int	main(void) {
	std::string	name;
	std::string	dessert;

	std::cout << "Enter your name:" << std::endl;
	std::getline(std::cin, name);
	std::cout << "Enter your favorite dessert:" << std::endl;
	std::getline(std::cin, dessert);
	std::cout << "I have some delicious " << dessert;
	std::cout << " for you, " << name << "." << std::endl;

	return 0;
}
#endif

#ifdef GROUND041
//	C++ Primer Plus 5ed 174p/1
enum Grade {A, B, C};

int	main(void) {
	const int	maxSize = 80;
	char	firstName[maxSize];
	char	lastName[maxSize];
	Grade	grade;
	int	age;

	std::cout << "What is your first name? ";
	std::cin.get(firstName, maxSize);
	std::cout << "What is your last name? ";
	std::cin >> lastName;
	std::cout << "What letter grade do you deserve? ";
	std::cin.get();
	grade = Grade(std::cin.get() - 'A');
	std::cout << "What is your age? ";
	std::cin >> age;
	std::cout << "Name: " << lastName << ", " << firstName << std::endl;
	std::cout << "Grade: " << char('A' + grade + 1) << std::endl;
	std::cout << "Age: " << age << std::endl;

	return 0;
}
#endif

#ifdef GROUND040
//	stack과 heap의 주소를 출력해보자.
//
//	결과: stack의 주소값은 점점 작아지고 heap의 주소값은 점점 커진다.
//		- code와 data를 담을 영역과 stack을 담을 영역을 먼저 결정하여 끝과 끝에 위치시켜두고 그 사이에서 heap이 채워져나가도록 만드는 것이 좋을 것이다.
int	main(void) {
	int	a;
	int	b;
	int*	c = new int;
	int*	d = new int;

	std::cout << "&a: " << &a << std::endl;
	std::cout << "&b: " << &b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	delete c;
	delete d;

	return 0;
}
#endif

#ifdef GROUND039
//	사용하지 않는 함수가 완성된 프로그램의 크기에 영향을 미칠까?
//	main 용량: 16834
//	hello 추가 용량: 40258
//	world 추가 용량: 30306
//
//	결과: 사용하지 않는 함수가 추가되어도 컴파일러는 이를 알아서 최적화하지 못하고 완성된 프로그램에 추가한다.
//		- 아마 최적화 옵션으로 결과가 달라질 수도 있을 것 같다.
void	world(void) {
	std::cout << "world" << std::endl;
}

void	hello(void) {
	std::cout << "hello" << std::endl;
}

int	main(void) {
	return 0;
}
#endif

#ifdef GROUND038
//	float, double, long double의 size를 출력해보자.
int	main(void) {
	std::cout << "sizeof(float): " << sizeof(float) << std::endl;
	std::cout << "sizeof(double): " << sizeof(double) << std::endl;
	std::cout << "sizeof(long double): " << sizeof(long double) << std::endl;

	return 0;
}
#endif

#ifdef GROUND037
//	반환값만 달라도 overloading이 될까?
//	error: functions that differ only in their return type cannot be overloaded
int	returnValue(void) {
	return 42;
}

double	returnValue(void) {
	return 4.2;
}
int	main(void) {
	int	x = returnValue();

	return 0;
}
#endif

#ifdef GROUND036
//	c++에서 private access modifier는 접근 범위를 instance로 제한하는 것이 아니라 class name scope으로 제한된다.
class	Type {
private:
	int	value;
public:
	Type(void) { this->value = 42; };
	Type(const Type& type);

	int	getValue(void) { return this->value; };
	void	setValue(int newValue) { this->value = newValue; };
};

Type::Type(const Type& type) {
	this->value = type.value;
}

int	main(void) {
	Type type1;
	type1.setValue(21);
	Type type2 = Type(type1);
	std::cout << "type2.value: " << type2.getValue() << std::endl;

	return 0;
}
#endif

#ifdef GROUND035
//	and, or, not practice
int	main(void) {
	bool	a = true;
	bool	b = false;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a and b) << std::endl;
	std::cout << (a or b) << std::endl;
	std::cout << not a << std::endl;
	std::cout << not b << std::endl;
	return 0;
}
#endif

#ifdef GROUND034
//	https://www.geeksforgeeks.org/default-methods-in-c-with-examples/
//	Default Methods in C++ with Examples
//	Type	type;
//		같다 Type	type = Type();
//	궁금: constructor에서 member variable에게 assign operator를 사용하면 member variable의 constructor가 두 번 호출될까?
//		default constructor도 호출되고 추가적인 constructor도 호출되고 copy assignment opertor도 호출되고 destructor도 호출된다.
//		: property(10)을 사용하면 parameterized constructor 하나만 호출된다.
//	Property의 default constructor가 없는데 Type이 Property를 member variable로 가지고 constructor에서 명시적으로 initialization을 하지 않으면 어떻게 될까?
//		error: constructor for 'Type' must explicitly initialize the member 'property' which does not have a default constructor
//	new keyword는 heap영역에 메모리 공간을 할당할 뿐만 아니라 default constructor도 호출한다. 
class	Super {
private:
	static int	referenceCount;
public:
	int	value;

	Super(void) { value = ++referenceCount; std::cout << "Super.defaultConstructor: " << referenceCount << std::endl; };
	Super(const Super& super) { this->value = super.value; std::cout << "Super.copyConstructor" << std::endl; };
	//	Called when an instance is passed as arguments to a constructor or returned
	~Super(void) { std::cout << "Super.destructor" << std::endl; };

	Super&	operator=(const Super& rhs) { this->value = rhs.value; std::cout << "super.copyAssignmentOperator" << std::endl; return *this; };
};

int	Super::referenceCount = 0;

class	Property {
private:
	static int	referenceCount;
public:
	int	value;

	Property(void) { value = ++referenceCount; std::cout << "Property.defaultConstructor: " << referenceCount << std::endl; };
	Property(int value) { this->value = value; };
	Property(const Property& property) { this->value = property.value; std::cout << "Property.copyConstructor" << std::endl; };
	~Property(void) { std::cout << "Property.destructor" << std::endl; };
	Property&	operator=(const Property& rhs) { this->value = rhs.value; std::cout << "property.copyAssignmentOperator" << std::endl; return *this; };
};

int	Property::referenceCount = 0;

class	Default: public Super {
private:
	Property	property;
//	public:
//		Default(void);
//		Default(const Default& type);
//		~Default(void);
//	
//		Default&	operator=(const Default& rhs);
};

//	Default::Default(void) {
//		super.defaultConstructor();
//		this->property.defaultConstructor();
//	}
//	
//	Default::Default(const Default& type) {
//		super.copyConstructor(type);
//		this->property.copyConstructor(type.property);
//	}
//	
//	Default::~Default(void) {
//		this->property.destructor();
//		super.destructor();
//	}
//	
//	Default&	Default::operator=(const Default& rhs) {
//		super.copyAssignmentOperator(rhs);
//		this->property.copyAssignmentOperator(rhs.property);
//	
//		return *this;
//	}

class	Type: public Super {
private:
	Property	property;
public:
	Type(void);
	Type(Property& property);
	Type(const Type& type);
	~Type(void);

	Type&	operator=(const Type& rhs);
};

Type::Type(void) {
	//	super.defaultConstructor
	//	this->property.defaultConstructor
//		this->property = Property(10);
	std::cout << "Type.defaultConstructor" << std::endl;
}

Type::Type(Property& property): property(property) {
	//	super.defaultConstructor
	//	property.copyConstructor
	std::cout << "Type.parameterizedConstructor" << std::endl;
}

Type::Type(const Type& type) {
	(void)type;
	//	super.defaultConstructor
	//	this->property.defaultConstructor
	std::cout << "Type.copyConstructor" << std::endl;
}

Type::~Type(void) {
	std::cout << "Type.destructor" << std::endl;
	//	this->property.destructor
	//	super.destructor
}

//	선언과 할당을 동시에 하는 경우를 제외한 모든 할당 시 호출
Type&	Type::operator=(const Type& rhs) {
	(void)rhs;
	std::cout << "type.copyAssignmentOperator" << std::endl;

	return *this;
}

int	main(void) {
//		Default	default1 = Default();
//		Default	default2 = Default(default1);
//		default2 = default1;

//		Type	type1 = Type();
//		Type	type2 = Type(type1);
//		type2 = type1;

//		Type*	type1 = new Type[2];
//		delete [] type1;

//		Property	property = Property(10);
//		Type	type = Type(property);

	return 0;
}
#endif

#ifdef GROUND033
//	namespace 안에서 'static const int' type 변수를 선언하고 초기화할 수 있을까?
//	가능하다, 'static' keyword를 빼도 잘 작동한다.
namespace name {
	int	value = 42;
}

int	main(void) {
	std::cout << "name::value: " << name::value << std::endl;
	return 0;
}
#endif

#ifdef GROUND032
//	인자의 type에 reference를 사용하면 Type 전후의 const는 주소가 가리키는 object가 변하지 않음을 의미한다.
class Object {
private:
public:
	int	_value;
};

void	function(Object &object) {
	object._value = 1;
	std::cout << "object._value: " << object._value << std::endl;
}

void	constFunction(const Object &object) {
	std::cout << "object._value: " << object._value << std::endl;
}

int	main(void) {
	Object	object;
	constFunction(object);
	function(object);

	return 0;
}
#endif

#ifdef GROUND031
//	practice string
int main(void) {
	std::string str = "hello, world!";

	std::cout << "str: " << str << std::endl;
	str.erase(0, 1);
	std::cout << "str: " << str << std::endl;
	return 0;
}
#endif

#ifdef GROUND031
//	global에 선언된 type은 '::'로 global type에 접근 가능하기 때문에 namespace 내부에서 같은 identifier를 사용하여 namespace를 정의할 수 있다.
typedef int Type;

namespace name {
	namespace Type {
		extern ::Type value;
	}
}

Type name::Type::value = 1;



int main(void) {
	std::cout << "name::Type::value: " << name::Type::value << std::endl;

	return 0;
}
#endif

#ifdef GROUND030
//	namespace의 identifier로 keyword를 사용할 수 없다. 
namespace name {
	namespace int {
		extern int value;
	}
}

int name::int::value = 1;



int main(void) {
	std::cout << "namespace::value: " << name::int::value << std::endl;

	return 0;
}
#endif

#ifdef GROUND029
//	궁금: const member를 constructor에서 assign하면 어떤 에러가 뜰까?
//	결과: "error: constructor for 'Object' must explicitly initialize the const member '_constant'"
//	"error: cannot assign to non-static data member '_constant' with const-qualified type 'const int'"
class Object {
public:
	int const	_constant;

	Object(int constant = 42);
};



Object::Object(int constant) {
	this->_constant = constant; 
	std::cout << "this->_constant: " << this->_constant << std::endl;
}



int	main(void) {
	Object	object = Object(10);

	std::cout << "object._constant: " << object._constant << std::endl;

	return 0;
}
#endif

#ifdef GROUND028
//	implicit type conversion을 할 때, source type을 인자로 하는 target type constructor와, source type의 conversion operator to target type이 모두 존재하면 ambiguous error가 발생할까?
//	결과: error: conversion from 'Source' to 'Target' is ambiguous
class Source;

class Target {
public:
	Target(void);
	Target(Source const &source);

	void nothing(void);
};

Target::Target(void) {}

Target::Target(Source const &source) {
	(void)source;
	std::cout << "Target(Source const &source) is called" << std::endl;
}

void	Target::nothing(void) {}



class Source {
public:
	operator Target(void) const;
};

Source::operator Target(void) const {
	std::cout << "operator Target(void) is called" << std::endl;

	return Target();
}



int	main(void) {
	Target	target = Source();

	target.nothing();

	return 0;
}
#endif

#ifdef GROUND027
//	Let's test cin
bool	getLine(std::string &line) {
	std::cout << "Input a word: ";
	std::getline(std::cin, line);

	return !std::cin.eof();
}

int	main(void) {
	std::string	line;

	while (getLine(line))
		std::cout << "You input [" << line << "]" << std::endl;

	return 0;
}
#endif

#ifdef GROUND026
//	궁금: std::setbase 의 return type 은 무엇일까?
//
//	결과:
//	실제 iomanip 파일을 열어보니 std::setbase(int)는 단순히 std::__iom_t3를 반환하는 inline 함수였다.
//	뜨는 에러로 확인해보아도 type은 std::__iom_t3이었다. 왜 cplusplus.com 등의 사이트에서는 /*unspecified*/ 라고 했을까?
//	아마 실제 implementation 은 'std::__iom_t3' 로 되어 있었지만 interface로는 /*unspecified*/이기 때문일 것 같다.
//	즉 implementation defined일 것 같다.
//	이 용어를 잘 설명한 블로그를 발견했다.
//	- https://m.blog.naver.com/ttagui/10043795874
//	implementation defined 와 unspecified 가 독립적으로 존재하는 개념이었다.
class Object {
};

int	main(void) {
	Object	object = Object(std::setbase(16));
	// error: no matching conversion for functional-style cast from 'std::__iom_t3' to 'Object'

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
