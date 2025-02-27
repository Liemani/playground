#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstddef>

#include "hex_dump.h"

using std::cin;
using std::cout;
using std::endl;

static void getline(std::istream& istream, std::string& line);
static void sockaddr_in_describe(struct sockaddr_in& socketAddress);
static void describe_socket(int fd);

const int BUF_SIZE = 8192;

template <typename T, typename U>
struct Pair {
  T command;
  U method;
};

class Program
{
private:
  typedef void* (Program::*Method)();
  typedef Pair<const char*, Method> MethodPair;

  enum Sockets_offset
  {
    server,
    connection,
    client,
    count,
  };

  const char* sockets_offset_to_string[3] = {
    "server",
    "connection",
    "client",
  };

  int sockets[Sockets_offset::count];

  int& server_socket;
  int& connection_socket;
  int& client_socket;

  static void describeMethodCommand();
  uint16_t read_port_number();
  void close_socket(int sockets_offset);

  void* describe();
  void* listen();
  void* accept();
  void* describeSocketOption();
  void* connection_send_big_string();
  void* close_server_socket();
  void* close_connection_socket();
  void* close_client_socket();
  void* close_all_sockets();
  void* connection_receive();
  void* connection_send();
  void* connect();
  void* client_send();
  void* client_receive();
//  void* reconnectRemote();

  static const MethodPair methodDictionary[];

public:
  Program();

  void mainLoop();
};

const Program::MethodPair Program::methodDictionary[] = {
  { "describe", &Program::describe },
  { "listen", &Program::listen },
  { "accept", &Program::accept },
  { "describe socket", &Program::describeSocketOption },
  { "connection send big string", &Program::connection_send_big_string },
  { "close server socket", &Program::close_server_socket },
  { "close connection socket", &Program::close_connection_socket },
  { "close client socket", &Program::close_client_socket },
  { "close all sockets", &Program::close_all_sockets },
  { "connection recv", &Program::connection_receive },
  { "connection send", &Program::connection_send },
  { "connect", &Program::connect },
  { "client send", &Program::client_send },
  { "client recv", &Program::client_receive },
//  { "reconnect remote", &Program::reconnectRemote },
};

void* Program::describe() {
  for (int i = 0; i < Sockets_offset::count; ++i)
  {
    const int socket = this->sockets[i];

//    if (socket == -1)
//    {
//      continue;
//    }

    cout << sockets_offset_to_string[i] << " : " << endl;
    describe_socket(socket);
    cout << endl;
  }

  return NULL;
}

uint16_t Program::read_port_number() {
  uint16_t port_number;

  cout << "enter port number : ";
  std::string line;
  getline(cin, line);
  std::istringstream inputStringStream(line);
  inputStringStream >> port_number;
  if (!inputStringStream)
    throw "fail getting port number";
  else
    cout << "port number : " << port_number << endl;

  return port_number;
}

void* Program::listen() {
  const uint16_t port_number = this->read_port_number();

  this->server_socket = socket(PF_INET, SOCK_STREAM, 0);
  fcntl(this->server_socket, F_SETFL, O_NONBLOCK);

  struct sockaddr_in serverSocketAddress;
  memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
  serverSocketAddress.sin_family = AF_INET;
  serverSocketAddress.sin_port = htons(port_number);
  serverSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(this->server_socket, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress)) == -1)
    throw "failed binding";

  ::listen(this->server_socket, 5);

  cout << "listening " << port_number << endl;

  return NULL;
}

void* Program::accept() {
  if (this->connection_socket != -1)
    throw "No sit, sorry";

  struct sockaddr clientSocketAddress;
  socklen_t clientSocketAddressSize = sizeof(clientSocketAddress);
  this->connection_socket = ::accept(this->server_socket, &clientSocketAddress, &clientSocketAddressSize);
  if (this->connection_socket == -1)
    cout << "fail accept" << endl;
  else
    cout << "success accept" << endl;

  return NULL;
}

void* Program::describeSocketOption() {
  int optionValue;
  socklen_t optionLength = sizeof(optionValue);

  getsockopt(this->connection_socket, SOL_SOCKET, SO_SNDBUF, &optionValue, &optionLength);

  cout << "SO_SNDBUF : " << optionValue << ", size : " << optionLength << endl;

  return NULL;
}

