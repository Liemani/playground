#include "Stopwatch.hpp"

#include <time.h> // clock_gettime()
#include <cstdio> // sprintf()
#include <cassert>

#include "Timespec.hpp"

void Stopwatch::start() {
  assert(clock_gettime(CLOCK_MONOTONIC, &_startTime) != -1);
}

const char* Stopwatch::lap() {
  struct timespec timeInterval;

  assert(clock_gettime(CLOCK_MONOTONIC, &timeInterval) != -1);
  timeInterval -= _startTime;

  sprintf(_lap, "%20ld.%09ld", timeInterval.tv_sec, timeInterval.tv_nsec);

  char* lapString = _lap;
  while (*lapString == ' ') {
    ++lapString;
  }

  return lapString;
}
