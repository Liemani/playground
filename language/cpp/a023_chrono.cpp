#include <iostream>
#include <chrono>

int main() {
  std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
  std::cout << now << std::endl;

  return 0;
}