void* Program::connection_send_big_string() {
  std::string bigString = std::string(10, '1');
  ssize_t sendSize = ::send(this->connection_socket, bigString.c_str(), 10, 0);
  if (sendSize == -1)
    cout << "send error has occured" << endl;
  else
    cout << "sended big string" << endl;

  return NULL;
}

void* Program::close_server_socket() {
  this->close_socket(Sockets_offset::connection);
  this->close_socket(Sockets_offset::server);

  return NULL;
}

void* Program::close_connection_socket() {
  this->close_socket(Sockets_offset::connection);

  return NULL;
}

void* Program::close_client_socket() {
  this->close_socket(Sockets_offset::client);

  return NULL;
}

void Program::close_socket(int sockets_offset)
{
  int& socket = this->sockets[sockets_offset];
  ::close(socket);
  socket = -1;

  cout << sockets_offset_to_string[sockets_offset] << " socket is closed" << endl;
}

void* Program::close_all_sockets() {
  this->close_server_socket();
  this->close_client_socket();

  return NULL;
}

void* Program::connection_receive() {
  char buf[BUF_SIZE + 1];
  ssize_t recvSize = ::recv(this->connection_socket, buf, BUF_SIZE, 0);
  if (recvSize == -1)
    throw "recv error has occured";
  else if (recvSize == 0)
    throw "no data";

  buf[recvSize] = '\0';

  cout << "received size : " << recvSize << endl;
  hex_dump(reinterpret_cast<unsigned char*>(buf), recvSize);

  return NULL;
}

void* Program::connection_send() {
  cout << "enter line to send : ";
  std::string line;
  getline(cin, line);
  line += "\r\n";
  ssize_t result = ::send(this->connection_socket, line.c_str(), line.length(), 0);
  if (result <= 0)
    throw "result of send <= 0";
  cout << "succeeded send" << endl;

  return NULL;
}

void* Program::connect() {
  struct sockaddr_in serverSocketAddress;
  std::string serverInetAddressString;
  unsigned long serverInetAddress;
  std::string serverPortNumberString;
  uint16_t serverPortNumber;
  int result;

  this->client_socket = socket(PF_INET, SOCK_STREAM, 0);
  if (this->client_socket == -1)
    throw "fail socket()";

  cout << "enter inet address of server : ";
  getline(cin, serverInetAddressString);
  serverInetAddress = inet_addr(serverInetAddressString.c_str());

  cout << "enter port number of server : ";
  getline(cin, serverPortNumberString);
  serverPortNumber = htons(atoi(serverPortNumberString.c_str()));

  memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
  serverSocketAddress.sin_family = AF_INET;
  serverSocketAddress.sin_addr.s_addr = serverInetAddress;
  serverSocketAddress.sin_port = serverPortNumber;

  result = ::connect(this->client_socket, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));
  fcntl(this->client_socket, F_SETFL, O_NONBLOCK); // connect 전에 non-blocking으로 만들면 connect 에러가 발생한다 ㅎㅎ
  if (result == -1)
    throw "fail connect()";

  cout << "success connect()" << endl;

  return NULL;
}

void* Program::client_send() {
  cout << "enter line to send[exit : q]:" << endl;
  std::string requestMessage;
  while (true) {
    std::string line;
    getline(cin, line);
    if (line == "q")
      break;
    requestMessage += line + "\r\n";
  }

  ssize_t result = ::send(this->client_socket, requestMessage.c_str(), requestMessage.length(), 0);
  if (result <= 0)
    throw "result of send <= 0";
  cout << "succeeded send" << endl;

  return NULL;
}

void* Program::client_receive() {
  char buf[BUF_SIZE + 1];
  ssize_t recvSize = ::recv(this->client_socket, buf, BUF_SIZE, 0);
  if (recvSize == -1)
    throw "recv error has occured";
  else if (recvSize == 0)
    throw "no data";

  buf[recvSize] = '\0';

  cout << "received size : " << recvSize << endl;
  hex_dump(reinterpret_cast<unsigned char*>(buf), recvSize);

  return NULL;
}

