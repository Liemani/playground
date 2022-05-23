#include <string.h>

int main(void) {
    char a;
    char b;

    a = 'a';

    memcpy(&b, &a, sizeof(char));

    return 0;
}
