#include <iostream>

#define GROUND110
#ifdef GROUND110
//	C++ Primer Plus 5ed 139
//	struct possess at least 4 bytes

using std::cout;
using std::endl;

void floatToBit(float number, char bits[32]);
void charToBit(char ch, char bits[8]);

void describeBit(char bits[32]);

typedef union ClearFloat{
	char raw[4];
	float data;
} ClearFloat;

typedef union ieee754_float {
	float floatNumber;
	struct {
		unsigned int negative:1;
		unsigned int exponent:8;
		unsigned int mantissa:23;
	} ieee;
} ieee754_float;

union torgle_register_float {
	float floatNumber;
	struct {
		unsigned int SN: 4;
		unsigned int :4;
		bool goodIn: 1;
		bool goodTorgle: 1;
		bool goodTorgle2: 1;
	} torgle_register;
};

int	main(void) {
	torgle_register_float tr;
	char bits[32];

	tr.torgle_register.SN = 14;
	tr.torgle_register.goodIn = true;
	tr.torgle_register.goodTorgle = false;
	tr.torgle_register.goodTorgle2 = true;

	cout << "sizeof(ieee754_float): " << sizeof(ieee754_float) << endl;
	cout << "sizeof(tr): " << sizeof(tr) << endl;
	floatToBit(tr.floatNumber, bits);
	describeBit(bits);

	return 0;
}

void floatToBit(float number, char bits[32]) {
	ClearFloat data;

	data.data = number;
	for (int i = 0; i < 4; ++i) {
		charToBit(data.raw[3 - i], &bits[8 * i]);
	}
}

void charToBit(char ch, char bits[8]) {
	for (int i = 0; i < 8; ++i) {
		bits[i] = '0' + (ch >> (8 - i - 1) & 0x1);
	}
}

void describeBit(char bits[32]) {
	for (int i = 0; i < 32; ++i) {
		if (i % 8 == 0)
			putchar(' ');
		putchar(bits[i]);
	}
	putchar('\n');
}
#endif

#ifdef GROUND109
//	C++ Primer Plus 5ed 588
//	getline() discard '\n'
void cinDescribe(void) {
	std::cout << (std::cin ? "NORMAL" : "ERROR") << " / " << (std::cin.eof() ? "EOF" : "NOT EOF") << std::endl;
	std::cin.clear();
}

void getInput1(void) {
	char temp[80];

	std::cin.get(temp, 80);
	cinDescribe();
	std::cout << "temp: " << temp << std::endl;
}

void getInput2(void) {
	std::cin.get(*std::cout.rdbuf());
	cinDescribe();
}

void getInput3(void) {
	std::string str;

	std::getline(std::cin, str);
	cinDescribe();
	std::cout << "str: " << str << std::endl;
}

void getInput4(void) {
	char temp[80];

	std::cin.getline(temp, 80);
	cinDescribe();
	std::cout << "temp: " << temp << std::endl;
}

int	main(void) {
	getInput1();
	getInput2();
	getInput3();
	getInput4();
	getInput1();

	return 0;
}
#endif

#ifdef GROUND108
//	precedence of '+' operator
class Type {
private:
	int value;
public:
	Type(int value = 0);

	int getValue(void) const;
	void setValue(int value);

	Type operator+(const Type& rhs) const;
};

Type::Type(int value_)
	: value(value_) {}

int Type::getValue(void) const {
	return this->value;
}

void Type::setValue(int value) {
	this->value = value;
}

Type Type::operator+(const Type& rhs) const {
	Type type;
	std::cout << "rhs.getValue(): " << rhs.getValue() << std::endl;
	type.setValue(this->getValue() + rhs.getValue());
	return type;
}

int	main(void) {
	Type a = Type(10);
	Type b = Type(20);
	Type c = Type(30);

	a + b + c;

	return 0;
}
#endif

#ifdef GROUND107
//	conio.h 테스트
#include <conio.h>

int	main(void) {
	using std::cout;

	while (true) {
		cout << "input: " << _getch();
	}

	return 0;
}
#endif

#ifdef GROUND106
//	C++ Primer Plus 5ed 489
//
//	기본적으로는 class declaration에서 private section에 static const double type을 초기화하는 것을 지원하지 않는다.
class Type {
private:
	static const double	test = 3.14;
public:
	double getTest(void) { return test; };
};

int	main(void) {
	using std::cout;
	using std::endl;

	Type type;
	cout << type.getTest() << endl;

	return 0;
}
#endif

#ifdef GROUND105
//	C++ Primer Plus 5ed 458
//
//	instance method implementation에서 qualified name으로 private member variable에 접근하기
class Type {
	int variable;

public:
	Type(int variable = 0) { Type::variable = variable; }
	void increaseVariable(void) { variable += 1; }
	void decreaseVariable(void) { Type::variable -= 1; }
	void setVariable(int variable) { Type::variable = variable; }
	const int& getVariable(void) const { return Type::variable; }
	void add(const Type& rhs, Type& result) const;
};

void Type::add(const Type& rhs, Type& result) const {
	result.variable = Type::variable + rhs.variable;
}

int	main(void) {
	using std::cout;
	using std::endl;

	Type type1 = Type(42);

	cout << type1.getVariable() << endl;
	type1.setVariable(10);
	cout << type1.getVariable() << endl;

	Type type2 = Type(21);
	Type type3;
	type1.add(type2, type3);
	cout << type3.getVariable() << endl;

	return 0;
}
#endif

#ifdef GROUND104
//	C++ Primer Plus 5ed 442/Programming Exercises/4
#include "06_programming_exercise_9_4.hpp"

int	main(void) {
	const double	ar[3] = { 1.1, 4.4, 2.2 };

	SALES::Sales	sales1;
	setSales(sales1, ar, 3);
	showSales(sales1);

	SALES::Sales	sales2;
	setSales(sales2);
	showSales(sales2);

	return 0;
}
#endif

#ifdef GROUND103
//	C++ Primer Plus 5ed 442/Programming Exercises/3
struct chaff
{
	char	dross[20];
	int		slag;
};

int	main(void) {
	using std::cout;
	using std::endl;

	char*	buffer = new char[100];

	chaff* array = new (buffer) chaff[2];
	strcpy(array[0].dross, "1234");
	array[0].slag = 10;
	strcpy(array[1].dross, "4321");
	array[1].slag = 42;

	for (int i = 0; i < 2; ++i)
		cout << array[i].dross << array[i].slag << endl;

	delete [] buffer;

	return 0;
}
#endif

#ifdef GROUND102
//	C++ Primer Plus 5ed 442/Programming Exercises/2
void	strcount(const char* str);

int	main(void) {
	using std::cin;
	using std::cout;
	using std::string;

	string	input;

	cout << "Enter a line:\n";
	std::getline(cin, input);
	while(cin and input != "")
	{
		strcount(input.c_str());
		cout << "Enter next line (empty line to quit):\n";
		std::getline(cin, input);
	}
	cout << "Bye\n";

	return 0;
}

