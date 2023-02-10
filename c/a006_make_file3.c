#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    // Open the file in write mode
    int fd = open(".temp2", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1) {
        fprintf(stderr, "failed open .temp2 file");
        return 1;
    }

    if (ftruncate(fd, 100000000) == -1) {
        fprintf(stderr, "failed ftruncate()");
        return 1;
    }

    // Write the data to the file
    for (int i = 0; i < 10000000; i++) {
        write(fd, "NNNNNNNNNN", 10);
    }

    // Close the file
    close(fd);

    return 0;
}
