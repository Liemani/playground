#include <iostream>

#include "IOSDescriber.hpp"

void IOSDescriber::describeStateBit() {
  std::cout << "badbit : " << std::ios_base::badbit << std::endl;
  std::cout << "failbit : " << std::ios_base::failbit << std::endl;
  std::cout << "eofbit : " << std::ios_base::eofbit << std::endl;
}

void IOSDescriber::describe(const std::ios& ios) {
  std::cout << "[debug describe start]" << std::endl;
  std::cout << "good() : " << ios.good() << std::endl;
  std::cout << "eof() : " << ios.eof() << std::endl;
  std::cout << "fail() : " << ios.fail() << std::endl;
  std::cout << "bad() : " << ios.bad() << std::endl;
  std::cout << "rdstate() : " << ios.rdstate() << std::endl;

  std::cout << std::endl;

  const std::ios_base::iostate iostate = ios.rdstate();
  std::cout << "badbit : " << (iostate & ios.badbit) << std::endl;
  std::cout << "failbit : " << (iostate & ios.failbit) << std::endl;
  std::cout << "eofbit : " << (iostate & ios.eofbit) << std::endl;
  std::cout << "[debug describe end]" << std::endl;
}
