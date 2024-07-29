#include "main.hpp"

#include <iostream>

//const int Test1::value = 52;
const int Test2::_value = 42;

int Test2::value() const {
  return Test2::_value;
}

int main() {
  Test2 test2 = Test2();

  std::cout << "Test1::value : " << Test1::value << std::endl;
  std::cout << "Test2::value() : " << test2.value() << std::endl;

  return 0;
}
