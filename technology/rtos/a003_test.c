#include <stdio.h>

#include "Schedule.hpp"
#include "Stopwatch.hpp"
#include "Timespec.hpp"

int main(int argc, char* argv[]) {
  setSchedulePriorityMax();

  Stopwatch stopwatch;
  stopwatch.start();
  struct timespec targetTime = stopwatch.startTime();
  targetTime += 1000;
  clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &targetTime, NULL);
  printf("elapsed time : %s\n", stopwatch.lap());

  return 0;
}
