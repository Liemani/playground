#include "ErrorHandler.hpp"

#include <iostream>

void ErrorHandler::exitWithMessage() {
  std::cerr << "Error : " << strerror(errno) << std::endl;
  exit(1);
}
