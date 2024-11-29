#include <stdio.h>

int main() {
  char buf[10];
  snprintf(buf, 10, "%8.2f", 10.0 / 3.0);
  printf("[%s]\n", buf);

  return 0;
}
