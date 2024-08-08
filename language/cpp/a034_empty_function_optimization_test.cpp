// test if the compiler optimize empty function or not
#define a004



#ifdef a004
#include <cstdio>

void emptyFunction() {
}

int main() {
  emptyFunction();

  return 0;
}
#endif



#ifdef a003
#include <cstdio>

void emptyFunction() {
}

int main() {
//  emptyFunction();

  return 0;
}
#endif
