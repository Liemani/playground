#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

// TODO remove unused header file
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>

using std::cin;
using std::cout;
using std::endl;

static void lmi_getline(std::istream& istream, std::string& line);

class Program {
private:
    typedef void (Program::*Method)(void);
    typedef std::pair<std::string, Method> MethodMapElementType;
    typedef std::map<std::string, Method> MethodMap;

    static const MethodMap methodMap;

    uint16_t portNumber;
    int serverSocketFD;
    int clientSocket;

    static void describeMethodCommand(void);

    void describe(void);
    void setPort(void);
    void listen(void);
    void acceptClient(void);
    void describeSocketOption(void);
    void sendLargeFile(void);
    void closeServerSocket(void);

public:
    Program(void): portNumber(0) {};

    void mainLoop(void);
};

const Program::MethodMap Program::methodMap = {
    { "describe", &Program::describe },
    { "set port", &Program::setPort },
    { "listen", &Program::listen },
    { "accept", &Program::acceptClient },
    { "describe socket", &Program::describeSocketOption },
    { "send large file", &Program::sendLargeFile },
    { "close server socket", &Program::closeServerSocket },
};

void Program::describe(void) {
    cout << "port number: " << this->portNumber << endl;
}

void Program::setPort(void) {
    cout << "Enter port number: ";
    std::string line;
    lmi_getline(cin, line);
    std::istringstream inputStringStream(line);
    inputStringStream >> this->portNumber;
    if (!inputStringStream)
        throw "fail get port number";
    else
        cout << "port number: " << this->portNumber << endl;
}

void Program::listen(void) {
    if (this->portNumber == 0) {
        cout << "wrong port number: " << this->portNumber << endl;
    }

    this->serverSocketFD = socket(PF_INET, SOCK_STREAM, 0);
    fcntl(this->serverSocketFD, F_SETFL, O_NONBLOCK);

    struct sockaddr_in serverSocketAddress;
    memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(this->portNumber);
    serverSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(this->serverSocketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));
    ::listen(this->serverSocketFD, 5);
}

void Program::acceptClient(void) {
    struct sockaddr clientSocketAddress;
    socklen_t clientSocketAddressSize = sizeof(clientSocketAddress);
    this->clientSocket = accept(this->serverSocketFD, &clientSocketAddress, &clientSocketAddressSize);
    if (this->clientSocket == -1)
        cout << "fail accept" << endl;
}

void Program::describeSocketOption(void) {
    int optionValue;
    socklen_t optionLength = sizeof(optionValue);

    getsockopt(this->clientSocket, SOL_SOCKET, SO_SNDBUF, &optionValue, &optionLength);

    cout << "SO_SNDBUF: " << optionValue << ", size: " << optionLength << endl;
}

void Program::sendLargeFile(void) {
    
}

void Program::closeServerSocket(void) {
    close(this->serverSocketFD);
}



void Program::mainLoop(void) {
    std::string line;

    while (true) {
        cout << endl << "Enable command list:" << endl;
        Program::describeMethodCommand();
        cout << "Enter command: ";

        lmi_getline(cin, line);

        Program::MethodMap::const_iterator iter = Program::methodMap.find(line);
        if (iter == Program::methodMap.end()) {
            cout << "not found: [" << line << "]" << endl;
            continue;
        }
        try {
            (this->*(iter->second))();
        } catch(const char* string) {
            cout << string << ": [" << line << "]" << endl;
        }
    }
}

void Program::describeMethodCommand(void) {
    for (MethodMap::const_iterator iter = Program::methodMap.begin(); iter != Program::methodMap.end(); ++iter)
        cout << iter->first << endl;
}

static void lmi_getline(std::istream& istream, std::string& line) {
    std::getline(istream, line);
    if (!istream)
        throw "failed getline";
}

int main(void) {
    Program program;

    program.mainLoop();

    return 0;
}
