#include <iostream>
#include <fstream>
#include <string>
#include <sys/select.h>

extern "C" {
#include "select_context.h"
}

#define ARDUINO_FILE_PATH "/dev/cu.usbmodem1101"

int main() {
  std::fstream fstream(ARDUINO_FILE_PATH);
  SelectContext selectContext = selectContext_new();

  selectContext_readFDSet_add(selectContext, int fd);

  selectContext_select(selectContext);
  selectContext_isSet(selectContext, int fd);

  std::string line;
  while () {
    ssize_t numberRead = getline(fstream, line);
    std::cout << line << std::endl;
  }

  select_delete(selectContext);

  return 0;
}
