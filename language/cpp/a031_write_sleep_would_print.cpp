// printf() prints when terminate without new line. write print immediately after call
#include <cstdio>
#include <unistd.h>

int main() {
  printf("printf");
//  write(1, "hi", 2);
  usleep(1000000);

  return 0;
}
