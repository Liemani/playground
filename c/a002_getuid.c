#include <unistd.h>
#include <stdio.h>

int main(void) {
    uid_t uid = getuid();

    printf("getuid(): %d\n", uid);
}
