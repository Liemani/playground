#include <cstdio>
#include <unistd.h>

#include "Stopwatch.hpp"

const int repeatCount = 100;
Stopwatch stopwatch;

int main() {
  for (int i = 0; i < repeatCount; ++i) {
    stopwatch.start();
    usleep(1);
    const char* lap = stopwatch.lap();
    printf("%s\n", lap);
  }

  return 0;
}
