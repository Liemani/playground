#include <stdio.h>
#include <arpa/inet.h>

int main(void) {
    uint16_t portNumber = 80;
    uint16_t networkPortNumber = htons(portNumber);

    printf("portNumber: [%#06x]\n", portNumber);
    printf("networkPortNumber: [%#6x]\n", networkPortNumber);

    return 0;
}
