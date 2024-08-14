#ifndef TIMEVAL_HPP
#define TIMEVAL_HPP

#include <sys/time.h>

void add(struct timeval& timeval, long usec);
void add(struct timeval& lhs, struct timeval& rhs);

bool operator>(const struct timeval& lhs, const struct timeval& rhs);
bool operator<(const struct timeval& lhs, const struct timeval& rhs);
bool operator<=(const struct timeval& lhs, const struct timeval& rhs);

#endif  // TIMEVAL_HPP
