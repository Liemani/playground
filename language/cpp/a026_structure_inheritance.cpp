#include <iostream>

struct Base {
  int value;

  Base(int value = 42);
};

struct Derived : Base {
};

Base::Base(int value)
: value(value)
{
}

int main() {
  Derived derived = Derived();
  std::cout << derived.value << std::endl;

  return 0;
}
