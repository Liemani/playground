#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define OUTPUT_FILE_EXTENSION "c"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("argc is %d, usage: %s <path>\n", argc, argv[0]);
        exit(0);
    }

    int inputFileFD = open(argv[1]);
    if (inputFileFD == -1) {
        perror(NULL);
        exit(0);
    }

    read(inputFileFD, O_RDONLY);

    open();
    write();
    return 0;
}

int openWriteFile(char* inputFileName) {
    char* beforeExtension = strrchr(inputFileName, '.');

    size_t inputFileNameSize =;

    if (beforeExtension != NULL) {
        inputFileNameSize = beforeExtension - inputFileName;
    } else {
        inputFileNameSize = strlen(inputFileName);
    }

    inputFileNameSize = beforeExtension != NULL
        ? beforeExtension - inputFileName
        : strlen(inputFileName);

    size_t outputFileNameSize = inputFileNameSize + OUTPUT_FILE_EXTENSION + 1;
    char* outputFileName = malloc(outputFileNameSize);
    outputFileName[outputFileNameSize - 1] = '\0';
    memcpy(outputFileName, inputFileName, inputFileNameSize);

}
