//#include "LMI.hpp"
//
//using std::cout;
//using std::endl;

//  다이아몬드 상속에서 base class는 value로 저장될까 reference로 저장될까?

/*  template
#ifdef playground163
#include <iostream>

int main(void) {

  return 0;
}
#endif

*/

#define playground165

#ifdef playground165
// char -1 to unsigned int
#include <iostream>

int main(void) {
  char a = -1;
  std::cout << "(int)(unsigned char)a : " << (int)(unsigned char)a << std::endl;

  return 0;
}
#endif

#ifdef playground164
// use enum
#include <iostream>

enum My_enum
{
  red,
  green,
  blue,
  count,
};

int main(void) {
  My_enum my_enum = My_enum::red;

  std::cout << "My_enum::red : " << My_enum::red << std::endl;
  std::cout << "My_enum::green : " << My_enum::green << std::endl;
  std::cout << "My_enum::blue : " << My_enum::blue << std::endl;
  std::cout << "My_enum::count : " << My_enum::count << std::endl;

  std::cout << "red : " << red << std::endl;

  return 0;
}
#endif

#ifdef playground163
// get array size
#include <iostream>

int my_array[4];

int main(void) {
  int my_array[4];

  std::cout << "sizeof(my_array) : " << sizeof(my_array) << std::endl;

  return 0;
}
#endif

#ifdef playground162
// check the syntax of member initializer list
#include <iostream>

class My_class
{
public :
  int variable1;
  int variable2;
  int variable3;
  int variable4;

public :
  My_class(void)
  : variable1(4)
  , variable2(3)
  , variable3(2)
  , variable4(1)
  { };
};

int main(void)
{
  My_class my_class = My_class();

  std::cout << "start" << std::endl;
  std::cout << my_class.variable1 << std::endl;
  std::cout << my_class.variable2 << std::endl;
  std::cout << my_class.variable3 << std::endl;
  std::cout << my_class.variable4 << std::endl;
  std::cout << "end" << std::endl;

  return 0;
}
#endif

#ifdef GROUND161
template <typename T>
class Test {
private:
    T   value_;

public:
    const T& value() const;
};  // class Test

template <typename T>
void hello(const Test<T>& test) {
    cout << "hello: " << test.value() << endl;
}

int main(void) {
    Test<int> test;

//      test.hello();
//      이렇게는 호출할 수 없다.
//      non-member function은 반드시 인자를 argument list로 전달받아야 한다.
    hello(test);

    return 0;
}
#endif

#ifdef GROUND160
template <typename T>
class Test {
private:
    T   value;

public:
    void hello() const;
};  // class Test

template <typename T>
void Test<T>::hello() const {
    cout << "hello: " << this->value << endl;
}

int main(void) {
    Test<int> test;

    test.hello();
//      hello(test);
//      이렇게는 호출할 수 없다.
//      멤버 함수는 반드시 instance 객체가 invoke해야 한다.

    return 0;
}
#endif

#ifdef GROUND159
void test(std::size_t) {
    cout << "first function" << endl;
}

template <typename T>
void test(...) {
    cout << "general template function" << endl;
}

template <typename T>
void test(typename std::enable_if<!std::is_integral<T>::value, T>::type) {
    cout << "second function" << endl;
}

int main(void) {
    test<int>(1.0);

    return 0;
}
#endif

#ifdef GROUND158
template <class T>
void do_stuff(...) {
    cout << "general do_stuff" << endl;
}

template <class T>
void do_stuff(typename std::enable_if<std::is_integral<T>::value>::type* = 0) {
    cout << "integral do_stuff" << endl;
}

//  error: default template arguments for a function template are a C++11 extension [-Werror,-Wc++11-extensions] 
//  template <class T, typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr>
//  void do_stuff(T& t) {
//      cout << "do_stuff integral" << endl;
//  }

int main(void) {
    do_stuff<int>(NULL);
    do_stuff<double>();

    return 0;
}
#endif

#ifdef GROUND157
struct SomeStructure {
  typedef int foo;
};

template <typename T>
void has_foo_function(typename T::foo) {}  // Definition #1

template <typename T>
void has_foo_function(T) {}  // Definition #2

int main() {
  has_foo_function<SomeStructure>(10);  // Call #1.
  has_foo_function<int>(10);   // Call #2. Without error (even though there is no int::foo)
                // thanks to SFINAE.
}
#endif

#ifdef GROUND156
//  test SFINAE

struct HaveFoo {
    typedef int foo;
};  // struct HaveFoo

struct FooAsMemberVariable {
    int foo;
};  // struct FooAsMemberVariable



template <typename T>
struct has_foo {
    typedef char TrueType[1];
    typedef char FalseType[2];

    typedef void* value_type;

    // general test() template
    template <typename U>
    static FalseType& test(...) {}

    // test() template when U::foo is member type
    template <typename U>
    static TrueType& test(typename std::__void_t<typename U::foo>::type*) {}

    static const bool value = sizeof(test<T>(NULL)) == sizeof(TrueType);
};  // struct has_foo



template <typename T>
void has_foo_function(typename T::foo) {
    cout << "yes have" << endl;
}

template <typename T>
void has_foo_function(...) {
    cout << "dont have" << endl;
}



int main(void) {
    cout << has_foo<HaveFoo>::value << endl;
    cout << has_foo<int>::value << endl;
    cout << has_foo<FooAsMemberVariable>::value << endl;

    has_foo_function<HaveFoo>(10);
    has_foo_function<int>(10);
    has_foo_function<FooAsMemberVariable>(10);

    return 0;
}
#endif

#ifdef GROUND155
template <typename T>
void swap(T& lhs, T& rhs);

template <typename T>
void swap(T lhs[], T rhs[], int count);

int main(void) {
    int int1 = 4;
    int int2 = 2;
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;
    swap(int1, int2);
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;
    cout << endl;

    double double1 = 4.1;
    double double2 = 2.1;
    cout << "double1: " << double1 << endl;
    cout << "double2: " << double2 << endl;
    swap(double1, double2);
    cout << "double1: " << double1 << endl;
    cout << "double2: " << double2 << endl;
    cout << endl;

    int intArray1[] = { 4, 2 };
    int intArray2[] = { 2, 4 };
    cout << "int1Array: " << intArray1[0] << intArray1[1] << endl;
    cout << "intArray2: " << intArray2[0] << intArray2[1] << endl;
    swap(intArray1, intArray2, sizeof(intArray1) / sizeof(int));
    cout << "int1Array: " << intArray1[0] << intArray1[1] << endl;
    cout << "intArray2: " << intArray2[0] << intArray2[1] << endl;
    cout << endl;

    double doubleArray1[] = { 4.1, 2.1 };
    double doubleArray2[] = { 2.2, 4.2 };
    cout << "double1Array: " << doubleArray1[0] << doubleArray1[1] << endl;
    cout << "doubleArray2: " << doubleArray2[0] << doubleArray2[1] << endl;
    swap(doubleArray1, doubleArray2, sizeof(doubleArray1) / sizeof(double));
    cout << "double1Array: " << doubleArray1[0] << doubleArray1[1] << endl;
    cout << "doubleArray2: " << doubleArray2[0] << doubleArray2[1] << endl;
    cout << endl;

    return 0;
}

template <typename T>
void swap(T& lhs, T& rhs) {
    cout << "void swap(T& lhs, T& rhs)" << endl;

    T temp;
    temp = lhs;
    lhs = rhs;
    rhs = temp;
}

template <typename T>
void swap(T lhs[], T rhs[], int count) {
    cout << "void swap(T& lhs, T& rhs, int count)" << endl;

    for (int i = 0; i < count; ++i)
        swap(lhs[i], rhs[i]);
}
#endif

#ifdef GROUND154
int main(void) {
    try {
        throw std::domain_error("not open file");
    }
    catch (const std::exception& e) {
        cout << "e.what(): " << e.what() << endl;
    }

    return 0;
}
#endif

#ifdef GROUND153
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[], char* envp[]) {
    (void)argc;
    pid_t pid;

    int pipeFD[2];
    int resultPipeFD[2];

    pipe(pipeFD);
    pipe(resultPipeFD);

    pid = fork();
    if (pid == 0) { // child
        cout << "pid == 0" << endl;
        dup2(resultPipeFD[1], STDOUT_FILENO);
        execve("test", argv, envp);
    }

    wait(NULL);

    char buf[1024];
    ssize_t readByteCount = read(resultPipeFD[0], buf, 1023);
    buf[readByteCount] = '\0';

    cout << "read thing: " << buf << endl;

    return 0;
}
#endif

#ifdef GROUND152
int main(void) {
    std::string string;

    cout << string.capacity() << endl;

    string.reserve(50);

    cout << string.capacity() << endl;

    return 0;
}
#endif

#ifdef GROUND151
struct Giant {
    double array[0x1 << 30];
};

int main(void) {
    Giant* array;

    try {
        array = new Giant[0x1 << 20];
        std::cout << "array: " << array << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "failed: " << e.what() << std::endl;
    }

    return 0;
}
#endif

#ifdef GROUND150

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/event.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

using std::cout;
using std::endl;

int openSocket(const char* ipAddressString, uint16_t portNumber);
void mainLoop(int serverSock);
void addEvent(int sock, int kqueueFD, int16_t filter, void* udata);

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "argc: [" << argc << "]" << endl;
        cout << "usage: " << argv[0] << " <ip address> <port number>" << endl;
        return 0;
    }
    int serverSock = openSocket(argv[1], atoi(argv[2]));

    mainLoop(serverSock);

    return 0;
}

int openSocket(const char* ipAddressString, uint16_t portNumber) {
    int sock = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    uint32_t ipAddress;
    inet_pton(AF_INET, ipAddressString, &ipAddress);

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = ipAddress;
//     address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(portNumber);

    if (bind(sock, (struct sockaddr*) &address, sizeof(address)) != -1)
        cout << "[success bind()]" << endl;
    else
        cout << "[fail bind()]" << endl;

    cout << errno << endl;

    fcntl(sock, F_SETFL, O_NONBLOCK);

    listen(sock, 5);

    return sock;
}

void mainLoop(int serverSock) {
    const int arraySize = 10;
    int queue = kqueue();
    addEvent(queue, serverSock, EVFILT_READ, NULL);
    int eventCount;
    struct kevent eventArray[arraySize];

    while (true) {
        eventCount = kevent(queue, NULL, 0, eventArray, arraySize, NULL);
        for (int i = 0; i < eventCount; ++i) {
            struct kevent& event = eventArray[i];

            int serverSock = event.ident;
            struct sockaddr clientAddress;
            socklen_t clientAddressSize = sizeof(clientAddress);
            int clientSock = accept(serverSock, &clientAddress, &clientAddressSize);
            send(clientSock, "response", strlen("response"), 0);
            close(clientSock);
        }
    }
}

void addEvent(int sock, int kqueueFD, int16_t filter, void* udata) {
    struct kevent event;
    EV_SET(&event, sock, filter, EV_ADD, 0, 0, udata);
    kevent(kqueueFD, &event, 1, NULL, 0, NULL);
}

#endif

#ifdef GROUND149
// print string.max_size()
// let's contain this file to a string and print it

#include <fstream>

int main(void) {
    std::string temp;

    std::cout << temp.max_size() << std::endl;
    std::cout << std::hex << std::showbase << temp.max_size() << std::endl;

    std::ifstream fin("00_playground.cpp");
    if (!fin.is_open()) {
        std::cout << "fail open file!" << std::endl;
        return -1;
    }

    std::string total;
    while (fin >> temp) {
        total += temp + ' ';
    }

    std::cout << total << std::endl;

    return 0;
}
#endif

#ifdef GROUND148
//  map에 같은 key에 value를 넣으면 어떻게 될까?

#include <map>

using std::cin;
using std::cout;
using std::endl;

void printMenu(void);

int main(void) {
    typedef std::map<std::string, std::string> StringMap;

    StringMap map;
    char ch;
    std::string key;
    std::string value;

    printMenu();
    while (cin >> ch && ch != 'q') {
        switch (ch) {
        case 'i':
            cout << "enter key: ";
            cin >> key;
            cout << "enter value: ";
            cin >> value;
            map[key] = value;
            break;
        case 'p':
            for (StringMap::iterator it = map.begin(); it != map.end(); ++it)
                cout << "pair: { key: [" << it->first << "], value: [" << it->second << "] }" << endl;
            break;
        case 'q':
            break;
        default:
            break;
        }

        if (ch == 'q')
            break;

        printMenu();
    }

    cout << "Terminating program" << endl;

    return 0;
}

void printMenu(void) {
    cout << endl;
    cout << "i) insert, p) print, q) quit: ";
}
#endif

#ifdef GROUND147
#include <vector>

int main(void) {
    std::vector<int> v { 1, 2, 3 };
    // vector의 intialier list를 인자로 받는 constructor는 c++11라고 한다.

    std::copy(v.begin(), v.end(), ostream_iterator(std::cout));

    return 0;
}
#endif

