#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50
#define APPEND_STRING "?\?!\n"
#define APPEND_STRING_LENGTH 4

int main(void) {
    char buffer[MAX_INPUT_LENGTH + APPEND_STRING_LENGTH + 1];

    ssize_t numberOfReadByte = read(STDIN_FILENO, buffer, MAX_INPUT_LENGTH + 1);
    memcpy(buffer + numberOfReadByte - 1, APPEND_STRING, APPEND_STRING_LENGTH);
    write(STDOUT_FILENO, buffer, numberOfReadByte - 1 + APPEND_STRING_LENGTH);

    return 0;
}
