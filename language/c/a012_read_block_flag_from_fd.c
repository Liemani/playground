#include <stdio.h>  // printf()
#include <fcntl.h>  // fcntl()

const char* containsFlag(int flags, int flag)
{
	return (flags & flag) != 0 ? "\033[32mtrue\033[0m" : "\033[31mfalse\033[0m";
}

const char* hasFlag(int fd, int flag) {
  int flags = fcntl(0, F_GETFL, 0);
  return containsFlag(flags, flag);
}

int main() {
  printf("hasFlag(0, O_NONBLOCK) : %s\n", hasFlag(0, O_NONBLOCK));
  printf("hasFlag(1, O_NONBLOCK) : %s\n", hasFlag(1, O_NONBLOCK));
  printf("hasFlag(2, O_NONBLOCK) : %s\n", hasFlag(2, O_NONBLOCK));

  return 0;
}
