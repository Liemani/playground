#include <string.h>

int main(void) {
    long a;
    long b;

    a = 42;

    memcpy(&b, &a, sizeof(long));

    return 0;
}
