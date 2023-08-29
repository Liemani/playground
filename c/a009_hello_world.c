#include<stdio.h>
#include<math.h>

void printWithStatic(void) {
    static double staticValue = 10.0;

    double sqrtedValue = sqrt(staticValue);

    printf("Hello, world! (%f)\n", sqrtedValue);
}

int main(void) {
    printWithStatic();

    return 0;
}
