#include <cstdio>
#include <sstream>

int main() {
  std::istringstream iss("hi there, nice to meet you!\r\n nice to meet you too!");

  std::string word;
  int index = 1;
  while (true) {
    iss >> word;

    if (iss.eof()) {
      break;
    }

    printf("[%d] %s\n", index, word.c_str());

    ++index;
  }

  return 0;
}
