#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 1;
    int c;

#ifdef IF
    c = a == b ? a : b;
#elif TERNARY
    if (a == b)
        c = a;
    else
        c = b;
#else
    c = 2;
#endif

    printf("c = %d\n", c);

    return 0;
}
