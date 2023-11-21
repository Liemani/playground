#include <iostream>

//  Int.h start
class Int {

private :
  int _value;

public :
  Int(int value);

  Int& operator+=(const Int& rhs);
  Int operator+(const Int& rhs);

  friend std::ostream& operator<<(std::ostream& out, const Int& value);

};  // Int

Int::Int(int value)
  : _value(value)
{ }

Int& Int::operator+=(const Int& rhs) {
  this->_value += rhs._value;
  return *this;
}

Int Int::operator+(const Int& rhs) {
  Int result = *this;
  return result += rhs;
}

std::ostream& operator<<(std::ostream& out, const Int& value) {
  return out << value._value;
}
//  Int.h end

int main(int argc, char* argv[]) {
  Int first = Int(4);
  Int second = Int(2);
  Int third = first + second;

  std::cout << third << std::endl;
  std::cout << first + second << std::endl;

  return 0;
}
