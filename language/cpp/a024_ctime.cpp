#include <iostream>
#include <ctime>

int main() {
  std::time_t time = std::time(nullptr);
  const struct tm* localtime = std::localtime(&time);
  std::cout << std::asctime(localtime) << std::endl;

  return 0;
}