#ifdef GROUND146
#include <sys/socket.h>

int main(void) {
    std::cout << MSG_DONTWAIT << std::endl;

    return 0;
}
#endif

#ifdef GROUND145
#include <vector>

//  constainer의 size_type등을 object로부터 사용할 수 있을까?
//
//  결과:
//  안된다 class name을 통해 scope resolution operator를 사용하여 접근해야 한다.
int main(void) {
    std::vector<int> vector;

    std::cout << sizeof vector.size_type << std::endl;

    return 0;
}
#endif

#ifdef GROUND144
int main(void) {
    int* pi = new int[10];

    pi[5] = 42;

    for (int i = 0; i < 10; ++i)
        std::cout << pi[i] << std::endl;

    delete [] pi;
    pi = new int[10];

    for (int i = 0; i < 10; ++i)
        std::cout << pi[i] << std::endl;

    delete [] pi;

    return 0;
}
#endif

#ifdef GROUND143

#include <vector>

int main(void) {
    std::vector<int> vector = std::vector<int>(9);

    std::cout << vector.size() << std::endl;
    std::cout << vector.max_size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    vector.push_back(10);

    std::cout << vector.size() << std::endl;
    std::cout << vector.max_size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    vector.reserve(30);

    std::cout << vector.size() << std::endl;
    std::cout << vector.max_size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    return 0;
}
#endif

#ifdef GROUND142
//  int와 unsigned int의 대소 비교
int main(void) {
    int i = -1;
    unsigned int ui = 1;

    std::cout << (i < ui) << std::endl;

    return 0;
}
#endif

#ifdef GROUND141
//  isnan() test
//  float의 최댓값을 넘는 값을 가지는 double로 float 변수 값을 설정해주면 inf가 될까?
//
//  결과:
//  그렇다.
int main(void) {
    float f = NAN;
    double d = NAN;

    std::cout << f << std::endl;
    std::cout << isnan(f) << std::endl;
    std::cout << isnan(d) << std::endl;

    float f2 = f;

    std::cout << f2 << std::endl;

    double d3 = 1e50;
    float f3 = static_cast<float>(d3);

    std::cout << d3 << std::endl;
    std::cout << f3 << std::endl;

    return 0;
}
#endif

#ifdef GROUND140
//  array를 선언한 후 {}를 사용하여 초기화할 수 있을까?
//
//  결론:
//  error: expected expression
int main(void) {
    int array[5];

    array = { 0 };

    return 0;
}
#endif

#ifdef GROUND139
// array type을 class의 constructor의 initializer list에서 초기화할 수 있을까?
//
// 결론:
// error: array initializer must be an initializer list
class Test {
private:
    int array[5];
public:
    Test(void);

    void describeArray(void) const;
};

Test::Test(void)
: array(5) {
}

void Test::describeArray(void) const {
    for (int i = 0; i < 5; ++i)
        std::cout << this->array[i] << std::endl;
}

int main(void) {
    Test test;

    return 0;
}
#endif

#ifdef GROUND138
//  exercise reference
int main(void) {
    int a = 42;
    const int& ra = a;

    std::cout << ra + ra << std::endl;
    std::cout << ra << std::endl;

    return 0;
}
#endif

#ifdef GROUND137
//  exercise bit-field representation
union Union {
    int intValue;
    struct {
        int first:8;
        int second:8;
        int third:8;
        int fourth:8;
    } Type;
};

int main(void) {
    Union uni = { 0 };
    int x = 257;
    uni.Type.first = x;

    std::cout << uni.intValue << std::endl;

//  int y = 0;
//  x = y / y;
//  std::cout << x << std::endl;
    int* z = NULL;
    std::cout << *z << std::endl;

    return 0;
}
#endif

#ifdef GROUND136
//  exercise pointer to method
using std::cout;
using std::endl;

class Type {
public:
    void method1(void) { cout << "method1" << endl; };
    void method2(void) { cout << "method2" << endl; };
};

int main(void) {
    Type instance;

    instance.method1();
    instance.Type::method1();
//  instance.*&Type::method1();
    (instance.*&Type::method1)();
//  instance.*(&Type::method1)();
    (instance.*(&Type::method1))();

    return 0;
}
#endif

#ifdef GROUND135
//  std::getline(std::istream, std::string);이 '\n'를 discard할까?
int main(void) {
    std::string string = "hi";
    getline(std::cin, string);
    std::cout << "string: " << string << std::endl;
    std::cout << "string.size(): " << string.size() << std::endl;
    std::cout << "std::cin.rdstate(): " << std::cin.rdstate() << std::endl;
    std::cin.clear();
    std::cout << "next character getline(): " << std::cin.get() << std::endl;

    return 0;
}
#endif

#ifdef GROUND134
//  C++ Primer Plus 5ed 1029p
#include <cstdio>

int main(void) {
    char tempName[10] = "hi";
    mkstemp(tempName);

    return 0;
}
#endif

#ifdef GROUND133
//  C++ Primer Plus 5ed 1000p
//  peek()가 get()과 putback()을 호출한다면 peek()을 하고 get()을 하는 algorithm과 get()을 하고 putback()을 하는 algorithm 사이에 유의미한 속도 차이가 발생할 것 같다.
//
//  결과:
//  ```
//  % time ./a.out peek-get 00_playground.cpp > .temp
//  ./a.out peek-get 00_playground.cpp > .temp  0.01s user 0.00s system 91% cpu 0.013 total
//  % time ./a.out get-putback 00_playground.cpp > .temp
//  ./a.out get-putback 00_playground.cpp > .temp  0.01s user 0.00s system 90% cpu 0.013 total
//  ```
//  둘의 걸리는 시간에서 유의미한 차이는 없었다.
//  즉, peek()이 get()과 putback()을 호출하지는 않을 것이다.
#include <fstream>

using std::cin;
using std::cout;

void peekGet(std::ifstream& ifs) {
    int ch;
    char ch2;
    while ((ch = ifs.peek()) != EOF) {
        if (ch == '\n') {
            cout << (char)ch;
            ifs.get();
        }
        else {
            ifs.get(ch2);
            cout << ch2;
        }
    }
}

void getPutback(std::ifstream& ifs) {
    char ch;
    while (ifs.get(ch)) {
        if (ch == '\n') {
            ifs.putback(ch);
            ifs.get();
        }
        else
            cout << ch;
    }
}

int main(int argc, char** argv) {
    if (argc != 3)
        return -1;

    std::ifstream ifs;
    ifs.open(argv[2]);
    if (!ifs.is_open())
        return -1;

    if (strcmp(argv[1], "peek-get") == 0)
        peekGet(ifs);
    else if (strcmp(argv[1], "get-putback") == 0)
        getPutback(ifs);

    ifs.close();

    return 0;
}
#endif

#ifdef GROUND132
//  C++ Primer Plus 5ed 988p
//  let's exercise cin
using std::cin;

int main(void) {
    int number;

    cin.exceptions(std::ios_base::failbit);
    try {
        cin >> number;
        std::cout << number << std::endl;
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    cin.exceptions(std::ios_base::goodbit);
    std::cout << "cin.gcount(): " << cin.gcount() << std::endl;
    if (cin.eof())
        return 0;
    else if (cin.fail())
        cin.clear();
    while (cin.get() != '\n');
    
    cin >> number;
    std::cout << number << std::endl;
    std::cout << "cin.gcount(): " << cin.gcount() << std::endl;
    if (cin.eof())
        return 0;
    else if (cin.fail())
        cin.clear();
    cin.ignore(255, '\n');

    char array[10];
    cin.getline(array, 10);
    std::cout << array << std::endl;
    std::cout << cin.rdstate() << std::endl;
    std::cout << "cin.gcount(): " << cin.gcount() << std::endl;
    if (cin.eof())
        return 0;
    else if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
    }

    cin.get(array, 10);
    std::cout << array << std::endl;
    std::cout << cin.rdstate() << std::endl;
    std::cout << "cin.gcount(): " << cin.gcount() << std::endl;
    if (cin.eof())
        return 0;
    if (cin.peek() != '\n') {
        std::cout << "input was too long" << std::endl;
        while (cin.get() != '\n');
    }

    return 0;
}
#endif

#ifdef GROUND131
//  C++ Primer Plus 5ed 862p
//  let's exercise cout
using std::cout;
using std::endl;

int main(void) {
    char array[11] = "0123456789";
    array[5] = '\0';
    cout.put('A').put('\n').write(array, 10);   // ostream.write() print specified number of character
    cout << std::flush; // flush the buffer. flush is in fact function
    cout << endl;   // flush the buffer and put new line character also
    flush(cout);
    cout << 1111123.0 << endl;
    cout << 111112.3f << endl;
    cout << 11111.23f << endl;
    cout << 0.0001111123f << endl;
    cout << 0.00001111123f << endl;
    cout << std::hex << 15 << std::oct << 15 << std::dec << endl;
    cout << cout.width(10) << endl;
    cout << cout.width(0) << endl;
    cout.width(10);
    cout << cout.width(0) << endl;
    cout.fill('*');
    cout.width(10);
    cout << -1 << endl;
    cout.precision(2);
    cout << 1111123.0 << endl;
    cout << 111112.3f << endl;
    cout << 11111.23f << endl;
    cout << 0.0001111123f << endl;
    cout << 0.00001111123f << endl;
    cout.setf(std::ios_base::showpoint);
    cout << 123.0 << endl;
    cout << 12.3f << endl;
    cout << 1.23f << endl;
    cout << 0.000123f << endl;
    cout << 0.0000123f << endl;
    cout << std::hex;
    cout.setf(std::ios_base::uppercase);
    cout.setf(std::ios_base::showbase);
    cout << true << false << true << endl;
    cout.setf(std::ios_base::boolalpha);
    cout << true << false << endl;
    cout.precision(2);
    cout << 12.3f << endl;

    return 0;
}
#endif

#ifdef GROUND130
//  C++ Primer Plus 5ed 928p
//  let's make function object using multiplies()
#include <vector>
#include <functional>

template <typename T>
class UnaryMultiplies {
private:
    const T t;
public:
    UnaryMultiplies(const T& t): t(t) {};
    T operator()(const T& t) { return std::multiplies<T>()(this->t, t); };
};

int main(void) {
    std::ostream_iterator<int, char> coutIter = std::ostream_iterator<int, char>(std::cout, " ");
    int array[10] = { 5, 1, 7, 2, 9, 10, 2, 7, 4, 0 };

    std::vector<int> v = std::vector<int>(array, array + 10);

    transform(v.begin(), v.end(), coutIter, UnaryMultiplies<int>(5));
    std::cout << std::endl;

    transform(v.begin(), v.end(), coutIter, std::bind1st(std::multiplies<int>(), 5));
    std::cout << std::endl;

    return 0;
}
#endif

#ifdef GROUND129
//  C++ Primer Plus 5ed 920p
//  let's exercise map
#include <map>
#include <iterator>

int main(void) {
    std::map<std::string, std::string> m;

    std::ostream_iterator<std::string, char> coutIter = std::ostream_iterator<std::string, char>(std::cout, " ");
    (void)coutIter;

    std::pair<std::string, std::string> p = std::pair<std::string, std::string>("hi", "their");
    std::cout << "key: " << p.first << ", value: " << p.second << std::endl;

    m.insert(p);
    m.insert(std::pair<std::string, std::string>("nice to", "meet you"));
//  copy(m.begin(), m.end(), coutIter);
    for (std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); ++it)
        std::cout << "key: " << it->first << ", value: " << it->second << std::endl;

    std::multimap<std::string, std::string> multimap;

    multimap.insert(std::pair<std::string, std::string>("hi", "there"));
    multimap.insert(std::pair<std::string, std::string>("hi", "hello"));

    std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> keyPair = multimap.equal_range("hi");

    for (; keyPair.first != keyPair.second; ++keyPair.first)
        std::cout << "key: " << keyPair.first->first << ", value: " << keyPair.first->second << std::endl;

    return 0;
}
#endif

#ifdef GROUND128
//  C++ Primer Plus 5ed 916p
//  let's exercise set
#include <set>
#include <vector>
#include <iterator>

