#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include "util.hpp"

using std::cin;
using std::cout;
using std::endl;

template <typename T, typename U>
struct Pair {
    T command;
    U method;
};

class Program {
private:
    typedef void (Program::*Method)(void);
    typedef Pair<const char*, Method> MethodPair;

    uint16_t portNumber;
    int serverSocketFD;
    int clientSocketFD;

    int remoteServerSocketFD;
	struct sockaddr_in remoteServerSocketAddress;

    static void describeMethodCommand(void);

    void describe(void);
    void setPort(void);
    void listen(void);
    void acceptClient(void);
    void setSockOpt(void);
    void describeSocketOption(void);
    void sendBigString(void);
    void closeServerSocket(void);
    void closeClientSocket(void);
    void close(void);
    void recv(void);
    void send(void);
    void connectRemote(void);
    void sendRemote(void);
    void recvRemote(void);
    void closeRemote(void);
    void reconnectRemote(void);
    void sendFileToRemote(void);

    static const MethodPair methodDictionary[];

public:
    Program(void)
        : portNumber(0)
        , serverSocketFD(-1)
        , clientSocketFD(-1)
        , remoteServerSocketFD(-1)
        , remoteServerSocketAddress()
    { };

    void mainLoop(void);
};



// MARK: - method
const Program::MethodPair Program::methodDictionary[] = {
    { "describe", &Program::describe },
    { "set port", &Program::setPort },
    { "listen", &Program::listen },
    { "accept", &Program::acceptClient },
    { "set socket", &Program::setSockOpt },
    { "describe socket", &Program::describeSocketOption },
    { "send big string", &Program::sendBigString },
    { "close server socket", &Program::closeServerSocket },
    { "close client socket", &Program::closeClientSocket },
    { "close", &Program::close },
    { "recv", &Program::recv },
    { "send", &Program::send },
    { "connect remote", &Program::connectRemote },
    { "send remote", &Program::sendRemote },
    { "recv remote", &Program::recvRemote },
    { "close remote", &Program::closeRemote },
    { "reconnect remote", &Program::reconnectRemote },
    { "send file to remote", &Program::sendFileToRemote },
};

void Program::describe(void) {
    cout << "port number: " << this->portNumber << endl;
    cout << "server socket fd: " << this->serverSocketFD << endl;
    cout << "client socket fd: " << this->clientSocketFD << endl;
    cout << endl;
    cout << "this->remoteServerSocketFD: "<< this->remoteServerSocketFD << endl;
    sockaddr_in_describe(this->remoteServerSocketAddress);
}

void Program::setPort(void) {
    cout << "current port number: " << this->portNumber << endl;
    std::string line;
    getSingleLine(cin,  "enter new port number: ", line);
    std::istringstream inputStringStream(line);
    inputStringStream >> this->portNumber;
    if (!inputStringStream)
        throw "getting port number";
    else
        cout << "port number: " << this->portNumber << endl;
}

void Program::listen(void) {
    this->setPort();

    this->serverSocketFD = socket(PF_INET, SOCK_STREAM, 0);
    fcntl(this->serverSocketFD, F_SETFL, O_NONBLOCK);

    struct sockaddr_in serverSocketAddress;
    memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(this->portNumber);
    serverSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(this->serverSocketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress)) == -1)
        throw "binding";

    ::listen(this->serverSocketFD, 5);

    cout << "listening " << this->portNumber << endl;
}

void Program::acceptClient(void) {
    if (this->clientSocketFD != -1)
        throw "No sit, sorry";

    struct sockaddr clientSocketAddress;
    socklen_t clientSocketAddressSize = sizeof(clientSocketAddress);
    this->clientSocketFD = accept(this->serverSocketFD, &clientSocketAddress, &clientSocketAddressSize);
    if (this->clientSocketFD == -1)
        cout << "accept" << endl;
    else
        printSuccessMessage("accept()");
}

