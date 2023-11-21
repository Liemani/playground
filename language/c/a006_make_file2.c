#include <stdio.h>

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    // Open the file in write mode
    FILE* fp = fopen(".temp2", "w");
    if (fp == NULL) {
        fprintf(stderr, "failed open .temp2 file");
        return 0;
    }

    // Write the data to the file
    for (int i = 0; i < 10000000; i++) {
      fwrite("NNNNNNNNNN", 10, 1, fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}