//void* Program::reconnectRemote() {
//  int serverSocketFD;
//  struct sockaddr_in serverSocketAddress;
//  std::string serverInetAddressString;
//  std::string serverPortNumberString;
//  int result;
//
//  if (this->client_socket == -1)
//    return this->connect();
//
//  serverSocketAddress = this->remoteServerSocketAddress;
//
//  this->close_client_socket();
//
//  serverSocketFD = socket(PF_INET, SOCK_STREAM, 0);
//  if (serverSocketFD == -1)
//    throw "fail socket()";
//
//  result = connect(serverSocketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));
//  fcntl(serverSocketFD, F_SETFL, O_NONBLOCK); // connect 전에 non-blocking으로 만들면 connect 에러가 발생한다 ㅎㅎ
//  if (result == -1)
//    throw "fail connect()";
//
//  cout << "success reconnect()" << endl;
//
//  this->client_socket = serverSocketFD;
//  this->remoteServerSocketAddress = serverSocketAddress;
//
//  return NULL;
//}



// MARK: - program
Program::Program()
  : server_socket(this->sockets[Sockets_offset::server])
  , connection_socket(this->sockets[Sockets_offset::connection])
  , client_socket(this->sockets[Sockets_offset::client])
{
  for (int i = 0; i < Sockets_offset::count; ++i)
  {
    this->sockets[i] = -1;
  }
}

void Program::mainLoop() {
  std::string line;

  while (true) {
    cout << endl << "enable command list:" << endl;
    Program::describeMethodCommand();
    cout << "--------------" << endl;
    cout << "enter command : ";

    getline(cin, line);

    unsigned long i;
    for (i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
      const MethodPair* pair = &methodDictionary[i];

      if (line == pair->command)
        break;
    }
    if (i == sizeof(methodDictionary) / sizeof(MethodPair)) {
      cout << "not found : [" << line << "]" << endl;
      continue;
    }
    try {
      const MethodPair* pair = &methodDictionary[i];
      (this->*(pair->method))();
    } catch(const char* string) {
      cout << line << " : " << string << endl;
    }
  }
}



// MARK: - static
void Program::describeMethodCommand() {
  for (unsigned long i = 0; i < sizeof(methodDictionary) / sizeof(MethodPair); ++i) {
    const MethodPair& pair = methodDictionary[i];

    cout << "\t" << pair.command << endl;
  }
}

static void getline(std::istream& istream, std::string& line) {
  std::getline(istream, line);
  if (!istream)
    throw "failed getline";
}

static void sockaddr_in_describe(struct sockaddr_in& socket_address) {
  cout << "socket_address.sin_len : " << static_cast<int>(socket_address.sin_len) << endl;
  cout << "socket_address.sin_family : "
    << std::hex << std::setfill('0') << std::setw(2)
    << static_cast<int>(static_cast<unsigned char>(socket_address.sin_family))
    << std::dec << endl;
  cout << "socket_address.sin_port : " << ntohs(socket_address.sin_port) << endl;
  cout << "socket_address.sin_addr : " << inet_ntoa(socket_address.sin_addr) << endl;
  cout << "socket_address.sin_zero : " << endl;
  hex_dump(reinterpret_cast<unsigned char*>(socket_address.sin_zero), sizeof(socket_address.sin_zero));
}

static void describe_socket(int fd)
{
  struct sockaddr_in socket_address;
  socklen_t socket_address_size;

  cout << "fd : " << fd << endl;

  socket_address_size = sizeof(socket_address);
  if (getsockname(fd, reinterpret_cast<struct sockaddr*>(&socket_address), &socket_address_size) == 0)
  {
    cout << "socket address :" << endl;
    sockaddr_in_describe(socket_address);
  }

  socket_address_size = sizeof(socket_address);
  if (getpeername(fd, reinterpret_cast<struct sockaddr*>(&socket_address), &socket_address_size) == 0)
  {
    cout << "peer address :" << endl;
    sockaddr_in_describe(socket_address);
  }
}



// MARK: - main
int main() {
  Program program;

  program.mainLoop();

  return 0;
}
