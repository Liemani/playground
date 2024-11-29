#include <stdio.h>
#include <stdlib.h>

void pabortif(int expression) {
  if (expression) {
    perror("");
    abort();
  }
}

int clearStdin() {
  while (1) {
    char ch = getchar();
    if (ch == '\n') {
      break;
    }
    else if (ch == -1) {
      return -1;
    }
  }

  return 0;
}

int main() {
  while (1) {
    char ch = getchar();
    printf("[%c] is entered\n", ch);
    pabortif(clearStdin() == -1);
  }
  return 0;
}
