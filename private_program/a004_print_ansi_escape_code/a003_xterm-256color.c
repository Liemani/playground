#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

int main(void) {
    char coloredString[] = "[0;000m8888[000m";
    int numberOffset = 4;
    size_t coloredStringLength = strlen(coloredString);

    char numberString[] = "000";

    int number = 0;
    while (number < 256) {
        sprintf(numberString, "%03d", number);
//        sprintf(coloredString + numberOffset, "%03d", number);
        memcpy(coloredString + numberOffset, numberString, 3);

        coloredString[2] = '0';
        coloredString[3] = '0';
        printf("[00%03d] %s", number, coloredString);
//        write(1, coloredString, coloredStringLength);

        coloredString[2] = '1';
        coloredString[3] = ';';
        printf("  [1;%03d] %s", number, coloredString);

        coloredString[2] = '2';
        coloredString[3] = ';';
        printf("  [2;%03d] %s", number, coloredString);

        printf("\n");

        ++number;
    }

    return 0;
}