void Program::describeSocketOption(void) {
    long long optionValue;
    socklen_t optionLength = sizeof(optionValue);

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_DEBUG, &optionValue, &optionLength);
    cout << "SO_DEBUG: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_REUSEADDR, &optionValue, &optionLength);
    cout << "SO_REUSEADDR: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_REUSEPORT, &optionValue, &optionLength);
    cout << "SO_REUSEPORT: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_KEEPALIVE, &optionValue, &optionLength);
    cout << "SO_KEEPALIVE: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_DONTROUTE, &optionValue, &optionLength);
    cout << "SO_DONTROUTE: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_LINGER, &optionValue, &optionLength);
    cout << "SO_LINGER: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_BROADCAST, &optionValue, &optionLength);
    cout << "SO_BROADCAST: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_OOBINLINE, &optionValue, &optionLength);
    cout << "SO_OOBINLINE: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_SNDBUF, &optionValue, &optionLength);
    cout << "SO_SNDBUF: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_RCVBUF, &optionValue, &optionLength);
    cout << "SO_RCVBUF: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_SNDLOWAT, &optionValue, &optionLength);
    cout << "SO_SNDLOWAT: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_RCVLOWAT, &optionValue, &optionLength);
    cout << "SO_RCVLOWAT: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_SNDTIMEO, &optionValue, &optionLength);
    cout << "SO_SNDTIMEO: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_RCVTIMEO, &optionValue, &optionLength);
    cout << "SO_RCVTIMEO: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_TYPE, &optionValue, &optionLength);
    cout << "SO_TYPE: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_ERROR, &optionValue, &optionLength);
    cout << "SO_ERROR: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_NOSIGPIPE, &optionValue, &optionLength);
    cout << "SO_NOSIGPIPE: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_NREAD, &optionValue, &optionLength);
    cout << "SO_NREAD: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_NWRITE, &optionValue, &optionLength);
    cout << "SO_NWRITE: " << optionValue << ", size: " << optionLength << endl;

    optionValue = 0;
    optionLength = sizeof(optionValue);
    getsockopt(this->clientSocketFD, SOL_SOCKET, SO_LINGER_SEC, &optionValue, &optionLength);
    cout << "SO_LINGER_SEC: " << optionValue << ", size: " << optionLength << endl;
}

void Program::setSockOpt(void) {
    long long optionValue = 1;
    socklen_t optionLength = sizeof(optionValue);
    setsockopt(this->clientSocketFD, SOL_SOCKET, SO_DEBUG, &optionValue, optionLength);
    cout << "SO_DEBUG: " << optionValue << ", size: " << optionLength << endl;
}

void Program::sendBigString(void) {
    std::string bigString = std::string(10, '1');
    ssize_t sendSize = ::send(this->clientSocketFD, bigString.c_str(), 10, 0);
    if (sendSize == -1)
        cout << "send error has occured" << endl;
    else
        cout << "sended big string" << endl;
}

void Program::closeServerSocket(void) {
    ::close(this->serverSocketFD);
    this->serverSocketFD = -1;

    cout << "closed server socket" << endl;
}

void Program::closeClientSocket(void) {
    ::close(this->clientSocketFD);
    this->clientSocketFD = -1;

    cout << "closed client socket" << endl;
}

void Program::close(void) {
    this->closeClientSocket();
    this->closeServerSocket();
}

void Program::recv(void) {
    char buf[BUF_SIZE + 1];
    ssize_t recvSize = ::recv(this->clientSocketFD, buf, BUF_SIZE, 0);
    if (recvSize == -1)
        throw "recv error has occured";
    else if (recvSize == 0)
        throw "no data";

    buf[recvSize] = '\0';

    cout << "received size: " << recvSize << endl;
    for (int index = 0; index < recvSize; index += 16) {
        print16Bytes(std::string(buf + index, buf + index + 16));
    }
}

void Program::send(void) {
    cout << "enter line to send[exit: q]:" << endl;
    std::string requestMessage;
    while (true) {
        std::string line;
        getline(cin, line);
        if (line == "q")
            break;
        requestMessage += line + "\r\n";
    }

    ssize_t result = ::send(this->clientSocketFD, requestMessage.c_str(), requestMessage.length(), 0);
    if (result <= 0)
        throw "result of send <= 0";
    cout << "succeeded send" << endl;
}

void Program::connectRemote(void) {
    int serverSocketFD;
	struct sockaddr_in serverSocketAddress;
    std::string serverInetAddressString;
    unsigned long serverInetAddress;
    std::string serverPortNumberString;
    uint16_t serverPortNumber;
    int result;

    serverSocketFD = socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocketFD == -1)
		throw "socket()";

    cout << "enter inet address of server: ";
    getline(cin, serverInetAddressString);
    serverInetAddress = inet_addr(serverInetAddressString.c_str());

    cout << "enter port number of server: ";
    getline(cin, serverPortNumberString);
    serverPortNumber = htons(atoi(serverPortNumberString.c_str()));

	memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
	serverSocketAddress.sin_family = AF_INET;
	serverSocketAddress.sin_addr.s_addr = serverInetAddress;
	serverSocketAddress.sin_port = serverPortNumber;

	result = connect(serverSocketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));
    fcntl(serverSocketFD, F_SETFL, O_NONBLOCK); // connect 전에 non-blocking으로 만들면 connect 에러가 발생한다 ㅎㅎ
    if (result == -1)
		throw "connect()";

    printSuccessMessage("connect()");

    this->remoteServerSocketFD = serverSocketFD;
    this->remoteServerSocketAddress = serverSocketAddress;
}

