#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <time.h> // struct timespec

class Stopwatch {

public :
  void start();
  const char* lap();

private :
  struct timespec _startTime;

  char _lap[42];

};

#endif  // STOPWATCH_HPP