int main(void) {
    int array[10] = { 1, 1, 2, 1, 2, 3, 4, 5, 4, 5 };
    std::vector<int> v = std::vector<int>(array, array + 10);
    std::ostream_iterator<int, char> coutIterator = std::ostream_iterator<int, char>(std::cout, " ");

    std::set<int> s = std::set<int>(v.rbegin(), v.rend());
    copy(s.begin(), s.end(), coutIterator);
    std::cout << std::endl;

    std::multiset<int> ms = std::multiset<int>(v.rbegin(), v.rend());
    copy(ms.begin(), ms.end(), std::ostream_iterator<int, char>(std::cout, " "));
    std::cout << std::endl;

    int array2[5] = { 7, 3, 1, -1, 0 };
    std::set<int> s2 = std::set<int>(array2, array2 + 5);
    set_union(s.begin(), s.end(), s2.begin(), s2.end(), coutIterator);
    std::cout << std::endl;

    std::set<int> s3;
    std::insert_iterator<std::set<int> > s3InsertIterator = std::insert_iterator<std::set<int> >(s3, s3.begin());
    set_union(s.begin(), s.end(), s2.begin(), s2.end(), s3InsertIterator);
    copy(s3.begin(), s3.end(), coutIterator);
    std::cout << std::endl;

    set_intersection(s.begin(), s.end(), s2.begin(), s2.end(), coutIterator);
    std::cout << std::endl;

    set_difference(s.begin(), s.end(), s2.begin(), s2.end(), coutIterator);
    std::cout << std::endl;

    copy(s3.lower_bound(0), s3.upper_bound(4), coutIterator);
    std::cout << std::endl;

    return 0;
}
#endif

#ifdef GROUND127
//  C++ Primer Plus 5ed 903p
//  let's exercise template<typename T> std::back_insert_iterator<T>
#include <vector>
#include <iterator>

int main(void) {
    std::vector<int> v = std::vector<int>(5);
    std::back_insert_iterator<std::vector<int> > bii = std::back_insert_iterator<std::vector<int> >(v);

    int array[5] = { 1, 2, 3, 4, 5 };

    copy(array, array + 5, bii);
    copy(v.begin(), v.end(), std::ostream_iterator<int, char>(std::cout, " "));

    return 0;
}
#endif

#ifdef GROUND126
//  C++ Primer Plus 5ed 901p
//  reverse_iterator는 begin()과 end()이 가리키는 실제 데이터의 주소와는 같지만 type만 다른 것일까?
#include <vector>
#include <iterator>

int main(void) {
    std::vector<int> v = std::vector<int>(5);

    int i = 0;
    for (std::vector<int>::iterator it = v.begin(); it < v.end(); ++it, ++i)
        *it = i;

    copy(v.begin(), v.end(), std::ostream_iterator<int, char>(std::cout, " "));

    for(std::vector<int>::reverse_iterator it = v.rbegin(); it < v.rend(); ++it, ++i)
        *it = i;

    copy(v.begin(), v.end(), std::ostream_iterator<int, char>(std::cout, " "));

    return 0;
}
#endif

#ifdef GROUND125
//  C++ Primer Plus 5ed 900p
//  let's exercise ostream iterator
#include <iterator>

int main(void) {
    std::ostream_iterator<int, char> out_iter = std::ostream_iterator<int, char>(std::cout, " ");

    *out_iter++ = 15;
    *out_iter++ = 1234567890;

    int array[5] = {2, 4, 6, 8, 10 };

    std::copy(array, array + 5, out_iter);
    std::copy(std::istream_iterator<int, char>(std::cin),
            std::istream_iterator<int, char>(),
            std::ostream_iterator<int, char>(std::cout, " "));

    return 0;
}
#endif

#ifdef GROUND124
//  C++ Primer Plus 5ed 878p
//  let's print size methods of vector
#include <vector>

using std::cout;
using std::endl;

int main(void) {
    std::vector<int> v = std::vector<int>();

    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;

    v.push_back(42);

    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;

    v.reserve(42);

    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;

    v.reserve(45);

    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;

    v.push_back(42);

    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;

    return 0;
}
#endif

#ifdef GROUND123
//  C++ Primer Plus 5ed 768p
//  how to use template as template type argument on function template?
using std::cout;
using std::endl;

template <typename T>
class ClassName {
public:
    T t;
};

template <template <typename> class Thing, typename T>
void funcName(Thing<T>& thing, T t) {
    cout << "thing.t: " << thing.t << ", t:" << t << endl;
}

int main(void) {
    ClassName<int> className;
    funcName(className, 42);

    return 0;
}
#endif

#ifdef GROUND122
//  C++ Primer Plus 5ed 865p
//  std::string::find()가 substring을 발견하지 못하면 std::string::npos를 반환한다고 한다. 확인해보자.
using namespace std;

int main(void) {
    string str = string("This is apple.");

    cout << str.find("is", 6) << endl;
    cout << str.npos << endl;

    return 0;
}
#endif

#ifdef GROUND121
//  C++ Primer Plus 5ed 850p
//  const_cast에 잘못된 const type으로 cast하면 exception이 발생할까?
//
//  결과:
//  const type은 runtime으로 추적하지 않기 때문에 실제 type의 const 여부와 관계 없이 cast가 가능하다.
//  cast의 의도가 const를 위한 것이라는 것을 명시하는 용도로 사용하면 될 것 같다.
//  그리고 실제 값이 수정되는 것을 막아준다.
int main(void) {
    const int ci = 42;
    const int* pci = &ci;
    int* pi = const_cast<int*> (pci);

    std::cout << "*pi: " << *pi << std::endl;
    std::cout << "ci: " << ci << std::endl;
    *pi = 21;
    std::cout << "*pi: " << *pi << std::endl;
    std::cout << "ci: " << ci << std::endl;

    int& i = const_cast<int&> (ci);
    i = 21;

    std::cout << "i: " << i << std::endl;
    std::cout << "ci: " << ci << std::endl;

    return 0;
}
#endif

#ifdef GROUND120
//  C++ Primer Plus 5ed 845p
//  typeid(funcName).name()을 하면 어떻게 될까?
//
//  결과:
//  함수의 return type과 argument list에 대한 정보를 담은 문자열을 반환한다.
//  하지만 const나 throw type등의 정보는 이 문자열에 담겨 있지 않은 것 같다.
using std::cout;
using std::endl;

class Type {
private:
    int a;
public:
    const int& getA(void) const { return a; };
};

void myFunc1(void) {
    cout << "In myfunc1" << endl;
}

int myFunc2(int a, int b, Type type) {
    (void)a;
    (void)b;
    (void)type;
    cout << "In myfunc2" << endl;
    return 0;
}

int main(void) {
    const int& (Type::*pt)(void);

    cout << "typeid(myFunc1).name(): " << typeid(myFunc1).name() << endl;
    cout << "typeid(myFunc2).name(): " << typeid(myFunc2).name() << endl;
    cout << "typeid(pt).name(): " << typeid(pt).name() << endl;
    cout << "typeid(myFunc1) == typeid(myFunc2): " << (typeid(myFunc1) == typeid(myFunc2)) << endl;

    return 0;
}
#endif

#ifdef GROUND119
//  C++ Primer Plus 5ed 834p
//  what happen if i don't catch exception?
//
//  result:
//  zsh: abort      ./a.out
void myFunc(void) throw(int) {
    throw 42;
}

int main(void) {
    myFunc();

    return 0;
}
#endif

#ifdef GROUND118
//  C++ Primer Plus 5ed 805p
//  what happen if i call abort()?
//
//  result:
//  zsh: abort      ./a.out
int main(void) {
    abort();

    return 0;
}
#endif

#ifdef GROUND117
//  C++ Primer Plus 5ed 163p
//  placement new로 int array를 할당하면 기존에 존재하던 데이터가 삭제될까?

using std::cout;
using std::endl;

int main(void) {
    int array[1] = { 1 };

    cout << array[0] << endl;

    int* ptr = new int[3];

    cout << ptr[0] << ptr[1] << ptr[2] << endl;

    for (int i = 0; i < 3; ++i)
        ptr[i] = i;

    cout << ptr[0] << ptr[1] << ptr[2] << endl;

    delete [] ptr;

    ptr = new int[3]();

    cout << ptr[0] << ptr[1] << ptr[2] << endl;

    for (int i = 0; i < 3; ++i)
        ptr[i] = i;

    cout << ptr[0] << ptr[1] << ptr[2] << endl;

    delete [] ptr;

    int i = int();

    cout << i << endl;

    return 0;
}
#endif

#ifdef GROUND116
//  C++ Primer Plus 5ed 765p
//  template <typename T, typename U> class className<T1, T2, T2> { ... }; 가 있을 때
//  ClassName<TypeName1, TypeName2>인 object가 위와 같은 partial specialization으로 생성될까?
//
//  결과:
//  아니다, 이것은 책이 잘못됐다.
//  type argument를 3 개 전달받는 tamplate에 대한 partial specialization을 선언하는 경우 이 partial specialization을 사용하는 object를 생성하기 위해서는 type argument를 3개 전달해야 한다.
//  인자를 2 개만 전달한다면 compliler가 아래 코드의 주석과 같은 error를 출력할 수 있다.
using std::cout;
using std::endl;

template <typename T, typename U, typename V/* = char*/>
class Type {
private:
    T t;
    U u;
    V v;
public:
    void describe(void) const;
};

template <typename T, typename U, typename V>
void Type<T, U, V>::describe(void) const {
    cout << this->t << this->u << this->v << endl;
}

template <typename T, typename U>
class Type<T, U, U> {
private:
    T t;
    U u;
    U v;
public:
    void describe(void) const;
};

template <typename T, typename U>
void Type<T, U, U>::describe(void) const {
    cout << this->t << this->u << this->v << endl;
}

int main(void) {
    Type<char, int, double> type1 = Type<char, int, double>();
    Type<int, char, char> type2 = Type<int, char, char>();
//  Type<int, char> type3 = Type<int, char>();
//  error: too few template arguments for class template 'Type'

    type1.describe();
    type2.describe();
//  type3.describe();

    return 0;
}
#endif

#ifdef GROUND115
//  C++ Primer Plus 5ed 381p
//  같은 signature를 갖는 template function의 explicit specialization과 explicit instantiation을 모두 두면 어떤 error가 발생할까?
//
//  결과:
//  둘이 같이 존재하면 제대로 error가 발생한다.
//  자세한 내용은 코드의 주석 참고
using std::cout;
using std::endl;

// MARK:- interface
template <typename T>
void describe(T what);

template <>
void describe<int>(int what);

// template void describe<int>(int what);
// error: explicit instantiation of 'describe<int>' that occurs after an explicit specialization has no effect [-Werror,-Winstantiation-after-specialization]

template void describe<double>(double what);

// MARK:- implementation
// template <>
// void describe<double>(double what);
// error: explicit specialization of 'describe<double>' after instantiation

template <typename T>
void describe(T what) {
    cout << "T: " << what << endl;
}

template <>
void describe<int>(int what) {
    cout << "int: " << what << endl;
}

// template <>
// void describe<double>(double what) {
//  cout << "double: " << what << endl;
// }

// MARK:- main
int main(void) {
    int number1 = 1;
    double number2 = 2.3;

    describe(number1);
    describe(number2);

    return 0;
}
#endif

#ifdef GROUND114
//  C++ Primer Plus 5ed 722p
//  protected derivation을 했을 때 base class의 reference가 가리키는 derived class instance는 virtual method를 어떻게 호출할까?
//
//  결과:
//  derived class의 외부에서는 implicit type cast가 되지 않는다.
//  derived class의 내부에서는 implicit type cast가 된다.
//  하지만 derived class의 내부에서 implicit type cast는 private inheritance일 때도 된다.

using std::cout;
using std::endl;

class BaseClass {
public:
    virtual const BaseClass& print(const BaseClass& baseClass) {
        cout << "BaseClass print is called" << endl;
        return baseClass;
    };
};

class DerivedClass: protected BaseClass {
public:
    void test(void) {
        cout << "DeerivedClass test is called" << endl;
        this->print(*this);
    };
};

int main(void) {
    DerivedClass derivedClass = DerivedClass();
    derivedClass.test();

//  BaseClass& baseClass = derivedClass;    //  00_playground.cpp:31:24: error: cannot cast 'const DerivedClass' to its protected base class 'const BaseClass'

    return 0;
}
#endif

#ifdef GROUND113
//  C++ Primer Plus 5ed 666p
//  derived class에서 virtual 함수를 signature가 다른 함수로 overriede하여 기존 base class의 함수를 hide하면 해당 함수를 호출할 수 있을까?
//  method hiding은 clang++의 -Werror option에 걸린다.
//  하지만 default에서는 warning이나 error를 출력하지 않는다.
//  또한 다른 signature의 함수를 선언함으로써 base class에 있는 같은 이름의 함수는 hide되기 때문에 implicit하게 호출하는 것이 불가능하다.

using std::cout;
using std::endl;

class BaseClass {
public:
    virtual void print(int value) {cout << "BaseClass: " << value << endl; };
};

class DerivedClass: public BaseClass {
public:
    virtual void print(int value, int times) {cout << "DerivedClass: " << value * times << endl; };
};

int main(void) {
    BaseClass instanceOfBaseClass = BaseClass();
    DerivedClass instanceOfDerivedClass = DerivedClass();

    instanceOfBaseClass.print(42);
    instanceOfDerivedClass.print(42, 2);
//  instanceOfDerivedClass.print(42);

    BaseClass& referenceOfBaseClass = instanceOfDerivedClass;
    referenceOfBaseClass.print(42);

    return 0;
}
#endif

