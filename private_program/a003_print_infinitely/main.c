#include <stdio.h>  // printf()
#include <stdbool.h>  // true
#include <unistd.h> // sleep()

#define MAX_LOOP 100

int main(int argc, char* argv[]) {
  int count = 0;
  while (count < 100) {
    printf("Hello, world!\n");
    sleep(10);
    ++count;
  }

  return 0;
}
