#include <cstdio>
#include <fstream>
#include <map>
#include <string>

std::map<int, int> map;

void printMap() {
  for (const auto it : map) {
    printf("map[%4d]%8d\n", it.first, it.second);
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("usage : %s <input_file>\n", argv[0]);
    exit(-1);
  }

  std::ifstream is(argv[1]);
  std::string word;
  while (is) {
    is >> word;
    ++map[atoi(word.c_str())];
  }

  printMap();

  return 0;
}
