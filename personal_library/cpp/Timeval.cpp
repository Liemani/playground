#include "Timeval.hpp"

#include <sys/time.h>

void add(struct timeval& timeval, long usec) {
  timeval.tv_usec += usec;
  if (timeval.tv_usec >= 1000000) {
    timeval.tv_usec -= 1000000;
    ++timeval.tv_sec;
  }
}

void add(struct timeval& lhs, struct timeval& rhs) {
  lhs.tv_sec += rhs.tv_sec;
  lhs.tv_usec += rhs.tv_usec;
  if (lhs.tv_usec >= 1000000) {
    lhs.tv_usec -= 1000000;
    ++lhs.tv_sec;
  }
}

bool operator>(const struct timeval& lhs, const struct timeval& rhs) {
  if (lhs.tv_sec > rhs.tv_sec) {
    return true;
  } else if (lhs.tv_sec == rhs.tv_sec) {
    if (lhs.tv_usec > rhs.tv_usec) {
      return true;
    }
  }

  return false;
}

bool operator<(const struct timeval& lhs, const struct timeval& rhs) {
  return rhs > lhs;
}

bool operator<=(const struct timeval& lhs, const struct timeval& rhs) {
  return !(lhs > rhs);
}
