#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MILION 100000000

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    // Open the file in write mode
    int fd = open(".temp2", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        fprintf(stderr, "failed open .temp2 file\n");
        perror(NULL);
        return 1;
    }

    if (ftruncate(fd, 100000000) == -1) {
        fprintf(stderr, "failed ftruncate()\n");
        return 2;
    }

    // Write the data to the file
    char* data;
    data = malloc(MILION);
    memset(data, 'N', MILION);
    write(fd, data, MILION);
    free(data);

    // Close the file
    close(fd);

    return 0;
}
