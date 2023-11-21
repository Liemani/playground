#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 3;

    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d % %d = %d\n", a, b, a % b);

    a = -10;

    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);

    return 0;
}
