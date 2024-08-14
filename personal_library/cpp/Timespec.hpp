#ifndef TIMESPEC_HPP
#define TIMESPEC_HPP

#include <time.h>

void operator+=(struct timespec& timespec, long nsec);
void operator+=(struct timespec& lhs, const struct timespec& rhs);

void operator-=(struct timespec& lhs, const struct timespec& rhs);

bool operator>(const struct timespec& lhs, const struct timespec& rhs);
bool operator<(const struct timespec& lhs, const struct timespec& rhs);
bool operator<=(const struct timespec& lhs, const struct timespec& rhs);

#endif  // TIMESPEC_HPP
