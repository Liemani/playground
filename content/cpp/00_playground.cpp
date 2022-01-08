#include <iostream>
#include <cassert>

#define GROUND015

//	template
#ifdef GROUND999
class Object	{
public:
};



int	main()	{
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

int	main() {
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



int	main()	{
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

int	main()	{
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


int	main() {
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



int	main() {
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



int	main() {
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

int	main() {
	function(NULL);	// error: no matching function for call to 'function'

	return 0;
}
#endif

#ifdef GROUND007
// let's make simple function that takes reference type as argument
void	function(int &referenceInt) {
	std::cout << "Value of parameter: " << referenceInt << std::endl;
}

int	main() {
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



int	main() {
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



int	main() {
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



int	main() {
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



int	main() {
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
int	main() {
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