#ifdef GROUND112
//  C++ Primer Plus 5ed 663p
//  virtual keyword를 사용하면 class의 size가 virtual method table의 address의 크기만큼 증가할까?
//  증가한다!

using std::cout;
using std::endl;

class DefaultClass {
private:
    int* value;
public:
    int* getValue(void) const { return this->value; };
    void setValue(int* value) { this->value = value; };
};

class BaseClass {
private:
    int value;
    int value2;
public:
    virtual ~BaseClass(void) {};

    int getValue(void) const { return this->value; };
    void setValue(int value) { this->value = value; };
    int getValue2(void) const { return this->value2; };
    void setValue2(int value) { this->value2 = value; };
};

int main(void) {
    DefaultClass instanceOfDefaultClass = DefaultClass();
    BaseClass instanceOfBaseClass = BaseClass();

    cout << "sizeof(instanceOfDefaultClass): " << sizeof(instanceOfDefaultClass) << endl;
    cout << "sizeof(instanceOfBaseClass): " << sizeof(instanceOfBaseClass) << endl;

    return 0;
}
#endif

#ifdef GROUND111
//  C++ Primer Plus 5ed 595p
//  type1 + type2 = type3가 가능하다.
class Type {
private:
    int value;
public:
    Type(int value = 0);

    int getValue(void) const;
    void setValue(int value);

    Type operator+(const Type& rhs) const;
};

Type::Type(int value)
: value(value) {
}

int Type::getValue(void) const {
    return this->value;
}

void Type::setValue(int value) {
    this->value = value;
}

Type Type::operator+(const Type& rhs) const {
    Type result;

    result.setValue(this->getValue() + rhs.getValue());

    return result;
}

int main(void) {
    Type instance1 = Type(10);
    Type instance2 = Type(20);
    Type instance3 = Type(30);

    instance1 + instance2 = instance3;

    return 0;
}
#endif

#ifdef GROUND110
//  C++ Primer Plus 5ed 139p
//  struct possess at least 4 bytes

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

