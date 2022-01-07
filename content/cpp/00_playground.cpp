#include <iostream>
#include <cassert>

#define EXECUTE	a010



//	template
//	class Sample011
//	{
//	public:
//	};
//	
//
//
//	void	a011(int argc, char **argv)
//	{
//		(void)argc;
//		(void)argv;
//	}



// TODO
// If multi word input how it processed?



// If there is a parametric constructor that all argument's default value is specified, and call default constructor,
// and there is user-defined default constructor,
// would the parametric constructor called?
// or would the user-defined default constructor called?



// If there is a parametric constructor that all argument's default value is specified, and call default constructor,
// would the parametric constructor called?



// What happen if i call a constructor that get some type which is not implemented as argument?
class Sample010
{
public:
	int	_value;
};



void	a010(int argc, char **argv)
{
	Sample010	sample = Sample010(42);	// error: no matching conversion for functional-style cast from 'int' to 'Sample010'

	(void)argc;
	(void)argv;
	std::cout << "sample._value: " << sample._value << std::endl;
}



// Let's make simple class and it's parametric constructor
// There is compiler defined default constructor,
// but if define at least a user-defined constructor,
// compiler would not generate default constructor
class Sample009
{
public:
	int	_value;

//		Sample009(int value);
};


//	
//	Sample009::Sample009(int value)
//		: _value(value)
//	{
//		return;
//	}



void	a009(int argc, char **argv)
{
	Sample009	sample;	// error: no matching constructor for initialization of 'Sample009'

	(void)argc;
	(void)argv;
	std::cout << sample._value << std::endl;
}



// Let's put NULL value to the function implemented in a007
// We can know that NULL is of type 'void *'
// Because "void (*)(int &)" and "void (*)(int *)" is different, compiler can't find matching function for function007(NULL)
void	function007(int &referenceInt);

void	a008(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//		function007(NULL);	// error: no matching function for call to 'function007'
}



// let's make simple function that takes reference type as argument
void	function007(int &referenceInt)
{
	std::cout << "Value of parameter: " << referenceInt << std::endl;
}

void	a007(int argc, char **argv)
{
	int	i;

	(void)argc;
	(void)argv;
	i = 42;
	function007(i);
}



// let's see the value of member variable of simple class without user-defined constructor
class Sample006
{
private:
	int	_value;
public:
	int	getValue(void) const;
};



int	Sample006::getValue(void) const
{
	return this->_value;
}



void	a006(int argc, char **argv)
{
	Sample006	sample;

	(void)argc;
	(void)argv;
	std::cout << sample.getValue() << std::endl;	// 0
}



// empty class
class Sample005
{
public:
};



void	a005(int argc, char **argv)
{
	Sample005	sample;

	(void)argc;
	(void)argv;
	(void)sample;
}



// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-canonical-form/videos/canonical-form
class Integer000
{
private:
	int	_value;
public:
	Integer000(void);
	Integer000(int const value);
	Integer000(Integer000 const &src);
	~Integer000(void);

	Integer000	&operator=(Integer000 const &rhs);

	int	getValue(void) const;
};

std::ostream	&operator<<(std::ostream &out, Integer000 const &rhs);



Integer000::Integer000(void)
	: _value(0)
{
	std::cout << "Default Constructor called" << std::endl;

	return;
}

Integer000::Integer000(int const value)
	: _value(value)
{
	std::cout << "Parametric Constructor called" << std::endl;

	return;
}

Integer000::Integer000(Integer000 const &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return;
}

Integer000::~Integer000(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

Integer000	&Integer000::operator=(Integer000 const &rhs)
{
	this->_value = rhs.getValue();
	return *this;
}

int	Integer000::getValue(void) const
{
	return this->_value;
}

std::ostream	&operator<<(std::ostream &out, Integer000 const &rhs)
{
	out << "The value: " << rhs.getValue();
	return out;
}



void	a004(int argc, char **argv)
{
	Integer000	instance1;
	Integer000	instance2 = Integer000(42);
	Integer000	instance3 = Integer000(instance1);

	(void)argc;
	(void)argv;
	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;

	return ;
}



// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-operator-overload/videos/operator-overload
// practice Integer class
class Integer
{
private:
	int	_n;

public:
	Integer(int const n);
	~Integer(void);

	int	getValue(void) const;

	Integer	&operator=(Integer const &rhs);
	Integer	operator+(Integer const &rhs) const;
};

std::ostream	&operator<<(std::ostream &out, Integer const &rhs);



Integer::Integer(int const n)
	: _n(n)
{
	std::cout << "Constructor called with value " << n << std::endl;
	return;
}

Integer::~Integer(void)
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return;
}

int	Integer::getValue(void) const
{
	return this->_n;
}

Integer	&Integer::operator=(Integer const &rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return *this;
}

Integer	Integer::operator+(Integer const &rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	const Integer result = Integer(this->_n + rhs.getValue());
	return result;
}

std::ostream	&operator<<(std::ostream &out, Integer const &rhs)
{
	out << rhs.getValue();
	return out;
}

void	a003(int argc, char **argv)
{
	Integer	x = Integer(10);
	Integer y = Integer(20);
	Integer z = Integer(30);

	(void)argc;
	(void)argv;
	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of y: " << y << std::endl;
	y = Integer(40);
	std::cout << "Value of y: " << y << std::endl;
	std::cout << "Value of z: " << z << std::endl;
	z = x + y;
	std::cout << "Value of z: " << z << std::endl;
}



// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-ad-hoc-polymorphism/videos/ad-hoc-polymorphisme
// practice Sample class
class Sample {

public:

	Sample(void);
	~Sample(void);

	void	bar(char const c) const;
	void	bar(int const n) const;
	void	bar(float const z) const;
	void	bar(double const d) const;
	void	bar(Sample const &i) const;
};



Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar(char const c) const
{
	std::cout << "Member function bar called with char overload : " << c << std::endl;
	return;
}

void	Sample::bar(int const n) const
{
	std::cout << "Member function bar called with int overload : " << n << std::endl;
	return;
}

void	Sample::bar(float const z) const
{
	std::cout << "Member function bar called with float overload : " << z << std::endl;
	return;
}

void	Sample::bar(double const d) const
{
	std::cout << "Member function bar called with double overload : " << d << std::endl;
	return;
}

void	Sample::bar(Sample const &i) const
{
	(void)i;
	std::cout << "Member function bar called with Sample overload" << std::endl;
	return;
}

void	a002(int argc, char **argv)
{
	Sample	sample;

	(void)argc;
	(void)argv;
	sample.bar('a');
	sample.bar(42);
	sample.bar(3.14);
	sample.bar(3.12345678901234567890);
	sample.bar(sample);
}



// let's print the return value of cin::operator>>()
// If wrong type input, will it return NULL?
void	a001(int argc, char **argv)
{
	int	num;

	(void)argc;
	(void)argv;
	std::cout << (std::cin >> num) << std::endl;
}



// use assert()
void	a000(int argc, char **argv)
{
	assert(argc != 1);
	(void)argv;
}



int	main(int argc, char **argv)
{
	EXECUTE(argc, argv);
}