void Program::sendRemote(void) {
    std::string data;
    getMultiLine(cin, "enter line to send: ", data, "q", "\r\n");

    ssize_t result = ::send(this->remoteServerSocketFD, data.c_str(), data.length(), 0);
    if (result <= 0)
        throw "result of send <= 0";
    printSuccessMessage("send() to remote");
}

void Program::sendFileToRemote(void) {
    std::string fileName;
    struct stat fileStatus;
    ssize_t result;

    getSingleLine(cin,  "enter file name to send: ", fileName);

    if (stat(fileName.c_str(), &fileStatus) == -1)
        throw "stat()";

    if (!S_ISREG(fileStatus.st_mode))
        throw "not a regular file";

    off_t fileSize = fileStatus.st_size;
    cout << "file size: " << fileSize << endl;

    std::string header;
    getMultiLine(cin, "enter header", header, "q", "\r\n");
    result = ::send(this->remoteServerSocketFD, header.c_str(), header.length(), 0);
    if (result <= 0)
        throw "result of send <= 0";

    int fileFD = open(fileName.c_str(), O_RDONLY);
    char buf[BUF_SIZE];
    while (true) {
        result = ::read(fileFD, buf, BUF_SIZE - 1);
        if (result == -1)
            throw "read() file";
        else if (result == 0)
            break;
        else {
            result = ::send(this->remoteServerSocketFD, buf, result, 0);
            if (result == -1)
                throw "send() remote";
            else if (result == 0)
                throw "connection closed from remote";
            cout << "sended byte count: " << result << endl;
        }
    }
    printSuccessMessage("send() to remote");
}

void Program::recvRemote(void) {
    char buf[BUF_SIZE + 1];
    ssize_t recvSize = ::recv(this->remoteServerSocketFD, buf, BUF_SIZE, 0);
    if (recvSize == -1)
        throw "recv error has occured";
    else if (recvSize == 0)
        throw "no data";

    buf[recvSize] = '\0';

    cout << "received size: " << recvSize << endl;
    for (int index = 0; index < recvSize; index += 16) {
        print16Bytes(std::string(buf + index, buf + index + 16));
    }
}

void Program::closeRemote(void) {
    if (this->remoteServerSocketFD == -1)
        throw "no remote server socket to close";
    ::close(this->remoteServerSocketFD);
    this->remoteServerSocketFD = -1;
    this->remoteServerSocketAddress = sockaddr_in();

    printSuccessMessage("close() remote socket");
}

void Program::reconnectRemote(void) {
    int serverSocketFD;
	struct sockaddr_in serverSocketAddress;
    std::string serverInetAddressString;
    std::string serverPortNumberString;
    int result;

    if (this->remoteServerSocketFD == -1) {
        this->connectRemote();
        return;
    }

    serverSocketAddress = this->remoteServerSocketAddress;

    this->closeRemote();

    serverSocketFD = socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocketFD == -1)
		throw "socket()";

	result = connect(serverSocketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));
    fcntl(serverSocketFD, F_SETFL, O_NONBLOCK); // connect 전에 non-blocking으로 만들면 connect 에러가 발생한다 ㅎㅎ
    if (result == -1)
		throw "connect()";

    printSuccessMessage("connect()");

    this->remoteServerSocketFD = serverSocketFD;
    this->remoteServerSocketAddress = serverSocketAddress;
}



// MARK: - program
void Program::mainLoop(void) {
    std::string line;

    while (true) {
        cout << endl << "enable command list:" << endl;
        Program::describeMethodCommand();
        cout << "--------------" << endl;
        getSingleLine(cin, "enter command: ", line);

        unsigned long i;
        for (i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
            const MethodPair* pair = &methodDictionary[i];

            if (line == pair->command)
                break;
        }
        if (i == sizeof(methodDictionary) / sizeof(MethodPair)) {
            cout << "not found: [" << line << "]" << endl;
            continue;
        }
        try {
            const MethodPair* pair = &methodDictionary[i];
            (this->*(pair->method))();
        } catch(const char* string) {
            cout << line << ": ";
            printFailMessage(string);
            cout << "errno: " << errno << endl;
        }
    }
}



// MARK: - static
void Program::describeMethodCommand(void) {
    for (unsigned long i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
        const MethodPair& pair = methodDictionary[i];

        cout << "\t" << pair.command << endl;
    }
}



// MARK: - main
int main(void) {
    Program program;

    program.mainLoop();

    return 0;
}
