#ifndef TIMER_HPP
#define TIMER_HPP

#include <sys/time.h> // struct timeval
#include <stddef.h> // NULL

class Timer {

public :
  Timer(int targetInterval);
  void set();
  void update();
  void busySleep();

  struct timeval& targetTime();

private :
  int _targetTimeInterval;

  struct timeval _targetTime;

};

#endif  // TIMER_HPP
