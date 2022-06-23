#include <string.h>

int main(void) {
    long long a;
    long long b;

    a = 42;

    memcpy(&b, &a, sizeof(long long));

    return 0;
}
