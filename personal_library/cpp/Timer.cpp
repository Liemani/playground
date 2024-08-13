#include "Timer.hpp"

#include <sys/time.h> // gettimeofday()
#include <stddef.h> // NULL
#include <cassert>

#include "Timerval.hpp"

Timer::Timer(int targetTimeInterval) {
  _targetTimeInterval = targetTimeInterval;
}

void Timer::set() {
  assert(gettimeofday(&_targetTime, NULL) != -1);
  this->update();
}

void Timer::update() {
  add(_targetTime, _targetTimeInterval);
}

void Timer::busySleep() {
  struct timeval currentTime;
  while(true) {
    assert(gettimeofday(&currentTime, NULL) != -1);
    if (_targetTime <= currentTime) {
      break;
    }
  }
}

struct timeval& Timer::targetTime() {
  return _targetTime;
}
