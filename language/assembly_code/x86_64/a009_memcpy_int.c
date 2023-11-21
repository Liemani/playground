#include <string.h>

int main(void) {
    int a;
    int b;

    a = 42;

    memcpy(&b, &a, sizeof(int));

    return 0;
}
