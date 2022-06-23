#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/event.h>
#include <fcntl.h>
#include <stdbool.h>

void subMain(int argc, char* argv[]);
void mainLoop(int kqueueFD, int serverSocketFD);
void modifyEvent(int kqueueFD, int ident, int16_t filter, uint16_t flags);
int acceptClient(int serverSocket);

int main(int argc, char* argv[]) {
    subMain(argc, argv);

    return 0;
}

void subMain(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: %s <port number>\n", argv[0]);
        return;
    }

    int serverSocketFD = socket(PF_INET, SOCK_STREAM, 0);
    fcntl(serverSocketFD, F_SETFL, O_NONBLOCK);

    struct sockaddr_in serverSocketAddress;
    memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(atoi(argv[1]));
    serverSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(serverSocketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));
    listen(serverSocketFD, 5);

    int kqueueFD = kqueue();

    modifyEvent(kqueueFD, serverSocketFD, EVFILT_READ, EV_ADD);

    mainLoop(kqueueFD, serverSocketFD);
}

#define arraySize 512

void mainLoop(int kqueueFD, int serverSocketFD) {
    int eventCount;
    struct kevent eventArray[arraySize];
    int clientSocketFDArray[arraySize] = {};
    char recieveBuffer[arraySize];

    while (true) {
        eventCount = kevent(kqueueFD, NULL, 0, eventArray, arraySize, NULL);
        for (int i = 0; i < eventCount; ++i) {
            struct kevent* event = eventArray + i;
            int fd = event->ident;

            if (fd == serverSocketFD) {
                int clientSocket = acceptClient(serverSocketFD);
                clientSocketFDArray[clientSocket] = 1;
                modifyEvent(kqueueFD, clientSocket, EVFILT_READ, EV_ADD);
            }
            else {
                ssize_t result = recv(fd, recieveBuffer, arraySize, 0);
                printf("result: [%ld]\n", result);
                printf("recieveBuffer: [%s]\n\n", recieveBuffer);
            }
        }
    }
}

void modifyEvent(int kqueueFD, int ident, int16_t filter, uint16_t flags) {
    struct kevent event;
    EV_SET(&event, ident, filter, flags, 0, 0, NULL);
    kevent(kqueueFD, &event, 1, NULL, 0, NULL);
}

int acceptClient(int serverSocket) {
    struct sockaddr clientSocketAddress;
    socklen_t clientSocketAddressSize = sizeof(clientSocketAddress);
    return accept(serverSocket, &clientSocketAddress, &clientSocketAddressSize);
}
