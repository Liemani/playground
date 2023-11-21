#include <iostream>

using std::cout;
using std::endl;

/*
class Container {
private:
    int a;

public:
    Container() { this->a = 0; cout << "default constructor is called" << endl; }
    Container(int num) { this->a = num; cout << "constructor is called" << endl; }
    Container(const Container& rhs) { this->a = rhs.a; cout << "copy constructor is called" << endl; }
    ~Container() { cout << "[" << this->a << "] " << "destructor is called" << endl; }

    Container& operator=(const Container& rhs) { cout << "operator= is called" << endl; return *this; }

    Container operator+(const Container& rhs) { cout << "operator+ is called" << endl; return Container(); }

};
*/

class Container {
private:
    int a;

public:
    Container();
    Container(int num);
    Container(const Container& rhs);
    ~Container();

    Container& operator=(const Container& rhs);

    Container operator+(const Container& rhs);

};

Container::Container() {
    this->a = 0;
    cout << "default constructor is called" << endl;
}

Container::Container(int num) {
    this->a = num;
    cout << "constructor is called" << endl;
}

Container::Container(const Container& rhs) {
    this->a = rhs.a;
    cout << "copy constructor is called" << endl;
}

Container::~Container() {
    cout << "[" << this->a << "] " << "destructor is called" << endl;
}

Container& Container::operator=(const Container& rhs) {
    cout << "operator= is called" << endl;
    return *this;
}

Container Container::operator+(const Container& rhs) {
    cout << "operator+ is called" << endl;
    return Container();
}

int main() {
    Container c1;
    Container c2 = 2;
    Container c3 = 3;

    c1 = c2 + c3;

    return 0;
}
