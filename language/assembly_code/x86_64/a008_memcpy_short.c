#include <string.h>

int main(void) {
    short a;
    short b;

    a = 42;

    memcpy(&b, &a, sizeof(short));

    return 0;
}
