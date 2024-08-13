#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <sys/time.h> // struct timeval
#include <stddef.h> // NULL
#include <string>

class Stopwatch {

public :
  void start();
  const char* lap();

private :
  struct timeval _startTime;
  struct timeval _lappedTime;
  char _string[42];

};

#endif  // STOPWATCH_HPP