int main(void) {
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
//  C++ Primer Plus 5ed 588p
//  getline() discard '\n'
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

int main(void) {
    getInput1();
    getInput2();
    getInput3();
    getInput4();
    getInput1();

    return 0;
}
#endif

#ifdef GROUND108
//  precedence of '+' operator
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

int main(void) {
    Type a = Type(10);
    Type b = Type(20);
    Type c = Type(30);

    a + b + c;

    return 0;
}
#endif

#ifdef GROUND107
//  conio.h 테스트
#include <conio.h>

int main(void) {
    using std::cout;

    while (true) {
        cout << "input: " << _getch();
    }

    return 0;
}
#endif

#ifdef GROUND106
//  C++ Primer Plus 5ed 489p
//
//  기본적으로는 class declaration에서 private section에 static const double type을 초기화하는 것을 지원하지 않는다.
class Type {
private:
    static const double test = 3.14;
public:
    double getTest(void) { return test; };
};

int main(void) {
    using std::cout;
    using std::endl;

    Type type;
    cout << type.getTest() << endl;

    return 0;
}
#endif

#ifdef GROUND105
//  C++ Primer Plus 5ed 458p
//
//  instance method implementation에서 qualified name으로 private member variable에 접근하기
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

int main(void) {
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
//  C++ Primer Plus 5ed 442p/Programming Exercises/4
#include "06_programming_exercise_9_4.hpp"

int main(void) {
    const double    ar[3] = { 1.1, 4.4, 2.2 };

    SALES::Sales    sales1;
    setSales(sales1, ar, 3);
    showSales(sales1);

    SALES::Sales    sales2;
    setSales(sales2);
    showSales(sales2);

    return 0;
}
#endif

#ifdef GROUND103
//  C++ Primer Plus 5ed 442p/Programming Exercises/3
struct chaff
{
    char    dross[20];
    int     slag;
};

int main(void) {
    using std::cout;
    using std::endl;

    char*   buffer = new char[100];

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
//  C++ Primer Plus 5ed 442p/Programming Exercises/2
void    strcount(const char* str);

int main(void) {
    using std::cin;
    using std::cout;
    using std::string;

    string  input;

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

void    strcount(const char* str)
{
    using std::cout;

    static int  total = 0;
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
//  C++ Primer Plus 5ed 441p/Programming Exercises/1
#include "05_programming_exercise_9_1.hpp"

int main(void) {
    golf    ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    handicap(ann, 42);
    showgolf(ann);

    golf    andy;
    if (setgolf(andy) != 0) {
        showgolf(andy);
        handicap(andy, 42);
        showgolf(andy);
    }

    return 0;
}
#endif

#ifdef GROUND100
//  C++ Primer Plus 5ed 439p/Review Questions/4
int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;

    double  x;

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
//  C++ Primer Plus 5ed 439p/Review Questions/3
int main(void) {
    double  x;

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
//  C++ Primer Plus 5ed 406p
//  함수 안에서 선언된 static variable은 declaration statement가 실행된 후 함수가 호출됐을 때 함수의 실행과 동시에 come into scope할까?
//
//  결과: 항상 declaration statement가 실행된 시점부터 come into scope한다.
using std::cout;
using std::endl;

static int  var = 42;

void    printVar(void);

int main(void) {
    printVar();
    printVar();

    return 0;
}

void    printVar(void) {
    cout << var << endl;
    static int  var = 10;
    cout << var << endl;
    var = 21;
}
#endif

#ifdef GROUND097
//  C++ Primer Plus 5ed 391p/Programming Exercises/7
template <typename T>
T   ShowArray(T arr[], int n);

template <typename T>
T   ShowArray(T* arr[], int n);

struct debts {
    char    name[50];
    double  amount;
};

int main(void) {
    using namespace std;
    int things[6] = { 13, 31, 103, 301, 310, 130 };
    struct  debts mr_E[3] = {
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
T   ShowArray(T arr[], int n) {
    using namespace std;

    T   total = 0.0;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}
template <typename T>
T   ShowArray(T* arr[], int n) {
    using namespace std;

    T   total = 0.0;
    cout << "template B\n";
    for (int i = 0; i < n; i++)
        total += *arr[i];

    return total;
}
#endif

#ifdef GROUND096
//  C++ Primer Plus 5ed 391p/Programming Exercises/6
template <typename T>
T& maxn(T array[], int count) {
    T*  biggest = &array[0];
    for (int i = 1; i < count; ++i)
        if (array[i] > *biggest)
            biggest = &array[i];

    return *biggest;
}

template <>
const char*&    maxn<const char*>(const char* array[], int count);

int main(void) {
    int intArray[6] = { 1, 3, 2, 5, 4, 6 };
    double  doubleArray[4] = { 1.1, 3.3, 4.4, 2.2 };
    const char* strArray[5] = { "hi", "hello", "there", ":DD", "!" };

    std::cout << maxn(intArray, 6) << std::endl;
    std::cout << maxn(doubleArray, 4) << std::endl;
    std::cout << maxn(strArray, 4) << std::endl;

    return 0;
}

template <>
const char*&    maxn<const char*>(const char* array[], int count) {
    const char**    longest = &array[0];
    int longest_count = strlen(*longest);
    int str_count;

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
//  C++ Primer Plus 5ed 391p/Programming Exercises/5
template <typename T>
T&  max5(T array[5]) {
    T*  biggest = &array[0];
    for (int i = 1; i < 5; ++i)
        if (array[i] > *biggest)
            biggest = &array[i];

    return *biggest;
}

int main(void) {
    int intArray[5] = { 0, 4, 3, 2, 1 };
    double doubleArray[5] = { 0.5, 4.4, 3.3, 2.2, 1.1 };

    std::cout << max5(intArray) << std::endl;
    std::cout << max5(doubleArray) << std::endl;

    return 0;
}
#endif

#ifdef GROUND094
//  C++ Primer Plus 5ed 390p/Programming Exercises/4
using namespace std;
#include <cstring>
struct stringy {
    char*   str;
    int ct;
};

void    set(stringy& string, const char* str);
void    show(stringy& string, int count = 1);
void    show(const char* str, int count = 1);

int main(void) {
    stringy beany;
    char    testing[] = "Reality isn't what it used to be.";

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

void    set(stringy& string, const char* str) {
    string.ct = strlen(str);
    string.str = new char[string.ct + 1];
    strcpy(string.str, str);
}

void    show(stringy& string, int count) {
    for (int i = 0; i < count; i += 1)
        cout << string.str << endl;
}

void    show(const char* str, int count) {
    for (int i = 0; i < count; i += 1)
        cout << str << endl;
}
#endif

#ifdef GROUND093
//  C++ Primer Plus 5ed 390p/Programming Exercises/3
void    string_toupper(std::string& string);

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;

    std::string string;

    cout << "Enter a string (q to quit): ";
    while (getline(cin, string) && string != "q") {
        string_toupper(string);
        cout << string << endl;
        cout << "Enter a string (q to quit): ";
    }

    cout << "Bye." << endl;

    return 0;
}

void    string_toupper(std::string& string) {
    for (unsigned long i = 0; i < string.length(); i += 1)
        string[i] = toupper(string[i]);
}
#endif

#ifdef GROUND092
//  C++ Primer Plus 5ed 390p/Programming Exercises/2
struct CandyBar {
    std::string brandName;
    double  weight;
    int calories;
};

void    CandyBar_init(CandyBar& bar,
        const char* brandName = "Millenium Munch",
        double weight = 2.85,
        int calories = 350);

void    CandyBar_describe(const CandyBar& bar);

int main(void) {
    CandyBar    bar;

    CandyBar_init(bar);
    CandyBar_describe(bar);
    CandyBar_init(bar, "nonsan");
    CandyBar_describe(bar);
    CandyBar_init(bar, "nonsan", 4.2);
    CandyBar_describe(bar);

    return 0;
}

void    CandyBar_init(CandyBar& bar, const char* brandName, double weight, int calories) {
    bar.brandName = brandName;
    bar.weight = weight;
    bar.calories = calories;
}

void    CandyBar_describe(const CandyBar& bar) {
    using std::cout;
    using std::endl;

    cout << "candy bar:" << endl;
    cout << "   brandName: " << bar.brandName << endl;
    cout << "   weight: " << bar.weight << endl;
    cout << "   calories: " << bar.calories << endl;
}
#endif

#ifdef GROUND091
//  C++ Primer Plus 5ed 390p/Programming Exercises/1
void    str_print(const char* str, int attr = 0);

int main(void) {
    str_print("hello, world1");
    str_print("hello, world2");
    str_print("hello, world3");
    str_print("hello, world4", -1);

    return 0;
}

void    str_print(const char* str, int attr) {
    using std::cout;
    using std::endl;

    static int  str_print_callCount = 0;

    str_print_callCount += 1;
    if (attr == 0)
        cout << str << endl;
    else
        for (int i = 0; i < str_print_callCount; i += 1)
            cout << str << endl;
}
#endif

#ifdef GROUND090
//  C++ Primer Plus 5ed 390p/Review Questions/7
struct box {
    char    maker[40];
    float   height;
    float   width;
    float   length;
    float   volume;
};

void    boxDescribe(box& box1);
void    boxSetVolume(box& box1);

template <typename T>
T&  larger(T& lhs, T& rhs) {
    return lhs > rhs ? lhs : rhs;
}

template <>
box&    larger<box>(box& lhs, box& rhs);

int main(void) {
    box box1 = {
        "nonsan",
        42,
        10,
        13,
        15,
    };
    box box2 = {
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

void    boxDescribe(box& box1) {
    using std::cout;
    using std::endl;

    cout << "box:" << endl;
    cout << "   maker: " << box1.maker << endl;
    cout << "   height: " << box1.height << endl;
    cout << "   width: " << box1.width << endl;
    cout << "   length: " << box1.length << endl;
    cout << "   volume: " << box1.volume << endl;
}

void    boxSetVolume(box& box1) {
    box1.volume = box1.height * box1.width * box1.length;
}

template <>
box&    larger<box>(box& lhs, box& rhs) {
    return lhs.volume > rhs.volume ? lhs : rhs;
}
#endif

#ifdef GROUND089
//  C++ Primer Plus 5ed 389p/Review Questions/4
struct box {
    char    maker[40];
    float   height;
    float   width;
    float   length;
    float   volume;
};

void    boxDescribe(box& box1);
void    boxSetVolume(box& box1);

int main(void) {
    box box1 = {
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

void    boxDescribe(box& box1) {
    using std::cout;
    using std::endl;

    cout << "box:" << endl;
    cout << "   maker: " << box1.maker << endl;
    cout << "   height: " << box1.height << endl;
    cout << "   width: " << box1.width << endl;
    cout << "   length: " << box1.length << endl;
    cout << "   volume: " << box1.volume << endl;
}

void    boxSetVolume(box& box1) {
    box1.volume = box1.height * box1.width * box1.length;
}
#endif

#ifdef GROUND088
//  C++ Primer Plus 5ed 389p/Review Questions/3
void    iquote(int number);
void    iquote(double number);
void    iquote(std::string string);

int main(void) {
    iquote(42);
    iquote(4.2);
    iquote("42");

    return 0;
}

void    iquote(int number) {
    using std::cout;
    using std::endl;

    cout << '\"' << number << '\"' << endl;
}

void    iquote(double number) {
    using std::cout;
    using std::endl;

    cout << '\"' << number << '\"' << endl;
}

void    iquote(std::string string) {
    using std::cout;
    using std::endl;

    cout << '\"' << string << '\"' << endl;
}
#endif

#ifdef GROUND087
//  C++ Primer Plus 5ed 371p
template <class T>
void swap(T& lhs, T& rhs);

int main(void) {
    using std::cout;
    using std::endl;

    int a = 1;
    int b = 2;
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
    T   temp;

    temp = lhs;
    lhs = rhs;
    rhs = temp;
}
#endif

#ifdef GROUND086
//  C++ Primer Plus 5ed 351p/8.6
using namespace std;
struct sysop {
    char    name[26];
    char    quote[64];
    int used;
};

const sysop&    use(sysop& sysopref);

int main(void) {
    sysop   looper = {
        "Rick \"Fortran\" Looper",
        "I'm a goto kink of guy.",
        0,
    };

    use(looper);
    cout << "Looper: " << looper.used << " use(s)\n";

//  sysop   copycat;
//  copycat = use(looper);
//  copycat = (const sysop&)looper;
    sysop&  copycat = (const sysop&)looper;
    copycat.used = 42;

    cout << "Copycat: " << copycat.used << " use(s)\n";
    return 0;
}

const sysop&    use(sysop& sysopref) {
    cout << sysopref.name << " says:\n";
    cout << sysopref.quote << endl;
    sysopref.used++;
    return sysopref;
}
#endif

#ifdef GROUND085
//  C++ Primer Plus 5ed 336p/Programming Exercises/9
double  calculate(double lhs, double rhs, double (*operation)(double, double)) {
    return operation(lhs, rhs);
}

double  add(double lhs, double rhs) {
    return lhs + rhs;
}

double  sub(double lhs, double rhs) {
    return lhs - rhs;
}

double  mul(double lhs, double rhs) {
    return lhs * rhs;
}

double  div(double lhs, double rhs) {
    return rhs == 0 ? 0 : lhs / rhs;
}

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;

    const int   operationArray_count = 4;

    double  (*operationArray[operationArray_count])(double, double) = {
        add,
        sub,
        mul,
        div,
    };

    double  lhs;
    double  rhs;
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
//  C++ Primer Plus 5ed 335p/Programming Exercises/8
using namespace std;

const int   SLEN = 30;
struct student {
    char    fullname[SLEN];
    char    hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n) {
    int index = 0;
    student*    element = pa;
    while (index < n) {
        cout << "student #" << index + 1 << ": " << endl;
        cout << "   fullname: ";
        cin.getline(element->fullname, SLEN);
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n' && cin);
        }
        cout << "   hobby: ";
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

void    display1(student st) {
    cout << "student:" << endl;
    cout << "   fullname: " << st.fullname << endl;
    cout << "   hobby: " << st.hobby << endl;
}

void    display2(const student * ps) {
    cout << "student:" << endl;
    cout << "   fullname: " << ps->fullname << endl;
    cout << "   hobby: " << ps->hobby << endl;
}

void    display3(const student pa[], int n) {
    int index = 0;
    const student*  element = pa;
    while (index < n) {
        cout << "student #" << index + 1 << ": " << endl;
        cout << "   fullname: " << element->fullname << endl;
        cout << "   hobby: " << element->hobby << endl;
        element += 1;
        index += 1;
    }
}

int main(void) {
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
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
//  C++ Primer Plus 5ed 335p/Programming Exercises/7
const int   Max = 5;

double* fill_array(double* start, double* end) {
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

void    show_array(const double* start, const double* end) {
    using std::cout;
    using std::endl;

    for (int index = 1; start != end; index += 1, start +=1) {
        cout << "Property #" << index << ": $";
        cout << *start << endl;
    }
}

void    revalue(double r, double* start, double* end) {
    for (; start != end; start += 1)
        *start *= r;
}

int main(void) {
    using namespace std;
    double  properties[Max];

    double* end = fill_array(properties, properties + Max);
    show_array(properties, end);
    cout << "Enter rebaluation factor: ";
    double  factor;
    cin >> factor;
    revalue(factor, properties, end);
    show_array(properties, end);
    cout << "Done.\n";
    return 0;
}
#endif

#ifdef GROUND082
//  C++ Primer Plus 5ed 335p/Programming Exercises/6
int Fill_array(double array[], int size) {
    using std::cout;
    using std::endl;
    using std::cin;

    cout << "Enter double values to fill array" << endl;
    int index;
    for (index = 0; index < size && cin >> array[index]; index += 1);

    return index;
}

void    Show_array(double array[], int size) {
    using std::cout;
    using std::endl;

    for (int index = 0; index < size; index += 1)
        cout << "array[" << index << "]: " << array[index] << endl;
}

void    Reverse_array(double array[], int size) {
    for (int lhs = 0, rhs = size - 1; lhs < rhs; lhs += 1, rhs -= 1) {
        double  temp;
        temp = array[lhs];
        array[lhs] = array[rhs];
        array[rhs] = temp;
    }
}

int main(void) {
    const int   arraySize = 10;
    double  array[arraySize];

    const int   arrayCount = Fill_array(array, arraySize);
    Show_array(array, arrayCount);
    Reverse_array(array, arrayCount);
    Show_array(array, arrayCount);
    Reverse_array(array + 1, arrayCount - 2);
    Show_array(array, arrayCount);

    return 0;
}
#endif

#ifdef GROUND081
//  C++ Primer Plus 5ed 334p/Programming Exercises/5
long    getFactorial(int number) {
    if (number > 0)
        return number * getFactorial(number - 1);
    else if (number == 0)
        return 1;
    else
        return -1;
}

int main(void) {
    using std::cout;
    using std::endl;
    using std::cin;

    int number;

    cout << "Enter a number you want to get of factorial: ";
    while (cin >> number)
        cout << "Fatorial: " << getFactorial(number) << endl;

    return 0;
}
#endif

#ifdef GROUND080
//  C++ Primer Plus 5ed 334p/Programming Exercises/3
#include <cstring>

struct Box {
    char    maker[40];
    float   height;
    float   width;
    float   length;
    float   volume;
};

void    Box_describe(Box box) {
    using std::cout;
    using std::endl;

    cout
        << "box.maker: " << box.maker << endl
        << "box.height: " << box.height << endl
        << "box.width: " << box.width << endl
        << "box.length: " << box.length << endl
        << "box.volume: " << box.volume << endl;
}

void    Box_setVolume(Box* box) {
    box->volume = box->height * box->width * box->length;
}

int main(void) {
    using std::cout;
    using std::endl;
    using std::cin;

    Box box;

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
//  C++ Primer Plus 5ed 334p/Programming Exercises/2
int setGolfScoreArray(int golfScoreArray[], int arraySize) {
    using std::cout;
    using std::endl;
    using std::cin;

    double  input;
    int index;

    cout << "Enter up to 10 golf scores:" << endl;
    index = 0;
    while (index < arraySize && cin >> input) {
        golfScoreArray[index] = input;
        index += 1;
    }

    return index;
}

void    describeGolfScoreArray(int golfScoreArray[], int count) {
    using std::cout;
    using std::endl;

    for (int index = 0; index < count; index += 1)
        cout << golfScoreArray[index] << ' ';
    cout << endl;
}

double  averageGolfScore(int golfScoreArray[], int count) {
    int sum = 0;
    for (int index = 0; index < count; index += 1)
        sum += golfScoreArray[index];

    return double(sum) / count;
}

int main(void) {
    using std::cout;
    using std::endl;
    using std::cin;

    const int   scoreArrayCount = 10;
    int golfScoreArray[scoreArrayCount];

    int setCount = setGolfScoreArray(golfScoreArray, scoreArrayCount);
    describeGolfScoreArray(golfScoreArray, setCount);

    cout << averageGolfScore(golfScoreArray, setCount) << endl;

    return 0;
}
#endif

#ifdef GROUND078
//  C++ Primer Plus 5ed 334p/Programming Exercises/1
double  harmonicMean(double number1, double number2) {
    return (2.0 * number1 * number2 / (number1 + number2));
}

int main(void) {
    using std::cout;
    using std::endl;
    using std::cin;

    double  number1;
    double  number2;

    while (cin >> number1 >> number2) {
        if (number1 == 0 || number2 == 0)
            break;
        harmonicMean(number1, number2);
        const double    mean = harmonicMean(number1, number2);
        cout << "harmonic mean: " << mean << endl;
    }

    return 0;
}
#endif

#ifdef GROUND077
//  C++ Primer Plus 5ed 321p/LISTING 7.13
#include <cmath>

struct PlaneCoordinate {
    double  x;
    double  y;
};

struct PolarCoordinate {
    double  distance;
    double  angle;
};

void    planeToPolar(PlaneCoordinate& plane, PolarCoordinate& polar) {
    polar.distance = sqrt(plane.x * plane.x + plane.y * plane.y);
    polar.angle = atan2(plane.y, plane.x);
}

void    showPolar(PolarCoordinate& polar) {
    using std::cout;
    using std::endl;

    cout
        << "Polar Coordinate:" << endl
        << "    Distance: " << polar.distance << endl
        << "    Angle: " << polar.angle * 180 / M_PI << endl;
}

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;

    PlaneCoordinate plane;
    PolarCoordinate polar;

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
//  이중 배열 연습
//
//  결과: 나는 이중 배열이 이중 포인터와 비슷할 거라고 알고 있었는데 이중 포인터가 아니라 배열의 주소값을 저장하는 포인터였다.
void    array2d_function(int array2d[][4]) {
    std::cout << array2d << std::endl;
    std::cout << *array2d << std::endl;
    std::cout << **array2d << std::endl;
}

void    pointerOfArray(int (*array2d)[4]) {
    std::cout << array2d << std::endl;
    std::cout << *array2d << std::endl;
    std::cout << **array2d << std::endl;
}

void    ppointer_function(int** ppointer) {
    std::cout << ppointer << std::endl;
    std::cout << *ppointer << std::endl;
    std::cout << **ppointer << std::endl;
}

int main(void) {
    int array2d[3][4] = {
        { 11, 10, 9, 8, },
        { 7, 6, 5, 4, },
        { 3, 2, 1, 0, },
    };

    std::cout << array2d << std::endl;
    std::cout << *array2d << std::endl;
    std::cout << **array2d << std::endl;
    array2d_function(array2d);
//  ppointer_function(array2d);
//  error: no matching function for call to 'ppointer_function'
//      candidate function not viable: no known conversion from 'int [3][4]' to 'int **' for 1st argument
    pointerOfArray(array2d);

    return 0;
}
#endif

#ifdef GROUND075
//  const 연습2
int main(void) {
    int         constValue = 10;
    int* const  pointer = &constValue;
    int* const* constPPointer;

    std::cout << "constValue: " << constValue << std::endl;

    constPPointer = &pointer;   // valid
    **constPPointer = 42;       // valid!!

    std::cout << "constValue: " << constValue << std::endl;

    return 0;
}
#endif

#ifdef GROUND074
//  const 연습1
int main(void) {
    const int   constValue = 10;
    int*        pointer;
    const int** constPPointer;

    std::cout << "constValue: " << constValue << std::endl;

//  constPPointer = &pointer;       // invalid
//  error: assigning to 'const int **' from 'int **' discards qualifiers in nested pointer types
    *constPPointer = &constValue;   // valid
    *pointer = 42;                  // valid!!

    std::cout << "constValue: " << constValue << std::endl;

    return 0;
}
#endif

#ifdef GROUND073
//  const type pointer가 가리키는 값이 가리키는 값은 수정이 가능할까?
//
//  결과: 'const Type*' type이라고 해도 Type 안의 pointer가 가리키는 값은 수정이 가능하다!
//      더불어 const type으로 전달받은 parameter도 const가 없는 type으로 explicit type conversion으로 값을 수정하는 것이 가능했다.
struct Type {
    int*    pointer;
};

void    lets_assign_value_to_a_variable_pointed_by_member_variable_of_const_type(const Type* constPointer) {
    *(constPointer->pointer) = 42;
}

void    lets_assign_value_to_a_member_variable_of_const_type_by_force_casting(const Type* constPointer) {
    int a;
    ((Type*)constPointer)->pointer = &a;
    std::cout << constPointer->pointer << std::endl;
}

int main(void) {
    int     variable = 0;;
    Type    type = { &variable };

    lets_assign_value_to_a_variable_pointed_by_member_variable_of_const_type(&type);
    std::cout << *(type.pointer) << std::endl;
    lets_assign_value_to_a_member_variable_of_const_type_by_force_casting(&type);
    std::cout << type.pointer << std::endl;
    std::cout << *(type.pointer) << std::endl;

    return 0;
}
#endif

#ifdef GROUND072
//  C++ Primer Plus 5ed 278p/Programming Exercises/9
#include <fstream>

struct Contributor {
    std::string name;
    double      contribution;
    static const double grandBasis;
};

const double    Contributor::grandBasis = 10000.0;

bool    getValidInt_isEOF(std::istream& is, int& variable) {
    double  temp;
    char    ch;

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

bool    getValidDouble_isEOF(std::istream& is, double& variable) {
    char    ch;

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

int main(void) {
    int contributorCount;
    int petronInCategoryCount;

    std::ifstream   ifs;
    ifs.open(".temp");
    if (getValidInt_isEOF(ifs, contributorCount))
        return 0;
    Contributor*    contributorArray = new Contributor[contributorCount];

    for (int i = 0; i < contributorCount; i += 1) {
        Contributor&    contributor = contributorArray[i];
        if (!getline(ifs, contributor.name))
            return 0;
        if (getValidDouble_isEOF(ifs, contributor.contribution))
            return 0;
    }

    ifs.close();

    std::cout << "Grand Patrons" << std::endl;
    petronInCategoryCount = 0;
    for (int i = 0; i < contributorCount; i += 1) {
        Contributor&    contributor = contributorArray[i];
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
        Contributor&    contributor = contributorArray[i];
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
//  C++ Primer Plus 5ed 278p/Programming Exercises/8
#include <fstream>

int main(void) {
    char    ch;

    std::ifstream   ifs;
    ifs.open(".temp");

    int characterCount = 0;
    while (ifs.get(ch))
        characterCount += 1;

    ifs.close();

    std::cout << characterCount << " character" << std::endl;

    return 0;
}
#endif

#ifdef GROUND070
//  C++ Primer Plus 5ed 278p/Programming Exercises/7
bool    getWord_shouldLoop(std::string& string) {
    if (!(std::cin >> string))
        return false;
    if (string == "q")
        return false;
    return true;
}

bool    isVowel(char ch) {
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

int main(void) {
    std::string word;

    std::cout << "Enter words (q to quit):" << std::endl;
    int wordBeginningWithVowelCount = 0;
    int wordBeginningWithConsonantCount = 0;
    int wordBeginningWithOthersCount = 0;
    while (getWord_shouldLoop(word)) {
        const char  firstLetter = word[0];
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
//  C++ Primer Plus 5ed 277p/Programming Exercises/6
struct Contributor {
    std::string name;
    double      contribution;
    static const double grandBasis;
};

const double    Contributor::grandBasis = 10000.0;

bool    getValidInt_isEOF(int& variable) {
    double  temp;
    char    ch;

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

bool    getValidDouble_isEOF(double& variable) {
    char    ch;

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

int main(void) {
    int contributorCount;
    int petronInCategoryCount;

    std::cout << "Enter contributor count: ";
    if (getValidInt_isEOF(contributorCount))
        return 0;
    Contributor*    contributorArray = new Contributor[contributorCount];

    for (int i = 0; i < contributorCount; i += 1) {
        Contributor&    contributor = contributorArray[i];
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
        Contributor&    contributor = contributorArray[i];
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
        Contributor&    contributor = contributorArray[i];
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
//  C++ Primer Plus 5ed 277p/Programming Exercises/5
const int   tax0 = 5000;
const int   tax1 = 15000;
const int   tax2 = 35000;

bool    getTvarp_isValid(int& tvarp) {
    double  temp;

    std::cout << "Enter income: ";
    if (!(std::cin >> temp))
        return false;
    if (temp < 0)
        return false;

    tvarp = temp;
    return true;
}

int main(void) {
    int tvarp;

    while (getTvarp_isValid(tvarp)) {
        int tax = 0;
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
//  C++ Primer Plus 5ed 276p/Programming Exercises/4
const int   strSize = 80;
const int   bopArray_count = 3;

struct Bop {
    enum Preference {
        preference_preference = -1,
        preference_fullName,
        preference_title,
        preference_nickname,
        preference_count,
    };

    char        property[preference_count][strSize];
    Preference  preference;
};

bool    getCh_shouldLoop(char& ch) {
    return (std::cin >> ch && ch != 'q');
}

int main(void) {
    const Bop   bopArray[bopArray_count] = {
        { {"A", ".", "a"}, Bop::preference_fullName},
        { {"B", "?", "b"}, Bop::preference_title},
        { {"C", "!", "c"}, Bop::preference_nickname},
    };

    std::cout << "a. display by name    b. display by title" << std::endl;
    std::cout << "c. display by nickname    d. display by preference" << std::endl;
    std::cout << "q. quit" << std::endl;

    std::cout << "Enter your choice: ";
    char    ch;
    while (getCh_shouldLoop(ch)) {
        Bop::Preference preference;
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
            const Bop*  bop = &bopArray[i];
            std::cout << bop->property[preference == Bop::preference_preference ? bop->preference : preference] << std::endl;
        }
        std::cout << "Next choice: ";
    }
    std::cout << "Bye!" << std::endl;

    return 0;
}
#endif

#ifdef GROUND066
//  C++ Primer Plus 5ed 276p/Programming Exercises/3
int main(void) {
    std::cout << "Please enter one of the following choices:" << std::endl
        << "c) carnivore    p)pianist" << std::endl
        << "t) tree     g)game" << std::endl;

    char    ch;
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
//  C++ Primer Plus 5ed 276p/Programming Exercises/2
const int   donationsCount = 10;

bool    getDonation_isValid(double* donations, int index) {
    return (index < donationsCount
            && std::cin >> donations[index]);
}

int main(void) {
    double  donations[donationsCount];

    std::cout << "Enter donation values(non-digit: exit):" << std::endl;

    int index = 0;
    while (getDonation_isValid(donations, index))
        index += 1;

    double  sum = 0;
    for (int i = 0; i < index; i += 1)
        sum += donations[i];
    const double    average = index == 0 ? 0 : sum / index;

    int biggerThanAverage_count = 0;
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
//  C++ Primer Plus 5ed 276p/Programming Exercises/1
int main(void) {
    char    ch;
    char    outputCh;
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
//  C++ Primer Plus 5ed 230p/Programming Exercises/9
#include <cstring>  // strcmp()

int main(void) {
    std::cout << "Enter number of rows: ";
    int rowCount;
    if (!(std::cin >> rowCount)) {
        std::cout << "Invalid value has input!" << std::endl;
        return 0;
    }

    for (int i = 0; i < rowCount; i += 1) {
        const int   dotCount = rowCount - (i + 1);
        for (int j = 0; j < dotCount; j += 1)
            std::cout << ".";
        const int   starCount = i + 1;
        for (int j = 0; j < starCount; j += 1)
            std::cout << "*";
        std::cout << std::endl;
    }

    return 0;
}
#endif

#ifdef GROUND062
//  C++ Primer Plus 5ed 230p/Programming Exercises/8
#include <cstring>  // strcmp()

int main(void) {
    std::string str;
    int wordCount;

    std::cout << "Enter words (to stop, type the word done):" << std::endl;
    wordCount = 0;
    while (std::cin >> str && str != "done")
        wordCount += 1;
    std::cout << "You entered a total of " << wordCount << " words." << std::endl;

    return 0;
}
#endif

#ifdef GROUND061
//  C++ Primer Plus 5ed 230p/Programming Exercises/7
#include <cstring>  // strcmp()

int main(void) {
    const int   strMaxCount = 80;
    char    str[strMaxCount];
    int wordCount;

    std::cout << "Enter words (to stop, type the word done):" << std::endl;
    wordCount = 0;
    while (std::cin >> str && strcmp(str, "done") != 0)
        wordCount += 1;
    std::cout << "You entered a total of " << wordCount << " words." << std::endl;

    return 0;
}
#endif

#ifdef GROUND060
//  C++ Primer Plus 5ed 230p/Programming Exercises/6
struct Car {
    std::string make;
    int yearMade;
};

int main(void) {
    int carCount;

    std::cout << "How many cars do you wish to catalog? ";
    if (!(std::cin >> carCount)) {
        std::cout << "Invalid value has input!" << std::endl;
        return 0;
    }
    std::cin.ignore();

    Car*    carArray = new Car[carCount];

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
//  C++ Primer Plus 5ed 230p/Programming Exercises/5
int main(void) {
    const int   yearCount = 3;
    const int   monthsOfTheYear = 12;

    const char* monthsStr[monthsOfTheYear] = {
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

    int monthlySales[yearCount][monthsOfTheYear];

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

    int sumOfYear[yearCount] = { 0 };
    for (int j = 0; j < yearCount; j += 1) {
        for (int i = 0; i < monthsOfTheYear; i +=1) {
            sumOfYear[j] += monthlySales[j][i];
        }
    }

    int totalSum = 0;
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
//  C++ Primer Plus 5ed 229p/Programming Exercises/4
int main(void) {
    const int   monthsOfTheYear = 12;
    const char* monthsStr[monthsOfTheYear] = {
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
    int monthlySales[monthsOfTheYear];

    std::cout << "Enter mothly sales of year" << std::endl;
    for (int i = 0; i < monthsOfTheYear; i +=1) {
        std::cout << monthsStr[i] << ": ";
        if (!(std::cin >> monthlySales[i])) {
            std::cout << "Invalid value has input!" << std::endl;
            return 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < monthsOfTheYear; i +=1) {
        sum += monthlySales[i];
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
#endif

#ifdef GROUND057
//  C++ Primer Plus 5ed 229p/Programming Exercises/3
int main(void) {
    const double    initialInvest = 100.0;
    double  investOfDaphne = initialInvest;
    double  investOfCleo = initialInvest;
    int yearCount;

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
//  C++ Primer Plus 5ed 229p/Programming Exercises/2
int main(void) {
    int inputNumber;
    int accumulator;

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
//  C++ Primer Plus 5ed 229p/Programming Exercises/1
int main(void) {
    int smallNumber;
    int bigNumber;

    std::cout << "Enter two int type number to calculate the total sum from to: ";

    if (!(std::cin >> smallNumber))
        std::cout << "failed reading number!" << std::cout;
    if (!(std::cin >> bigNumber))
        std::cout << "Failed reading number!" << std::endl;

    if (smallNumber > bigNumber) {
        const int   temp = smallNumber;
        smallNumber = bigNumber;
        bigNumber = temp;
    }

    long    accumulator = 0;
    for (int index = smallNumber; index <= bigNumber; index += 1)
        accumulator += index;

    std::cout << "Total: " << accumulator << std::endl;

    return 0;
}
#endif

#ifdef GROUND054
//  C++ Primer Plus 5ed 229p/Review Questions/6
int main(void) {
    for (int i = 1; i <= 64; i *= 2)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}
#endif

#ifdef GROUND053
//  C++ Primer Plus 5ed 227p
int main(void) {
    char    cities[25][5] = {
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
//  C++ Primer Plus 5ed 218p/listing 5.18
int main(void) {
    int ch;
    int count;

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
//  C++ Primer Plus 5ed 214p/listing 5.16
//  textin1.cpp
int main(void) {
    std::cout << "Enter character; Enter # to quit: " << std::endl;;
    char    ch;
    int count = 0;
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
//  C++ Primer Plus 5ed 214p/listing 5.16
//  textin1.cpp
int main(void) {
    std::cout << "Enter character; Enter # to quit: " << std::endl;;
    char    ch;
    int count = 0;
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
//  C++ Primer Plus 5ed 175p/6
struct CandyBar {
    std::string name;
    double  weight;
    int calorie;
};

void    CandyBarDescribe(CandyBar* candyBar, int index) {
    std::cout << index << ". Name: " << candyBar->name << std::endl;
    std::cout << index << ". Weight: " << candyBar->weight << std::endl;
    std::cout << index << ". Calories: " << candyBar->calorie << std::endl;
}

int main(void) {
    CandyBar*   candyBars = new CandyBar[3];

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
//  C++ Primer Plus 5ed 175p/7
struct Pizza {
    std::string nameOfCompany;
    double  diameter;
    double  weight;
};

int main(void) {
    Pizza*  pizza = new Pizza;

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
//  C++ Primer Plus 5ed 175p/7
struct Pizza {
    std::string nameOfCompany;
    double  diameter;
    double  weight;
};

int main(void) {
    Pizza   pizza;

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
//  C++ Primer Plus 5ed 175p/6
struct CandyBar {
    std::string name;
    double  weight;
    int calorie;
};

void    CandyBarDescribe(CandyBar* candyBar, int index) {
    std::cout << index << ". Name: " << candyBar->name << std::endl;
    std::cout << index << ". Weight: " << candyBar->weight << std::endl;
    std::cout << index << ". Calories: " << candyBar->calorie << std::endl;
}

int main(void) {
    CandyBar    candyBars[3] = {
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
//  C++ Primer Plus 5ed 175p/5
struct CandyBar {
    std::string name;
    double  weight;
    int calorie;
};

int main(void) {
    CandyBar    snack = {"Mocha Munch", 2.3, 350};

    std::cout << "Name: " << snack.name << std::endl;
    std::cout << "Weight: " << snack.weight << std::endl;
    std::cout << "Calories: " << snack.calorie << std::endl;

    return 0;
}
#endif

#ifdef GROUND044
//  C++ Primer Plus 5ed 174p/4
int main(void) {
    std::string firstName;
    std::string lastName;
    std::string name;

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
//  C++ Primer Plus 5ed 174p/3
int main(void) {
    const int   lineMaxCount = 80;
    char    firstName[lineMaxCount];
    char    lastName[lineMaxCount];
    char    name[lineMaxCount];
    char*   namePointer;

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
//  C++ Primer Plus 5ed 174p/2
int main(void) {
    std::string name;
    std::string dessert;

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
//  C++ Primer Plus 5ed 174p/1
enum Grade {A, B, C};

int main(void) {
    const int   maxSize = 80;
    char    firstName[maxSize];
    char    lastName[maxSize];
    Grade   grade;
    int age;

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
//  stack과 heap의 주소를 출력해보자.
//
//  결과: stack의 주소값은 점점 작아지고 heap의 주소값은 점점 커진다.
//      - code와 data를 담을 영역과 stack을 담을 영역을 먼저 결정하여 끝과 끝에 위치시켜두고 그 사이에서 heap이 채워져나가도록 만드는 것이 좋을 것이다.
int main(void) {
    int a;
    int b;
    int*    c = new int;
    int*    d = new int;

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
//  사용하지 않는 함수가 완성된 프로그램의 크기에 영향을 미칠까?
//  main 용량: 16834
//  hello 추가 용량: 40258
//  world 추가 용량: 30306
//
//  결과: 사용하지 않는 함수가 추가되어도 컴파일러는 이를 알아서 최적화하지 못하고 완성된 프로그램에 추가한다.
//      - 아마 최적화 옵션으로 결과가 달라질 수도 있을 것 같다.
void    world(void) {
    std::cout << "world" << std::endl;
}

void    hello(void) {
    std::cout << "hello" << std::endl;
}

int main(void) {
    return 0;
}
#endif

#ifdef GROUND038
//  float, double, long double의 size를 출력해보자.
int main(void) {
    std::cout << "sizeof(float): " << sizeof(float) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(long double): " << sizeof(long double) << std::endl;

    return 0;
}
#endif

#ifdef GROUND037
//  반환값만 달라도 overloading이 될까?
//  error: functions that differ only in their return type cannot be overloaded
int returnValue(void) {
    return 42;
}

double  returnValue(void) {
    return 4.2;
}
int main(void) {
    int x = returnValue();

    return 0;
}
#endif

#ifdef GROUND036
//  c++에서 private access modifier는 접근 범위를 instance로 제한하는 것이 아니라 class name scope으로 제한된다.
class   Type {
private:
    int value;
public:
    Type(void) { this->value = 42; };
    Type(const Type& type);

    int getValue(void) { return this->value; };
    void    setValue(int newValue) { this->value = newValue; };
};

Type::Type(const Type& type) {
    this->value = type.value;
}

int main(void) {
    Type type1;
    type1.setValue(21);
    Type type2 = Type(type1);
    std::cout << "type2.value: " << type2.getValue() << std::endl;

    return 0;
}
#endif

#ifdef GROUND035
//  and, or, not practice
int main(void) {
    bool    a = true;
    bool    b = false;

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
//  https://www.geeksforgeeks.org/default-methods-in-c-with-examples/
//  Default Methods in C++ with Examples
//  Type    type;
//      같다 Type   type = Type();
//  궁금: constructor에서 member variable에게 assign operator를 사용하면 member variable의 constructor가 두 번 호출될까?
//      default constructor도 호출되고 추가적인 constructor도 호출되고 copy assignment opertor도 호출되고 destructor도 호출된다.
//      : property(10)을 사용하면 parameterized constructor 하나만 호출된다.
//  Property의 default constructor가 없는데 Type이 Property를 member variable로 가지고 constructor에서 명시적으로 initialization을 하지 않으면 어떻게 될까?
//      error: constructor for 'Type' must explicitly initialize the member 'property' which does not have a default constructor
//  new keyword는 heap영역에 메모리 공간을 할당할 뿐만 아니라 default constructor도 호출한다. 
class   Super {
private:
    static int  referenceCount;
public:
    int value;

    Super(void) { value = ++referenceCount; std::cout << "Super.defaultConstructor: " << referenceCount << std::endl; };
    Super(const Super& super) { this->value = super.value; std::cout << "Super.copyConstructor" << std::endl; };
    //  Called when an instance is passed as arguments to a constructor or returned
    ~Super(void) { std::cout << "Super.destructor" << std::endl; };

    Super&  operator=(const Super& rhs) { this->value = rhs.value; std::cout << "super.copyAssignmentOperator" << std::endl; return *this; };
};

int Super::referenceCount = 0;

class   Property {
private:
    static int  referenceCount;
public:
    int value;

    Property(void) { value = ++referenceCount; std::cout << "Property.defaultConstructor: " << referenceCount << std::endl; };
    Property(int value) { this->value = value; };
    Property(const Property& property) { this->value = property.value; std::cout << "Property.copyConstructor" << std::endl; };
    ~Property(void) { std::cout << "Property.destructor" << std::endl; };
    Property&   operator=(const Property& rhs) { this->value = rhs.value; std::cout << "property.copyAssignmentOperator" << std::endl; return *this; };
};

int Property::referenceCount = 0;

class   Default: public Super {
private:
    Property    property;
//  public:
//      Default(void);
//      Default(const Default& type);
//      ~Default(void);
//  
//      Default&    operator=(const Default& rhs);
};

//  Default::Default(void) {
//      super.defaultConstructor();
//      this->property.defaultConstructor();
//  }
//  
//  Default::Default(const Default& type) {
//      super.copyConstructor(type);
//      this->property.copyConstructor(type.property);
//  }
//  
//  Default::~Default(void) {
//      this->property.destructor();
//      super.destructor();
//  }
//  
//  Default&    Default::operator=(const Default& rhs) {
//      super.copyAssignmentOperator(rhs);
//      this->property.copyAssignmentOperator(rhs.property);
//  
//      return *this;
//  }

class   Type: public Super {
private:
    Property    property;
public:
    Type(void);
    Type(Property& property);
    Type(const Type& type);
    ~Type(void);

    Type&   operator=(const Type& rhs);
};

Type::Type(void) {
    //  super.defaultConstructor
    //  this->property.defaultConstructor
//      this->property = Property(10);
    std::cout << "Type.defaultConstructor" << std::endl;
}

Type::Type(Property& property): property(property) {
    //  super.defaultConstructor
    //  property.copyConstructor
    std::cout << "Type.parameterizedConstructor" << std::endl;
}

Type::Type(const Type& type) {
    (void)type;
    //  super.defaultConstructor
    //  this->property.defaultConstructor
    std::cout << "Type.copyConstructor" << std::endl;
}

Type::~Type(void) {
    std::cout << "Type.destructor" << std::endl;
    //  this->property.destructor
    //  super.destructor
}

//  선언과 할당을 동시에 하는 경우를 제외한 모든 할당 시 호출
Type&   Type::operator=(const Type& rhs) {
    (void)rhs;
    std::cout << "type.copyAssignmentOperator" << std::endl;

    return *this;
}

int main(void) {
//      Default default1;
//      Default default1 = Default();
//      Default default2 = Default(default1);
//      default2 = default1;

//      Type    type1 = Type();
//      Type    type2 = Type(type1);
//      type2 = type1;

//      Type*   type1 = new Type[2];
//      delete [] type1;

//      Property    property = Property(10);
//      Type    type = Type(property);

    return 0;
}
#endif

#ifdef GROUND033
//  namespace 안에서 'static const int' type 변수를 선언하고 초기화할 수 있을까?
//  가능하다, 'static' keyword를 빼도 잘 작동한다.
namespace name {
    int value = 42;
}

int main(void) {
    std::cout << "name::value: " << name::value << std::endl;
    return 0;
}
#endif

#ifdef GROUND032
//  인자의 type에 reference를 사용하면 Type 전후의 const는 주소가 가리키는 object가 변하지 않음을 의미한다.
class Object {
private:
public:
    int _value;
};

void    function(Object &object) {
    object._value = 1;
    std::cout << "object._value: " << object._value << std::endl;
}

void    constFunction(const Object &object) {
    std::cout << "object._value: " << object._value << std::endl;
}

int main(void) {
    Object  object;
    constFunction(object);
    function(object);

    return 0;
}
#endif

#ifdef GROUND031
//  practice string
int main(void) {
    std::string str = "hello, world!";

    std::cout << "str: " << str << std::endl;
    str.erase(0, 1);
    std::cout << "str: " << str << std::endl;
    return 0;
}
#endif

#ifdef GROUND031
//  global에 선언된 type은 '::'로 global type에 접근 가능하기 때문에 namespace 내부에서 같은 identifier를 사용하여 namespace를 정의할 수 있다.
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
//  namespace의 identifier로 keyword를 사용할 수 없다. 
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
//  궁금: const member를 constructor에서 assign하면 어떤 에러가 뜰까?
//  결과: "error: constructor for 'Object' must explicitly initialize the const member '_constant'"
//  "error: cannot assign to non-static data member '_constant' with const-qualified type 'const int'"
class Object {
public:
    int const   _constant;

    Object(int constant = 42);
};



Object::Object(int constant) {
    this->_constant = constant; 
    std::cout << "this->_constant: " << this->_constant << std::endl;
}



int main(void) {
    Object  object = Object(10);

    std::cout << "object._constant: " << object._constant << std::endl;

    return 0;
}
#endif

#ifdef GROUND028
//  implicit type conversion을 할 때, source type을 인자로 하는 target type constructor와, source type의 conversion operator to target type이 모두 존재하면 ambiguous error가 발생할까?
//  결과: error: conversion from 'Source' to 'Target' is ambiguous
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

void    Target::nothing(void) {}



class Source {
public:
    operator Target(void) const;
};

Source::operator Target(void) const {
    std::cout << "operator Target(void) is called" << std::endl;

    return Target();
}



int main(void) {
    Target  target = Source();

    target.nothing();

    return 0;
}
#endif

#ifdef GROUND027
//  Let's test cin
bool    getLine(std::string &line) {
    std::cout << "Input a word: ";
    std::getline(std::cin, line);

    return !std::cin.eof();
}

int main(void) {
    std::string line;

    while (getLine(line))
        std::cout << "You input [" << line << "]" << std::endl;

    return 0;
}
#endif

#ifdef GROUND026
//  궁금: std::setbase 의 return type 은 무엇일까?
//
//  결과:
//  실제 iomanip 파일을 열어보니 std::setbase(int)는 단순히 std::__iom_t3를 반환하는 inline 함수였다.
//  뜨는 에러로 확인해보아도 type은 std::__iom_t3이었다. 왜 cplusplus.com 등의 사이트에서는 /*unspecified*/ 라고 했을까?
//  아마 실제 implementation 은 'std::__iom_t3' 로 되어 있었지만 interface로는 /*unspecified*/이기 때문일 것 같다.
//  즉 implementation defined일 것 같다.
//  이 용어를 잘 설명한 블로그를 발견했다.
//  - https://m.blog.naver.com/ttagui/10043795874
//  implementation defined 와 unspecified 가 독립적으로 존재하는 개념이었다.
#include <iomanip>

class Object {
};

int main(void) {
    Object  object = Object(std::setbase(16));
    // error: no matching conversion for functional-style cast from 'std::__iom_t3' to 'Object'

    return 0;
}
#endif

#ifdef GROUND025
//  string practice
//
//  결과:
//  str.size() 는 13 이며, 실제 차지하는 공간은 16 byte 이기 때문에 npos 와 max_size() 가 16 만큼 차이가 난다.
int main(void) {
    std::string str = std::string("hello, world!");
    std::cout << "value of str: [" << str << "]" << std::endl;
    std::cout << "size of str: [" << str.size() << "]" << std::endl;
    std::cout << "max_size of str: [" << str.max_size() << "]" << std::endl;
    std::cout << "npos of string: [" << std::string::npos << "]" << std::endl;

    return 0;
}
#endif

#ifdef GROUND024
//  궁금: 없는 namespace 의 맴버를 선언하고 사용할 수 있을까?
int main(void) {
    int name::first = 42;   // error: use of undeclared identifier 'name'

    return 0;
}
#endif

#ifdef GROUND023
//  궁금: 있는 namespace 의 맴버를 추가 선언하고 사용할 수 있을까?
namespace name {
    int first;
}

int main(void) {
    std::cout << "name::first: " << name::first << std::endl;
    name::first = 42;
    std::cout << "name::first: " << name::first << std::endl;
    int name::second = 1;   // error: definition or redeclaration of 'second' not allowed inside a function

    return 0;
}
#endif

#ifdef GROUND022
//  pointer practice
//
//  결과:
//  Object pointer 는 c 처럼 애매하게 사용할 수 없고, 딱 정해진 방식으로 사용해야 compile 이 진행된다.(& 와 * 를 정확한 위치에 정확한 갯수로 명시해야 한다.)
//  compiler 는 'void (*)(Object *const)' 와 'void (Object::*)() const' 를 다른 type 으로 처리한다.
class Object    {
public:
    int value;

    Object(void);

    void    function(void) const;
};



Object::Object(void): value(0) {
    std::cout << "Object(void) is called" << std::endl;
}

void    Object::function(void) const {
    std::cout << "Object.function() is called" << std::endl;
}



int main(void) {
    Object  object;
    Object  *pObject = &object;
    std::cout << "object.value: " << object.value << std::endl;
    std::cout << "pObject->value: " << pObject->value << std::endl;
    object.function();
    pObject->function();

    int *ptr = &object.value;
    std::cout << "*ptr: " << *ptr << std::endl;
    *ptr = 42;
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << "object.value: " << object.value << std::endl;

    int Object::*pValue;
    pValue = &Object::value;
    std::cout << "object.*pValue = " << object.*pValue << std::endl;
    //  pObject->*pValue

    void    (Object::*f)(void) const;
    f = &Object::function;
    (object.*f)();
    //  (pObject->*f)();

//      void    (*newF)(Object *const);
//      newF = &Object::function;   // error: assigning to 'void (*)(Object *const)' from incompatible type 'void (Object::*)() const'
//      (*newF)(object);

    return 0;
}
#endif

#ifdef GROUND021
//  static member practice
//  static member attribute 는 꼭 'type Object::attr' 로 class declaration 밖에서 선언을 해주어야 한다.
//  그렇지 않으면 Undefined symbol link error 가 발생한다.
//  값은 c 처럼 compiler 가 알아서 초기화해 줄까?
class Object {
private:
    static int  _value;
public:
    static int  getValue(void);
};



int Object::_value;

int Object::getValue(void) {
    return Object::_value;
}



int main(void) {
    std::cout << Object::getValue() << std::endl;

    return 0;
}
#endif

#ifdef GROUND020
//  궁금:
//  어떤 object 를 정의할 때 어떤 변수를 private 으로 정의하여 Object.cpp 로 Object.o 파일을 생성한 후, main.cpp 에서 사용할 때 해당 변수 선언을 public 으로 바꾸고 main.o 파일을 생성할 수 있을까?
//  그렇게 생성된 Object.o 파일과 mainc.o 파일을 link 하여 a.out 파일을 생성할 수 있을까?
//  생성된다면 이 파일이 실행될까?
//  02_main.cpp 로 테스트를 진행했다.
//  private 에 있던 변수를 public 으로 옮기면 당연히 잘 작동할 것 같다.
//  public 에 선언된 변수를 private 으로 옮기면 문제가 발생할 수 있을까?
//  가령 'Object(Object const &object) {}' 이런 복사 생성자에서 인자인 object 에 직접 접근 가능한 public 상태로 Object class 를 컴파일하고 main 은 private 으로 바꿔서 컴파일하면 어떨까?
//  아니다 이것은 어리석은 생각이다.
//  오류가 나든 나지 않든 크게 얻을 것이 없는 생각인 것 같다.
//  실제 저런 식으로 프로그램을 실행시킬 일은 없기 때문이다.
//  보안상으로도 private 으로 구현된 object 의 변수를 public 으로 수정하여 강제로 내부 변수에 직접 접근하는 방식을 제외하고는 큰 의미가 없다.
//  반대로 public 을 private 으로 바꾼다면 오히려 접근 권한을 더 줄일 뿐이다.
//
//  결과:
//  private 으로 선언된 attribute 를 public 으로 변경하여 main.o 를 생성하고 미리 컴파일해둔 Object.o 와 link 를 하니 해당 attribute 에 직접 접근하는 코드가 에러 없이 실행되는 것을 볼 수 있었다.
#endif

#ifdef GROUND019
//  궁금:
//  member variable 이 primitive type 이라면 초기화를 하지 않지만, instance 라면 default constructor 를 호출하지 않을까?
//
//  결과:
//  Container 의 default constructor 를 호출하기만 하고 member variable 인 content 의 값을 초기화하지 않았지만 content 의 type 이 object type 이기 때문에 default constructor 가 호출되었다.
//  그럼 structure 는 어떨까? 나중에 structure 를 사용할 일이 있으면 자세히 알아보도록 하자.
class   Content {
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



class   Container {
private:
    Content content;
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



int main(void) {
    Container   container = Container();

    container = Container();

    return 0;
}
#endif

#ifdef GROUND018
//  Let's test cin
int main(void) {
    char    buf[512];

    std::cout << "Input a word: ";
    std::cin >> buf;
    std::cout << "You input [" << buf << "]" << std::endl;

    return 0;
}
#endif

#ifdef GROUND017
//  namespace alias practice
namespace   Shape {
    class Point {public: double x, y;};
    class Circle {public: Point center; double radius;};
}

namespace   ShapeNew = Shape;

int main(void) {
    ShapeNew::Circle    circle;

    std::cout << circle.radius << std::endl;

    return 0;
}
#endif

#ifdef GROUND016
//  namespace practice
namespace   Shape {
    class Point {public: double x, y;};
    class Circle {public: Point center; double radius;};
}

int main(void) {
    Shape::Circle   circle;

    std::cout << circle.radius << std::endl;

    return 0;
}
#endif

#ifdef GROUND015
//  궁금: c++ 도 c 처럼 지역 변수는 따로 초기화하지 않는 것일까?
//  결과: c 와 마찬가지로 자동으로 초기화하지는 않는다
void    function(void) {
    int local;

    std::cout << "Initial local variable: " << local << std::endl;
    local = 42;
    std::cout << "After set local variable: " << local << std::endl;
}

int main(void) {
    function();
    function();

    return 0;
}
#endif

#ifdef GROUND014
//  궁금:
//  Object  object1;
//  Object  object2 = Object();
//  
//  object1 = Object();
//  
//  object1 은 default constructor 와 operator=() 가 호출될 것 같다
//  object2 는 default constructor 만 호출될 것 같다
//
//  결과:
//  - 예상과 일치
//      error 관련:
//      - 'Object object = Object();' 처럼 declaration 과 assignment 를 동시에 한 후
//          object 를 사용하지 않으면 unused variable error 가 발생한다
//      - 'Object object; object = Object();' 처럼 declaration 과 assignment 를
//          나눠 실시하면 이 후 object 를 사용하지 않아도
//          unused variable error 가 발생하지 않는다
class Object    {
public:
    int _value;

    Object(void);
    ~Object(void);

    Object  &operator=(Object const &rhs);

    int getValue(void) const;
};



Object::Object(void) {
    std::cout << "Object(void) is called" << std::endl;

    return;
}

Object::~Object(void) {
    std::cout << "~Object(void) is called" << std::endl;

    return;
}

Object  &Object::operator=(Object const &rhs) {
    std::cout << "Object::operator=(rhs) is called" << std::endl;
    this->_value = rhs.getValue();

    return *this;
}

int Object::getValue(void) const {
    return this->_value;
}



int main(void) {
    Object  object1;
    Object  object2 = Object();

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
//  in c: calling 'function(42)' from 'function()' is warning -> not intended work
//      - forced specifying 'void' on declaration of empty argument
//  in cpp: calling 'function(42)' from 'function()' is error -> consistent with intend
void    function() {
    std::cout << "function() is called" << std::endl;
}

int main(void) {
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
    int _value;

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


int main(void) {
    Object  object; // error: call to constructor of 'Object' is ambiguous

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
    int _value;

    Object(int value = 1);
};



Object::Object(int value): _value(value) {
    std::cout << "Object(" << value << ") is called" << std::endl;
    return;
}



int main(void) {
    Object  object = Object(2);

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
    int _value;
};



int main(int argc, char **argv) {
    Object  object = Object(42);    // error: no matching conversion for functional-style cast from 'int' to 'Object'

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
    int _value;

    Object(int value);
};



Object::Object(int value): _value(value) {
    return;
}



int main(void) {
    Object  object; // error: no matching constructor for initialization of 'Object'

    std::cout << object._value << std::endl;

    return 0;
}
#endif

#ifdef GROUND008
// Let's put NULL value to the function implemented at GROUND007
// We can know that NULL is of type 'void *'
// Because "void (*)(int &)" and "void (*)(int *)" is different, compiler can't find matching function for function(NULL)
void    function(int &referenceInt) {
    std::cout << "Value of parameter: " << referenceInt << std::endl;
}

int main(void) {
    function(NULL); // error: no matching function for call to 'function'

    return 0;
}
#endif

#ifdef GROUND007
// let's make simple function that takes reference type as argument
void    function(int &referenceInt) {
    std::cout << "Value of parameter: " << referenceInt << std::endl;
}

int main(void) {
    int i;

    i = 42;
    function(i);
}
#endif

#ifdef GROUND006
// let's see the value of member variable of simple class without user-defined constructor
// Default constructor made by compiler set the member variable as 0
class Object {
private:
    int _value;
public:
    int getValue(void) const;
};



int Object::getValue(void) const {
    return this->_value;
}



int main(int argc, char **argv) {
    Object  object;

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



int main(void) {
    Object  object; // error: unused variable 'object'

    return 0;
}
#endif

#ifdef GROUND004
// https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions/piscine-c-d02-canonical-form/videos/canonical-form
class Object {
private:
    int _value;
public:
    Object(void);
    Object(int const value);
    Object(Object const &src);
    ~Object(void);

    Object  &operator=(Object const &rhs);

    int getValue(void) const;
};

std::ostream    &operator<<(std::ostream &out, Object const &rhs);



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

Object  &Object::operator=(Object const &rhs) {
    this->_value = rhs.getValue();
    return *this;
}

int Object::getValue(void) const {
    return this->_value;
}

std::ostream    &operator<<(std::ostream &out, Object const &rhs) {
    out << "The value: " << rhs.getValue();
    return out;
}



int main(void) {
    Object  instance1;
    Object  instance2 = Object(42);
    Object  instance3 = Object(instance1);

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
    int _n;

public:
    Object(int const n);
    ~Object(void);

    int getValue(void) const;

    Object  &operator=(Object const &rhs);
    Object  operator+(Object const &rhs) const;
};

std::ostream    &operator<<(std::ostream &out, Object const &rhs);



Object::Object(int const n): _n(n) {
    std::cout << "Constructor called with value " << n << std::endl;
    return;
}

Object::~Object(void) {
    std::cout << "Destructor called with value " << this->_n << std::endl;
    return;
}

int Object::getValue(void) const {
    return this->_n;
}

Object  &Object::operator=(Object const &rhs) {
    std::cout << "Assignation operator called from " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl;

    this->_n = rhs.getValue();

    return *this;
}

Object  Object::operator+(Object const &rhs) const {
    std::cout << "Addition operator called with " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;

    const Object result = Object(this->_n + rhs.getValue());
    return result;
}

std::ostream    &operator<<(std::ostream &out, Object const &rhs) {
    out << rhs.getValue();
    return out;
}



int main(void) {
    Object  x = Object(10);
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

    void    bar(char const c) const;
    void    bar(int const n) const;
    void    bar(float const z) const;
    void    bar(double const d) const;
    void    bar(Object const &i) const;
};



Object::Object(void) {
    std::cout << "Constructor called" << std::endl;
    return;
}

Object::~Object(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Object::bar(char const c) const {
    std::cout << "Member function bar called with char overload : " << c << std::endl;
    return;
}

void    Object::bar(int const n) const {
    std::cout << "Member function bar called with int overload : " << n << std::endl;
    return;
}

void    Object::bar(float const z) const {
    std::cout << "Member function bar called with float overload : " << z << std::endl;
    return;
}

void    Object::bar(double const d) const {
    std::cout << "Member function bar called with double overload : " << d << std::endl;
    return;
}

void    Object::bar(Object const &i) const {
    (void)i;
    std::cout << "Member function bar called with Object overload" << std::endl;
    return;
}



int main(void) {
    Object  object;

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
int main(void) {
    int num;

    std::cout << (std::cin >> num) << std::endl;

    return 0;
}
#endif

#ifdef GROUND000
#include <cassert>  // assert()

//  #define NDEBUG

int main(int argc, char **argv) {
    assert(argc != 1);
    (void)argv;

    return 0;
}
#endif