void	strcount(const char* str)
{
	using std::cout;

	static int	total = 0;
	int count = 0;

	cout << "\"" << str << "\" contains ";
	while (*str++)
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#endif

#ifdef GROUND101
//	C++ Primer Plus 5ed 441/Programming Exercises/1
#include "05_programming_exercise_9_1.hpp"

int	main(void) {
	golf	ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	handicap(ann, 42);
	showgolf(ann);

	golf	andy;
	if (setgolf(andy) != 0) {
		showgolf(andy);
		handicap(andy, 42);
		showgolf(andy);
	}

	return 0;
}
#endif

#ifdef GROUND100
//	C++ Primer Plus 5ed 439/Review Questions/4
int	main(void) {
	using std::cin;
	using std::cout;
	using std::endl;

	double	x;

	cout << "Enter value: ";
	while (!(cin >> x)) {
		cout << "Bad input. Please enter a number: ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cout << "Value = " << x << endl;

	return 0;
}
#endif

#ifdef GROUND099
//	C++ Primer Plus 5ed 439/Review Questions/3
int	main(void) {
	double	x;

	std::cout << "Enter value: ";
	while (!(std::cin >> x)) {
		std::cout << "Bad input. Please enter a number: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cout << "Value = " << x << std::endl;

	return 0;
}
#endif

#ifdef GROUND098
//	C++ Primer Plus 5ed 406
//	함수 안에서 선언된 static variable은 declaration statement가 실행된 후 함수가 호출됐을 때 함수의 실행과 동시에 come into scope할까?
//
//	결과: 항상 declaration statement가 실행된 시점부터 come into scope한다.
using std::cout;
using std::endl;

static int	var = 42;

void	printVar(void);

int	main(void) {
	printVar();
	printVar();

	return 0;
}

void	printVar(void) {
	cout << var << endl;
	static int	var = 10;
	cout << var << endl;
	var = 21;
}
#endif

#ifdef GROUND097
//	C++ Primer Plus 5ed 391/Programming Exercises/7
template <typename T>
T	ShowArray(T arr[], int n);

template <typename T>
T	ShowArray(T* arr[], int n);

struct debts {
	char	name[50];
	double	amount;
};

int	main(void) {
	using namespace std;
	int	things[6] = { 13, 31, 103, 301, 310, 130 };
	struct	debts mr_E[3] = {
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Listing Mr. E's counts of things:\n";
	cout << ShowArray(things, 6) << endl;
	cout << "Listing Mr. E's debts:\n";
	cout << ShowArray(pd, 3) << endl;

	return 0;
}

template <typename T>
T	ShowArray(T arr[], int n) {
	using namespace std;

	T	total = 0.0;
	cout << "template A\n";
	for (int i = 0; i < n; i++)
		total += arr[i];

	return total;
}
template <typename T>
T	ShowArray(T* arr[], int n) {
	using namespace std;

	T	total = 0.0;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		total += *arr[i];

	return total;
}
#endif

#ifdef GROUND096
//	C++ Primer Plus 5ed 391/Programming Exercises/6
template <typename T>
T& maxn(T array[], int count) {
	T*	biggest = &array[0];
	for (int i = 1; i < count; ++i)
		if (array[i] > *biggest)
			biggest = &array[i];

	return *biggest;
}

template <>
const char*&	maxn<const char*>(const char* array[], int count);

int	main(void) {
	int	intArray[6] = { 1, 3, 2, 5, 4, 6 };
	double	doubleArray[4] = { 1.1, 3.3, 4.4, 2.2 };
	const char*	strArray[5] = { "hi", "hello", "there", ":DD", "!" };

	std::cout << maxn(intArray, 6) << std::endl;
	std::cout << maxn(doubleArray, 4) << std::endl;
	std::cout << maxn(strArray, 4) << std::endl;

	return 0;
}

template <>
const char*&	maxn<const char*>(const char* array[], int count) {
	const char**	longest = &array[0];
	int	longest_count = strlen(*longest);
	int	str_count;

	for (int i = 1; i < count; ++i) {
		str_count = strlen(array[i]);
		if (str_count > longest_count) {
			longest = &array[i];
			longest_count = str_count;
		}
	}

	return *longest;
}

#endif

#ifdef GROUND095
//	C++ Primer Plus 5ed 391/Programming Exercises/5
template <typename T>
T&	max5(T array[5]) {
	T*	biggest = &array[0];
	for (int i = 1; i < 5; ++i)
		if (array[i] > *biggest)
			biggest = &array[i];

	return *biggest;
}

int	main(void) {
	int	intArray[5] = { 0, 4, 3, 2, 1 };
	double doubleArray[5] = { 0.5, 4.4, 3.3, 2.2, 1.1 };

	std::cout << max5(intArray) << std::endl;
	std::cout << max5(doubleArray) << std::endl;

	return 0;
}
#endif

#ifdef GROUND094
//	C++ Primer Plus 5ed 390/Programming Exercises/4
using namespace std;
#include <cstring>
struct stringy {
	char*	str;
	int	ct;
};

void	set(stringy& string, const char* str);
void	show(stringy& string, int count = 1);
void	show(const char* str, int count = 1);

int	main(void) {
	stringy	beany;
	char	testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	delete [] beany.str;

	return 0;
}

void	set(stringy& string, const char* str) {
	string.ct = strlen(str);
	string.str = new char[string.ct + 1];
	strcpy(string.str, str);
}

void	show(stringy& string, int count) {
	for (int i = 0; i < count; i += 1)
		cout << string.str << endl;
}

void	show(const char* str, int count) {
	for (int i = 0; i < count; i += 1)
		cout << str << endl;
}
#endif

#ifdef GROUND093
//	C++ Primer Plus 5ed 390/Programming Exercises/3
void	string_toupper(std::string& string);

int	main(void) {
	using std::cin;
	using std::cout;
	using std::endl;

	std::string	string;

	cout << "Enter a string (q to quit): ";
	while (getline(cin, string) && string != "q") {
		string_toupper(string);
		cout << string << endl;
		cout << "Enter a string (q to quit): ";
	}

	cout << "Bye." << endl;

	return 0;
}

void	string_toupper(std::string& string) {
	for (unsigned long i = 0; i < string.length(); i += 1)
		string[i] = toupper(string[i]);
}
#endif

#ifdef GROUND092
//	C++ Primer Plus 5ed 390/Programming Exercises/2
struct CandyBar {
	std::string	brandName;
	double	weight;
	int	calories;
};

void	CandyBar_init(CandyBar& bar,
		const char* brandName = "Millenium Munch",
		double weight = 2.85,
		int calories = 350);

void	CandyBar_describe(const CandyBar& bar);

int	main(void) {
	CandyBar	bar;

	CandyBar_init(bar);
	CandyBar_describe(bar);
	CandyBar_init(bar, "nonsan");
	CandyBar_describe(bar);
	CandyBar_init(bar, "nonsan", 4.2);
	CandyBar_describe(bar);

	return 0;
}

void	CandyBar_init(CandyBar& bar, const char* brandName, double weight, int calories) {
	bar.brandName = brandName;
	bar.weight = weight;
	bar.calories = calories;
}

void	CandyBar_describe(const CandyBar& bar) {
	using std::cout;
	using std::endl;

	cout << "candy bar:" << endl;
	cout << "	brandName: " << bar.brandName << endl;
	cout << "	weight: " << bar.weight << endl;
	cout << "	calories: " << bar.calories << endl;
}
#endif

#ifdef GROUND091
//	C++ Primer Plus 5ed 390/Programming Exercises/1
void	str_print(const char* str, int attr = 0);

int	main(void) {
	str_print("hello, world1");
	str_print("hello, world2");
	str_print("hello, world3");
	str_print("hello, world4", -1);

	return 0;
}

void	str_print(const char* str, int attr) {
	using std::cout;
	using std::endl;

	static int	str_print_callCount = 0;

	str_print_callCount += 1;
	if (attr == 0)
		cout << str << endl;
	else
		for (int i = 0; i < str_print_callCount; i += 1)
			cout << str << endl;
}
#endif

#ifdef GROUND090
//	C++ Primer Plus 5ed 390/Review Questions/7
struct box {
	char	maker[40];
	float	height;
	float	width;
	float	length;
	float	volume;
};

void	boxDescribe(box& box1);
void	boxSetVolume(box& box1);

template <typename T>
T&	larger(T& lhs, T& rhs) {
	return lhs > rhs ? lhs : rhs;
}

template <>
box&	larger<box>(box& lhs, box& rhs);

int	main(void) {
	box	box1 = {
		"nonsan",
		42,
		10,
		13,
		15,
	};
	box	box2 = {
		"daejeon",
		10,
		20,
		30,
		40,
	};

	boxSetVolume(box1);
	boxSetVolume(box2);
	boxDescribe(larger(box1, box2));
	boxDescribe(box1);
	boxDescribe(box2);

	return 0;
}

void	boxDescribe(box& box1) {
	using std::cout;
	using std::endl;

	cout << "box:" << endl;
	cout << "	maker: " << box1.maker << endl;
	cout << "	height: " << box1.height << endl;
	cout << "	width: " << box1.width << endl;
	cout << "	length: " << box1.length << endl;
	cout << "	volume: " << box1.volume << endl;
}

void	boxSetVolume(box& box1) {
	box1.volume = box1.height * box1.width * box1.length;
}

template <>
box&	larger<box>(box& lhs, box& rhs) {
	return lhs.volume > rhs.volume ? lhs : rhs;
}
#endif

#ifdef GROUND089
//	C++ Primer Plus 5ed 389/Review Questions/4
struct box {
	char	maker[40];
	float	height;
	float	width;
	float	length;
	float	volume;
};

void	boxDescribe(box& box1);
void	boxSetVolume(box& box1);

int	main(void) {
	box	box1 = {
		"nonsan",
		42,
		10,
		13,
		15,
	};

	boxSetVolume(box1);
	boxDescribe(box1);

	return 0;
}

void	boxDescribe(box& box1) {
	using std::cout;
	using std::endl;

	cout << "box:" << endl;
	cout << "	maker: " << box1.maker << endl;
	cout << "	height: " << box1.height << endl;
	cout << "	width: " << box1.width << endl;
	cout << "	length: " << box1.length << endl;
	cout << "	volume: " << box1.volume << endl;
}

void	boxSetVolume(box& box1) {
	box1.volume = box1.height * box1.width * box1.length;
}
#endif

#ifdef GROUND088
//	C++ Primer Plus 5ed 389/Review Questions/3
void	iquote(int number);
void	iquote(double number);
void	iquote(std::string string);

int	main(void) {
	iquote(42);
	iquote(4.2);
	iquote("42");

	return 0;
}

void	iquote(int number) {
	using std::cout;
	using std::endl;

	cout << '\"' << number << '\"' << endl;
}

void	iquote(double number) {
	using std::cout;
	using std::endl;

	cout << '\"' << number << '\"' << endl;
}

void	iquote(std::string string) {
	using std::cout;
	using std::endl;

	cout << '\"' << string << '\"' << endl;
}
#endif

#ifdef GROUND087
//	C++ Primer Plus 5ed 371
template <class T>
void swap(T& lhs, T& rhs);

int	main(void) {
	using std::cout;
	using std::endl;

	int	a = 1;
	int	b = 2;
	swap(a, b);
	cout << a << b << endl;

	double c = 1.1;
	double d = 2.2;
	swap(c, d);
	cout << c << d << endl;

	return 0;
}

template <class T>
void swap(T& lhs, T& rhs) {
	T	temp;

	temp = lhs;
	lhs = rhs;
	rhs = temp;
}
#endif

#ifdef GROUND086
//	C++ Primer Plus 5ed 351/8.6
using namespace std;
struct sysop {
	char	name[26];
	char	quote[64];
	int	used;
};

const sysop&	use(sysop& sysopref);

int	main(void) {
	sysop	looper = {
		"Rick \"Fortran\" Looper",
		"I'm a goto kink of guy.",
		0,
	};

	use(looper);
	cout << "Looper: " << looper.used << " use(s)\n";

// 	sysop	copycat;
// 	copycat = use(looper);
// 	copycat = (const sysop&)looper;
	sysop&	copycat = (const sysop&)looper;
	copycat.used = 42;

	cout << "Copycat: " << copycat.used << " use(s)\n";
	return 0;
}

const sysop&	use(sysop& sysopref) {
	cout << sysopref.name << " says:\n";
	cout << sysopref.quote << endl;
	sysopref.used++;
	return sysopref;
}
#endif

#ifdef GROUND085
//	C++ Primer Plus 5ed 336/Programming Exercises/9
double	calculate(double lhs, double rhs, double (*operation)(double, double)) {
	return operation(lhs, rhs);
}

double	add(double lhs, double rhs) {
	return lhs + rhs;
}

double	sub(double lhs, double rhs) {
	return lhs - rhs;
}

double	mul(double lhs, double rhs) {
	return lhs * rhs;
}

double	div(double lhs, double rhs) {
	return rhs == 0 ? 0 : lhs / rhs;
}

int	main(void) {
	using std::cin;
	using std::cout;
	using std::endl;

	const int	operationArray_count = 4;

	double	(*operationArray[operationArray_count])(double, double) = {
		add,
		sub,
		mul,
		div,
	};

	double	lhs;
	double	rhs;
	cout << "Enter two number to calculate: ";
	while (cin >> lhs >> rhs) {
		for (int index = 0; index < operationArray_count; index += 1)
			cout << "#" << index << ": " << calculate(lhs, rhs, operationArray[index]) << endl;
		cout << "Enter two number to calculate: ";
	}

	return 0;
}
#endif

#ifdef GROUND084
//	C++ Primer Plus 5ed 335/Programming Exercises/8
using namespace std;

const int	SLEN = 30;
struct student {
	char	fullname[SLEN];
	char	hobby[SLEN];
	int	ooplevel;
};

int	getinfo(student pa[], int n) {
	int	index = 0;
	student*	element = pa;
	while (index < n) {
		cout << "student #" << index + 1 << ": " << endl;
		cout << "	fullname: ";
		cin.getline(element->fullname, SLEN);
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n' && cin);
		}
		cout << "	hobby: ";
		cin.getline(element->hobby, SLEN);
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n' && cin);
		}

		element += 1;
		index += 1;
	}

	return index;
}

void	display1(student st) {
	cout << "student:" << endl;
	cout << "	fullname: " << st.fullname << endl;
	cout << "	hobby: " << st.hobby << endl;
}

void	display2(const student * ps) {
	cout << "student:" << endl;
	cout << "	fullname: " << ps->fullname << endl;
	cout << "	hobby: " << ps->hobby << endl;
}

void	display3(const student pa[], int n) {
	int index = 0;
	const student*	element = pa;
	while (index < n) {
		cout << "student #" << index + 1 << ": " << endl;
		cout << "	fullname: " << element->fullname << endl;
		cout << "	hobby: " << element->hobby << endl;
		element += 1;
		index += 1;
	}
}

int	main(void) {
	cout << "Enter class size: ";
	int	class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student * ptr_stu = new student[class_size];
	int	entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";

	return 0;
}
#endif

#ifdef GROUND083
//	C++ Primer Plus 5ed 335/Programming Exercises/7
const int	Max = 5;

double*	fill_array(double* start, double* end) {
	using std::cin;
	using std::cout;

	double temp;

	for (int index = 1; start != end; index += 1, start +=1) {
		cout << "Enter value #" << index << ": ";
		cin >> temp;
		if(!cin) {
			cin.clear();
			while (cin.get() != '\n' && cin);
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*start = temp;
	}
	return start;
}

void	show_array(const double* start, const double* end) {
	using std::cout;
	using std::endl;

	for (int index = 1; start != end; index += 1, start +=1) {
		cout << "Property #" << index << ": $";
		cout << *start << endl;
	}
}

void	revalue(double r, double* start, double* end) {
	for (; start != end; start += 1)
		*start *= r;
}

int	main(void) {
	using namespace std;
	double	properties[Max];

	double* end = fill_array(properties, properties + Max);
	show_array(properties, end);
	cout << "Enter rebaluation factor: ";
	double	factor;
	cin >> factor;
	revalue(factor, properties, end);
	show_array(properties, end);
	cout << "Done.\n";
	return 0;
}
#endif

#ifdef GROUND082
//	C++ Primer Plus 5ed 335/Programming Exercises/6
int	Fill_array(double array[], int size) {
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter double values to fill array" << endl;
	int	index;
	for (index = 0; index < size && cin >> array[index]; index += 1);

	return index;
}

void	Show_array(double array[], int size) {
	using std::cout;
	using std::endl;

	for (int index = 0; index < size; index += 1)
		cout << "array[" << index << "]: " << array[index] << endl;
}

void	Reverse_array(double array[], int size) {
	for (int lhs = 0, rhs = size - 1; lhs < rhs; lhs += 1, rhs -= 1) {
		double	temp;
		temp = array[lhs];
		array[lhs] = array[rhs];
		array[rhs] = temp;
	}
}

int	main(void) {
	const int	arraySize = 10;
	double	array[arraySize];

	const int	arrayCount = Fill_array(array, arraySize);
	Show_array(array, arrayCount);
	Reverse_array(array, arrayCount);
	Show_array(array, arrayCount);
	Reverse_array(array + 1, arrayCount - 2);
	Show_array(array, arrayCount);

	return 0;
}
#endif

#ifdef GROUND081
//	C++ Primer Plus 5ed 334/Programming Exercises/5
long	getFactorial(int number) {
	if (number > 0)
		return number * getFactorial(number - 1);
	else if (number == 0)
		return 1;
	else
		return -1;
}

int	main(void) {
	using std::cout;
	using std::endl;
	using std::cin;

	int	number;

	cout << "Enter a number you want to get of factorial: ";
	while (cin >> number)
		cout << "Fatorial: " << getFactorial(number) << endl;

	return 0;
}
#endif

#ifdef GROUND080
//	C++ Primer Plus 5ed 334/Programming Exercises/3
#include <cstring>

struct Box {
	char	maker[40];
	float	height;
	float	width;
	float	length;
	float	volume;
};

void	Box_describe(Box box) {
	using std::cout;
	using std::endl;

	cout
		<< "box.maker: " << box.maker << endl
		<< "box.height: " << box.height << endl
		<< "box.width: " << box.width << endl
		<< "box.length: " << box.length << endl
		<< "box.volume: " << box.volume << endl;
}

void	Box_setVolume(Box* box) {
	box->volume = box->height * box->width * box->length;
}

int	main(void) {
	using std::cout;
	using std::endl;
	using std::cin;

	Box	box;

	strcpy(box.maker, "nonsan");
	box.height = 2;
	box.width = 3;
	box.length = 5;
	box.volume = 0;

	Box_setVolume(&box);
	Box_describe(box);

	return 0;
}
#endif

#ifdef GROUND079
//	C++ Primer Plus 5ed 334/Programming Exercises/2
int	setGolfScoreArray(int golfScoreArray[], int arraySize) {
	using std::cout;
	using std::endl;
	using std::cin;

	double	input;
	int	index;

	cout << "Enter up to 10 golf scores:" << endl;
	index = 0;
	while (index < arraySize && cin >> input) {
		golfScoreArray[index] = input;
		index += 1;
	}

	return index;
}

void	describeGolfScoreArray(int golfScoreArray[], int count) {
	using std::cout;
	using std::endl;

	for (int index = 0; index < count; index += 1)
		cout << golfScoreArray[index] << ' ';
	cout << endl;
}

double	averageGolfScore(int golfScoreArray[], int count) {
	int	sum = 0;
	for (int index = 0; index < count; index += 1)
		sum += golfScoreArray[index];

	return double(sum) / count;
}

int	main(void) {
	using std::cout;
	using std::endl;
	using std::cin;

	const int	scoreArrayCount = 10;
	int	golfScoreArray[scoreArrayCount];

	int	setCount = setGolfScoreArray(golfScoreArray, scoreArrayCount);
	describeGolfScoreArray(golfScoreArray, setCount);

	cout << averageGolfScore(golfScoreArray, setCount) << endl;

	return 0;
}
#endif

#ifdef GROUND078
//	C++ Primer Plus 5ed 334/Programming Exercises/1
double	harmonicMean(double number1, double number2) {
	return (2.0 * number1 * number2 / (number1 + number2));
}

int	main(void) {
	using std::cout;
	using std::endl;
	using std::cin;

	double	number1;
	double	number2;

	while (cin >> number1 >> number2) {
		if (number1 == 0 || number2 == 0)
			break;
		harmonicMean(number1, number2);
		const double	mean = harmonicMean(number1, number2);
		cout << "harmonic mean: " << mean << endl;
	}

	return 0;
}
#endif

#ifdef GROUND077
//	C++ Primer Plus 5ed 321/LISTING 7.13
#include <cmath>

struct PlaneCoordinate {
	double	x;
	double	y;
};

struct PolarCoordinate {
	double	distance;
	double	angle;
};

void	planeToPolar(PlaneCoordinate& plane, PolarCoordinate& polar) {
	polar.distance = sqrt(plane.x * plane.x + plane.y * plane.y);
	polar.angle = atan2(plane.y, plane.x);
}

void	showPolar(PolarCoordinate& polar) {
	using std::cout;
	using std::endl;

	cout
		<< "Polar Coordinate:" << endl
		<< "	Distance: " << polar.distance << endl
		<< "	Angle: " << polar.angle * 180 / M_PI << endl;
}

int	main(void) {
	using std::cin;
	using std::cout;
	using std::endl;

	PlaneCoordinate	plane;
	PolarCoordinate	polar;

	cout << "Enter Plane Coordinate's x-axis and y-axis: ";
	while (cin >> plane.x >> plane.y) {
		planeToPolar(plane, polar);
		showPolar(polar);
		cout << "Enter Plane Coordinate's x-axis and y-axis: ";
	}

	return 0;
}
#endif

#ifdef GROUND076
//	이중 배열 연습
//
//	결과: 나는 이중 배열이 이중 포인터와 비슷할 거라고 알고 있었는데 이중 포인터가 아니라 배열의 주소값을 저장하는 포인터였다.
void	array2d_function(int array2d[][4]) {
	std::cout << array2d << std::endl;
	std::cout << *array2d << std::endl;
	std::cout << **array2d << std::endl;
}

void	pointerOfArray(int (*array2d)[4]) {
	std::cout << array2d << std::endl;
	std::cout << *array2d << std::endl;
	std::cout << **array2d << std::endl;
}

void	ppointer_function(int** ppointer) {
	std::cout << ppointer << std::endl;
	std::cout << *ppointer << std::endl;
	std::cout << **ppointer << std::endl;
}

int	main(void) {
	int	array2d[3][4] = {
		{ 11, 10, 9, 8, },
		{ 7, 6, 5, 4, },
		{ 3, 2, 1, 0, },
	};

	std::cout << array2d << std::endl;
	std::cout << *array2d << std::endl;
	std::cout << **array2d << std::endl;
	array2d_function(array2d);
// 	ppointer_function(array2d);
//	error: no matching function for call to 'ppointer_function'
//		candidate function not viable: no known conversion from 'int [3][4]' to 'int **' for 1st argument
	pointerOfArray(array2d);

	return 0;
}
#endif

#ifdef GROUND075
//	const 연습2
int	main(void) {
	int			constValue = 10;
	int* const	pointer = &constValue;
	int* const*	constPPointer;

	std::cout << "constValue: " << constValue << std::endl;

	constPPointer = &pointer;	// valid
	**constPPointer = 42;		// valid!!

	std::cout << "constValue: " << constValue << std::endl;

	return 0;
}
#endif

#ifdef GROUND074
//	const 연습1
int	main(void) {
	const int	constValue = 10;
	int*		pointer;
	const int**	constPPointer;

	std::cout << "constValue: " << constValue << std::endl;

// 	constPPointer = &pointer;		// invalid
//	error: assigning to 'const int **' from 'int **' discards qualifiers in nested pointer types
	*constPPointer = &constValue;	// valid
	*pointer = 42;					// valid!!

	std::cout << "constValue: " << constValue << std::endl;

	return 0;
}
#endif

#ifdef GROUND073
//	const type pointer가 가리키는 값이 가리키는 값은 수정이 가능할까?
//
//	결과: 'const Type*' type이라고 해도 Type 안의 pointer가 가리키는 값은 수정이 가능하다!
//		더불어 const type으로 전달받은 parameter도 const가 없는 type으로 explicit type conversion으로 값을 수정하는 것이 가능했다.
struct Type {
	int*	pointer;
};

void	lets_assign_value_to_a_variable_pointed_by_member_variable_of_const_type(const Type* constPointer) {
	*(constPointer->pointer) = 42;
}

void	lets_assign_value_to_a_member_variable_of_const_type_by_force_casting(const Type* constPointer) {
	int	a;
	((Type*)constPointer)->pointer = &a;
	std::cout << constPointer->pointer << std::endl;
}

int	main(void) {
	int		variable = 0;;
	Type	type = { &variable };

	lets_assign_value_to_a_variable_pointed_by_member_variable_of_const_type(&type);
	std::cout << *(type.pointer) << std::endl;
	lets_assign_value_to_a_member_variable_of_const_type_by_force_casting(&type);
	std::cout << type.pointer << std::endl;
	std::cout << *(type.pointer) << std::endl;

	return 0;
}
#endif

#ifdef GROUND072
//	C++ Primer Plus 5ed 278/Programming Exercises/9
#include <fstream>

struct Contributor {
	std::string	name;
	double		contribution;
	static const double	grandBasis;
};

const double	Contributor::grandBasis = 10000.0;

bool	getValidInt_isEOF(std::istream& is, int& variable) {
	double	temp;
	char	ch;

	while (!(is >> temp).eof()) {
		if (is.fail()) {
			std::cout << "Invalid input!" << std::endl;
			is.clear();
			while (is.get(ch) && !std::isspace(ch));
			if (is.eof())
				return true;
		}
		else {
			is.get();
			variable = temp;
			return false;
		}
	}

	return true;
}

bool	getValidDouble_isEOF(std::istream& is, double& variable) {
	char	ch;

	while (!(is >> variable).eof()) {
		if (is.fail()) {
			std::cout << "Invalid input!" << std::endl;
			is.clear();
			while (is.get(ch) && !std::isspace(ch));
			if (is.eof())
				return true;
		}
		else {
			is.get();
			return false;
		}
	}

	return true;
}

int	main(void) {
	int	contributorCount;
	int	petronInCategoryCount;

	std::ifstream	ifs;
	ifs.open(".temp");
	if (getValidInt_isEOF(ifs, contributorCount))
		return 0;
	Contributor*	contributorArray = new Contributor[contributorCount];

	for (int i = 0; i < contributorCount; i += 1) {
		Contributor&	contributor = contributorArray[i];
		if (!getline(ifs, contributor.name))
			return 0;
		if (getValidDouble_isEOF(ifs, contributor.contribution))
			return 0;
	}

	ifs.close();

	std::cout << "Grand Patrons" << std::endl;
	petronInCategoryCount = 0;
	for (int i = 0; i < contributorCount; i += 1) {
		Contributor&	contributor = contributorArray[i];
		if (contributor.contribution >= Contributor::grandBasis) {
			std::cout << contributor.name << ": " << contributor.contribution << std::endl;
			petronInCategoryCount += 1;
		}
	}

	if (petronInCategoryCount == 0)
		std::cout << "none." << std::endl;

	std::cout << "Petrons" << std::endl;
	petronInCategoryCount = 0;
	for (int i = 0; i < contributorCount; i += 1) {
		Contributor&	contributor = contributorArray[i];
		if (contributor.contribution < Contributor::grandBasis) {
			std::cout << contributor.name << ": " << contributor.contribution << std::endl;
			petronInCategoryCount += 1;
		}
	}

	if (petronInCategoryCount == 0)
		std::cout << "none." << std::endl;

	delete [] contributorArray;

	return 0;
}
#endif

#ifdef GROUND071
//	C++ Primer Plus 5ed 278/Programming Exercises/8
#include <fstream>

int	main(void) {
	char	ch;

	std::ifstream	ifs;
	ifs.open(".temp");

	int	characterCount = 0;
	while (ifs.get(ch))
		characterCount += 1;

	ifs.close();

	std::cout << characterCount << " character" << std::endl;

	return 0;
}
#endif

#ifdef GROUND070
//	C++ Primer Plus 5ed 278/Programming Exercises/7
bool	getWord_shouldLoop(std::string& string) {
	if (!(std::cin >> string))
		return false;
	if (string == "q")
		return false;
	return true;
}

bool	isVowel(char ch) {
	switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
	}
	return false;
}

int	main(void) {
	std::string	word;

	std::cout << "Enter words (q to quit):" << std::endl;
	int	wordBeginningWithVowelCount = 0;
	int	wordBeginningWithConsonantCount = 0;
	int	wordBeginningWithOthersCount = 0;
	while (getWord_shouldLoop(word)) {
		const char	firstLetter = word[0];
		if (isalpha(firstLetter)) {
			if (isVowel(firstLetter))
				wordBeginningWithVowelCount += 1;
			else
				wordBeginningWithConsonantCount += 1;
		}
		else
			wordBeginningWithOthersCount += 1;
	}

	if (!std::cin)
		return 0;

	std::cout << wordBeginningWithVowelCount << " words beginning with vowels" << std::endl;
	std::cout << wordBeginningWithConsonantCount << " words beginning with consonants" << std::endl;
	std::cout << wordBeginningWithOthersCount << " others" << std::endl;

	return 0;
}
#endif

#ifdef GROUND069
//	C++ Primer Plus 5ed 277/Programming Exercises/6
struct Contributor {
	std::string	name;
	double		contribution;
	static const double	grandBasis;
};

const double	Contributor::grandBasis = 10000.0;

bool	getValidInt_isEOF(int& variable) {
	double	temp;
	char	ch;

	while (!(std::cin >> temp).eof()) {
		if (std::cin.fail()) {
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			while (std::cin.get(ch) && !std::isspace(ch));
			if (std::cin.eof())
				return true;
		}
		else {
			std::cin.get();
			variable = temp;
			return false;
		}
	}

	return true;
}

bool	getValidDouble_isEOF(double& variable) {
	char	ch;

	while (!(std::cin >> variable).eof()) {
		if (std::cin.fail()) {
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			while (std::cin.get(ch) && !std::isspace(ch));
			if (std::cin.eof())
				return true;
		}
		else {
			std::cin.get();
			return false;
		}
	}

	return true;
}

int	main(void) {
	int	contributorCount;
	int	petronInCategoryCount;

	std::cout << "Enter contributor count: ";
	if (getValidInt_isEOF(contributorCount))
		return 0;
	Contributor*	contributorArray = new Contributor[contributorCount];

	for (int i = 0; i < contributorCount; i += 1) {
		Contributor&	contributor = contributorArray[i];
		std::cout << "Enter contributor #" << i + 1 << " information: " << std::endl;
		std::cout << "name: ";
		if (!getline(std::cin, contributor.name))
			return 0;
		std::cout << "contribution: ";
		if (getValidDouble_isEOF(contributor.contribution))
			return 0;
	}

	std::cout << "Grand Patrons" << std::endl;
	petronInCategoryCount = 0;
	for (int i = 0; i < contributorCount; i += 1) {
		Contributor&	contributor = contributorArray[i];
		if (contributor.contribution >= Contributor::grandBasis) {
			std::cout << contributor.name << ": " << contributor.contribution << std::endl;
			petronInCategoryCount += 1;
		}
	}

	if (petronInCategoryCount == 0)
		std::cout << "none." << std::endl;

	std::cout << "Petrons" << std::endl;
	petronInCategoryCount = 0;
	for (int i = 0; i < contributorCount; i += 1) {
		Contributor&	contributor = contributorArray[i];
		if (contributor.contribution < Contributor::grandBasis) {
			std::cout << contributor.name << ": " << contributor.contribution << std::endl;
			petronInCategoryCount += 1;
		}
	}

	if (petronInCategoryCount == 0)
		std::cout << "none." << std::endl;

	delete [] contributorArray;

	return 0;
}
#endif

#ifdef GROUND068
//	C++ Primer Plus 5ed 277/Programming Exercises/5
const int	tax0 = 5000;
const int	tax1 = 15000;
const int	tax2 = 35000;

bool	getTvarp_isValid(int& tvarp) {
	double	temp;

	std::cout << "Enter income: ";
	if (!(std::cin >> temp))
		return false;
	if (temp < 0)
		return false;

	tvarp = temp;
	return true;
}

int	main(void) {
	int	tvarp;

	while (getTvarp_isValid(tvarp)) {
		int	tax = 0;
		if (tvarp > tax2) {
			tax += (tvarp - tax2) * (20 / 100.0);
			tvarp = tax2;
		}
		if (tvarp > tax1) {
			tax += (tvarp - tax1) * (15 / 100.0);
			tvarp = tax1;
		}
		if (tvarp > tax0) {
			tax += (tvarp - tax0) * (10 / 100.0);
			tvarp = tax0;
		}
		std::cout << "Tax: " << tax << " tvarps" << std::endl;
	}

	if (!std::cin.eof() && std::cin.fail())
		std::cout << "Invalid input!" << std::endl;
	else
		std::cout << "Bye!" << std::endl;

	return 0;
}
#endif

#ifdef GROUND067
//	C++ Primer Plus 5ed 276/Programming Exercises/4
const int	strSize = 80;
const int	bopArray_count = 3;

struct Bop {
	enum Preference {
		preference_preference = -1,
		preference_fullName,
		preference_title,
		preference_nickname,
		preference_count,
	};

	char		property[preference_count][strSize];
	Preference	preference;
};

bool	getCh_shouldLoop(char& ch) {
	return (std::cin >> ch && ch != 'q');
}

int	main(void) {
	const Bop	bopArray[bopArray_count] = {
		{ {"A", ".", "a"}, Bop::preference_fullName},
		{ {"B", "?", "b"}, Bop::preference_title},
		{ {"C", "!", "c"}, Bop::preference_nickname},
	};

	std::cout << "a. display by name	b. display by title" << std::endl;
	std::cout << "c. display by nickname	d. display by preference" << std::endl;
	std::cout << "q. quit" << std::endl;

	std::cout << "Enter your choice: ";
	char	ch;
	while (getCh_shouldLoop(ch)) {
		Bop::Preference	preference;
		switch (ch) {
			case 'a':
				preference = Bop::preference_fullName;
				break;
			case 'b':
				preference = Bop::preference_title;
				break;
			case 'c':
				preference = Bop::preference_nickname;
				break;
			case 'd':
				preference = Bop::preference_preference;
				break;
			default:
				std::cout << "Please enter a a, b, c, d, or q: ";
				continue;
		}
		for (int i = 0; i < bopArray_count; i += 1) {
			const Bop*	bop = &bopArray[i];
			std::cout << bop->property[preference == Bop::preference_preference ? bop->preference : preference] << std::endl;
		}
		std::cout << "Next choice: ";
	}
	std::cout << "Bye!" << std::endl;

	return 0;
}
#endif

#ifdef GROUND066
//	C++ Primer Plus 5ed 276/Programming Exercises/3
int	main(void) {
	std::cout << "Please enter one of the following choices:" << std::endl
		<< "c) carnivore	p)pianist" << std::endl
		<< "t) tree		g)game" << std::endl;

	char	ch;
	while (std::cin >> ch) {
		switch (ch) {
			case 'C':
			case 'c':
				std::cout << "What does carnivore mean?" << std::endl;
				break;
			case 'P':
			case 'p':
				std::cout << "Pianist is gorgeous!" << std::endl;
				break;
			case 'T':
			case 't':
				std::cout << "A maple is a tree." << std::endl;
				break;
			case 'G':
			case 'g':
				std::cout << "What a pity.." << std::endl;
				break;
			default:
				std::cout << "Please enter a c, p, t, or g: ";
		}
	}

	return 0;
}
#endif

#ifdef GROUND065
//	C++ Primer Plus 5ed 276/Programming Exercises/2
const int	donationsCount = 10;

bool	getDonation_isValid(double* donations, int index) {
	return (index < donationsCount
			&& std::cin >> donations[index]);
}

int	main(void) {
	double	donations[donationsCount];

	std::cout << "Enter donation values(non-digit: exit):" << std::endl;

	int	index = 0;
	while (getDonation_isValid(donations, index))
		index += 1;

	double	sum = 0;
	for (int i = 0; i < index; i += 1)
		sum += donations[i];
	const double	average = index == 0 ? 0 : sum / index;

	int	biggerThanAverage_count = 0;
	for (int i = 0; i < index; i += 1)
		if (donations[i] > average)
			biggerThanAverage_count += 1;

	std::cout << "Average of donations: "
		<< average
		<< std::endl;
	std::cout << biggerThanAverage_count
		<< " donations are larger than the average"
		<< std::endl;

	return 0;
}
#endif

#ifdef GROUND064
//	C++ Primer Plus 5ed 276/Programming Exercises/1
int	main(void) {
	char	ch;
	char	outputCh;
	while (std::cin.get(ch)) {
		if (ch == '@')
			break;
		else if (isnumber(ch))
			continue;
		else if (islower(ch))
			outputCh = toupper(ch);
		else if (isupper(ch))
			outputCh = tolower(ch);
		else
			outputCh = ch;

		std::cout << outputCh;
	}

	return 0;
}
#endif

#ifdef GROUND063
//	C++ Primer Plus 5ed 230p/Programming Exercises/9
#include <cstring>	// strcmp()

int	main(void) {
	std::cout << "Enter number of rows: ";
	int	rowCount;
	if (!(std::cin >> rowCount)) {
		std::cout << "Invalid value has input!" << std::endl;
		return 0;
	}

	for (int i = 0; i < rowCount; i += 1) {
		const int	dotCount = rowCount - (i + 1);
		for (int j = 0; j < dotCount; j += 1)
			std::cout << ".";
		const int	starCount = i + 1;
		for (int j = 0; j < starCount; j += 1)
			std::cout << "*";
		std::cout << std::endl;
	}

	return 0;
}
#endif

#ifdef GROUND062
//	C++ Primer Plus 5ed 230p/Programming Exercises/8
#include <cstring>	// strcmp()

int	main(void) {
	std::string	str;
	int	wordCount;

	std::cout << "Enter words (to stop, type the word done):" << std::endl;
	wordCount = 0;
	while (std::cin >> str && str != "done")
		wordCount += 1;
	std::cout << "You entered a total of " << wordCount << " words." << std::endl;

	return 0;
}
#endif

#ifdef GROUND061
//	C++ Primer Plus 5ed 230p/Programming Exercises/7
#include <cstring>	// strcmp()

int	main(void) {
	const int	strMaxCount = 80;
	char	str[strMaxCount];
	int	wordCount;

	std::cout << "Enter words (to stop, type the word done):" << std::endl;
	wordCount = 0;
	while (std::cin >> str && strcmp(str, "done") != 0)
		wordCount += 1;
	std::cout << "You entered a total of " << wordCount << " words." << std::endl;

	return 0;
}
#endif

#ifdef GROUND060
//	C++ Primer Plus 5ed 230p/Programming Exercises/6
struct Car {
	std::string	make;
	int	yearMade;
};

int	main(void) {
	int	carCount;

	std::cout << "How many cars do you wish to catalog? ";
	if (!(std::cin >> carCount)) {
		std::cout << "Invalid value has input!" << std::endl;
		return 0;
	}
	std::cin.ignore();

	Car*	carArray = new Car[carCount];

	for (int i = 0; i < carCount; i += 1) {
		std::cout << "Car #" << i + 1 << ":" << std::endl;
		std::cout << "Please enter the Make: ";
		if (!getline(std::cin, carArray[i].make)) {
			std::cout << "Invalid value has input!" << std::endl;
			return 0;
		}
		std::cout << "Please enter the year made: ";
		if (!(std::cin >> carArray[i].yearMade)) {
			std::cout << "Invalid value has input!" << std::endl;
			return 0;
		}
		std::cin.ignore();
	}

	std::cout << "Here is your collection:" << std::endl;
	for (int i = 0; i < carCount; i += 1)
		std::cout << carArray[i].yearMade << ' ' << carArray[i].make << std::endl;

	delete [] carArray;

	return 0;
}
#endif

#ifdef GROUND059
//	C++ Primer Plus 5ed 230p/Programming Exercises/5
int	main(void) {
	const int	yearCount = 3;
	const int	monthsOfTheYear = 12;

	const char*	monthsStr[monthsOfTheYear] = {
		"January",
		"Fabruary",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};

	int	monthlySales[yearCount][monthsOfTheYear];

	std::cout << "Enter mothly sales for " << yearCount << "years" << std::endl;
	for (int j = 0; j < yearCount; j += 1) {
		std::cout << j + 1 << "year" << std::endl;
		for (int i = 0; i < monthsOfTheYear; i +=1) {
			std::cout << monthsStr[i] << ": ";
			if (!(std::cin >> monthlySales[j][i])) {
				std::cout << "Invalid value has input!" << std::endl;
				return 0;
			}
		}
	}

	int	sumOfYear[yearCount] = { 0 };
	for (int j = 0; j < yearCount; j += 1) {
		for (int i = 0; i < monthsOfTheYear; i +=1) {
			sumOfYear[j] += monthlySales[j][i];
		}
	}

	int	totalSum = 0;
	for (int i = 0; i < yearCount; i +=1)
		totalSum += sumOfYear[i];

	std::cout << "Sum of years: ";
	for (int i = 0; i < yearCount; i += 1)
		std::cout << sumOfYear[i] << ' ';
	std::cout << std::endl;

	std::cout << "Total sum: " << totalSum << std::endl;

	return 0;
}
#endif

#ifdef GROUND058
//	C++ Primer Plus 5ed 229p/Programming Exercises/4
int	main(void) {
	const int	monthsOfTheYear = 12;
	const char*	monthsStr[monthsOfTheYear] = {
		"January",
		"Fabruary",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};
	int	monthlySales[monthsOfTheYear];

	std::cout << "Enter mothly sales of year" << std::endl;
	for (int i = 0; i < monthsOfTheYear; i +=1) {
		std::cout << monthsStr[i] << ": ";
		if (!(std::cin >> monthlySales[i])) {
			std::cout << "Invalid value has input!" << std::endl;
			return 0;
		}
	}

	int	sum = 0;
	for (int i = 0; i < monthsOfTheYear; i +=1) {
		sum += monthlySales[i];
	}

	std::cout << "Sum: " << sum << std::endl;

	return 0;
}
#endif

#ifdef GROUND057
//	C++ Primer Plus 5ed 229p/Programming Exercises/3
int	main(void) {
	const double	initialInvest = 100.0;
	double	investOfDaphne = initialInvest;
	double	investOfCleo = initialInvest;
	int	yearCount;

	yearCount = 0;
	do {
		investOfDaphne += 0.1 * initialInvest;
		investOfCleo *= 1.05;
		yearCount += 1;
	} while (investOfDaphne > investOfCleo);
	std::cout << "The year took to exceed Cleo's invest Daphne's invest: " << yearCount << std::endl;
	std::cout << "Daphne's invest: " << investOfDaphne << std::endl;
	std::cout << "Cleo's invest: " << investOfCleo << std::endl;

	return 0;
}
#endif

#ifdef GROUND056
//	C++ Primer Plus 5ed 229p/Programming Exercises/2
int	main(void) {
	int	inputNumber;
	int	accumulator;

	std::cout << "Enter a int type number: ";
	accumulator = 0;
	while (std::cin >> inputNumber) {
		if (inputNumber == 0)
			break;
		accumulator += inputNumber;
		std::cout << "Cumulative sum: " << accumulator << std::endl;
		std::cout << "Enter a int type number: ";
	}

	if (!std::cin)
		std::cout << "Failed reading number!" << std::endl;
	else
		std::cout << "\'0\' is entered!" << std::endl;

	return 0;
}
#endif

#ifdef GROUND055
//	C++ Primer Plus 5ed 229p/Programming Exercises/1
int	main(void) {
	int	smallNumber;
	int	bigNumber;

	std::cout << "Enter two int type number to calculate the total sum from to: ";

	if (!(std::cin >> smallNumber))
		std::cout << "failed reading number!" << std::cout;
	if (!(std::cin >> bigNumber))
		std::cout << "Failed reading number!" << std::endl;

	if (smallNumber > bigNumber) {
		const int	temp = smallNumber;
		smallNumber = bigNumber;
		bigNumber = temp;
	}

	long	accumulator = 0;
	for (int index = smallNumber; index <= bigNumber; index += 1)
		accumulator += index;

	std::cout << "Total: " << accumulator << std::endl;

	return 0;
}
#endif

#ifdef GROUND054
//	C++ Primer Plus 5ed 229p/Review Questions/6
int	main(void) {
	for (int i = 1; i <= 64; i *= 2)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}
#endif

#ifdef GROUND053
//	C++ Primer Plus 5ed 227p
int	main(void) {
	char	cities[25][5] = {
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"San Gribble",
		"Gribble Vista",
	};

	for (int i = 0; i < 5; i += 1) {
		std::cout << cities[i] << std::endl;
	}

	return 0;
}
#endif

#ifdef GROUND052
//	C++ Primer Plus 5ed 218p/listing 5.18
int	main(void) {
	int	ch;
	int	count;

	count = 0;
	ch = std::cin.get();
	while (std::cin.fail() == false) {
		std::cout << char(ch);
		count += 1;
		ch = std::cin.get();
	}
	std::cout << std::endl;
	std::cout << count << " characters read" << std::endl;

	return 0;
}
#endif

#ifdef GROUND051
//	C++ Primer Plus 5ed 214p/listing 5.16
//	textin1.cpp
int	main(void) {
	std::cout << "Enter character; Enter # to quit: " << std::endl;;
	char	ch;
	int	count = 0;
	std::cin >> ch;
	while (ch != '#') {
		std::cout << ch;
		count += 1;
		std::cin >> ch;
	}
	std::cout << std::endl;
	std::cout << "count: " << count << std::endl;

	return 0;
}
#endif

#ifdef GROUND050
//	C++ Primer Plus 5ed 214p/listing 5.16
//	textin1.cpp
int	main(void) {
	std::cout << "Enter character; Enter # to quit: " << std::endl;;
	char	ch;
	int	count = 0;
	while (true) {
		std::cin >> ch;
		if (ch == '#') break;
		std::cout << ch;
		count += 1;
	}
	std::cout << std::endl;
	std::cout << "count: " << count << std::endl;

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
//		Default	default1;
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
#include <iomanip>

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
#include <cassert>	// assert()

//	#define NDEBUG

int	main(int argc, char **argv) {
	assert(argc != 1);
	(void)argv;

	return 0;
}
#endif
