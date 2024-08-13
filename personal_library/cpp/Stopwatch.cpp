#include "Stopwatch.hpp"

#include <sys/time.h> // gettimeofday()
#include <stddef.h> // NULL
#include <cstdio> // printf()
#include <cassert>
#include <string>
#include <cstring>

void Stopwatch::start() {
  assert(gettimeofday(&_startTime, NULL) != -1);
  _lappedTime = _startTime;
}

const char* Stopwatch::lap() {
  struct timeval interval;

  assert(gettimeofday(&_lappedTime, NULL) != -1);

  interval.tv_sec = _lappedTime.tv_sec - _startTime.tv_sec;
  interval.tv_usec = _lappedTime.tv_usec - _startTime.tv_usec;
  if (interval.tv_usec < 0) {
    --interval.tv_sec;
    interval.tv_usec += 1000000;
  }

  char buffer[42];
  sprintf(buffer, "%20ld.%06ld", interval.tv_sec, interval.tv_usec);

  char* start = buffer;
  while (*start == ' ') {
    ++start;
  }

  memcpy(_string, start, strlen(start) + 1);

  return _string;
}
