#include <stdio.h>

//  template
//  #ifdef COMPILE002
//  int main() {
//      return 0;
//  }
//  #endif

#define COMPILE004
#ifdef COMPILE004
// print binary representation of float value
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define NORMAL 0
#define ERROR_ARGUMENT_COUNT -1

int checkArgument(int argc, char** argv) {
    (void)argv;
    if (argc != 2) {
        return ERROR_ARGUMENT_COUNT;
    }

    return NORMAL;
}

void handleError(int argc, char** argv, int errorCode) {
    (void)argc;
    switch (errorCode) {
        case ERROR_ARGUMENT_COUNT:
            printf("usage: %s <number to convert to float>\n", argv[0]);
            break;
        default:
            assert(false);
            break;
    }
}

//  - assume
//      pOutputBuffer has at least 8 byte size
void printByte(void* pByte, char* pOutputBuffer) {
    unsigned char byte = *(unsigned char*)pByte;

    for (size_t i = 0; i < 8; ++i) {
        pOutputBuffer[i] = '0' + ((byte & 0x1 << (7 - i)) != 0);
    }
}

void printInBinary(void* pData, size_t length) {
    char byteBuffer[9];

    byteBuffer[8] = '\0';

    for (size_t i = 0; i < length; ++i) {
        printByte(pData + i, byteBuffer);
        printf("%s ", byteBuffer);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int errorCode = checkArgument(argc, argv);
    if (errorCode != NORMAL) {
        handleError(argc, argv, errorCode);
    } else {
        float f = atof(argv[1]);
        printInBinary(&f, 4);
    }

    return 0;
}
#endif

#ifdef COMPILE003
// 140p print integer divise table
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define NORMAL 0
#define ERROR_ARGUMENT_COUNT -1
#define ERROR_ARGUMENT_FIRST -2

int checkArgument(int argc, char** argv) {
    if (argc != 2) {
        return ERROR_ARGUMENT_COUNT;
    }

    int divisor = atoi(argv[1]);
    if (divisor == 0) {
        return ERROR_ARGUMENT_FIRST;
    }

    return NORMAL;
}

void handleError(int argc, char** argv, int errorCode) {
    (void)argc;
    switch (errorCode) {
        case ERROR_ARGUMENT_COUNT:
            printf("usage: %s <divisor>\n", argv[0]);
            break;
        case ERROR_ARGUMENT_FIRST:
            printf("error: divisor must not 0\n");
            break;
        default:
            assert(false);
            break;
    }
}

void run(int divisor) {
    for (int dividend = -8; dividend < 8; ++dividend) {
        printf("%2d / %d = %2d ...... %d\n", dividend, divisor, dividend / divisor, dividend % divisor);
    }
}

int main(int argc, char** argv) {
    int errorCode = checkArgument(argc, argv);
    if (errorCode != NORMAL) {
        handleError(argc, argv, errorCode);
    } else {
        run(atoi(argv[1]));
    }

    return 0;
}
#endif

#ifdef COMPILE002
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (unsigned int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

int main() {
    int i = 12345;
    float f;
    *(int*)&f = i;

    show_bytes((byte_pointer)&i, sizeof(i));
    show_bytes((byte_pointer)&f, sizeof(f));
    printf("%f\n", f);

    return 0;
}
#endif

#ifdef COMPILE001
// 81p
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (unsigned int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_float(float x) {
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer)&x, sizeof(x));
}

void test_show_bytes(int val) {
    int ival = val;
    show_int(ival);

    float fval = (float)ival;
    show_float(fval);

    int* pval = &ival;
    show_pointer(pval);
}

int main() {
    test_show_bytes(0x3039);
    return 0;
}
#endif

#ifdef COMPILE000
// 38p
int main()
{
    printf("hello, world\n");
    return 0;
}
#endif
