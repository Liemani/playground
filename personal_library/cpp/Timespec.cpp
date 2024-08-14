#include "Timespec.hpp"

#include <time.h>

void operator+=(struct timespec& timespec, long nsec) {
  timespec.tv_nsec += nsec;
  if (timespec.tv_nsec >= 1000000000) {
    timespec.tv_nsec -= 1000000000;
    ++timespec.tv_sec;
  }
}

void operator+=(struct timespec& lhs, const struct timespec& rhs) {
  lhs.tv_sec += rhs.tv_sec;
  lhs.tv_nsec += rhs.tv_nsec;
  if (lhs.tv_nsec >= 1000000000) {
    lhs.tv_nsec -= 1000000000;
    ++lhs.tv_sec;
  }
}

void operator-=(struct timespec& lhs, const struct timespec& rhs) {
  lhs.tv_sec -= rhs.tv_sec;
  lhs.tv_nsec -= rhs.tv_nsec;
  if (lhs.tv_nsec < 0) {
    --lhs.tv_sec;
    lhs.tv_nsec += 1000000000;
  }
}

bool operator>(const struct timespec& lhs, const struct timespec& rhs) {
  if (lhs.tv_sec > rhs.tv_sec) {
    return true;
  } else if (lhs.tv_sec == rhs.tv_sec) {
    if (lhs.tv_nsec > rhs.tv_nsec) {
      return true;
    }
  }

  return false;
}

bool operator<(const struct timespec& lhs, const struct timespec& rhs) {
  return rhs > lhs;
}

bool operator<=(const struct timespec& lhs, const struct timespec& rhs) {
  return !(lhs > rhs);
}
