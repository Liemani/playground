#include <string.h>

#define ARRAY_SIZE 42

int main(void) {
    char a[ARRAY_SIZE];
    char b[ARRAY_SIZE];

    memcpy(&b, &a, sizeof(char) * ARRAY_SIZE);

    return 0;
}
