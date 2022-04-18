//	#include <arpa/inet.h>
//		uint16_t htons(uint16_t hostshort);
//		uint32_t htonl(uint32_t hostlong);
//		uint16_t ntohs(uint16_t netshort);
//		uint32_t ntohl(uint32_t netlong);
//		in_addr_t inet_addr(const char *cp);
//
//	#include <sys/select.h>
//		void FD_CLR(fd, fd_set *fdset);
//		void FD_COPY(fd_set *fdset_orig, fd_set *fdset_copy);
//		int FD_ISSET(fd, fd_set *fdset);
//		void FD_SET(fd, fd_set *fdset);
//		void FD_ZERO(fd_set *fdset);
//		int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);
//
//	#include <poll.h>
//		int poll(struct pollfd fds[], nfds_t nfds, int timeout);
//	epoll(epoll_create, epoll_ctl, epoll_wait)
//
//	#include <sys/types.h>
//	#include <sys/event.h>
//	#include <sys/time.h>
//		int kqueue(void);
//		int kevent(int kq, const struct kevent *changelist, int nchanges, struct kevent *eventlist, int nevents, const struct timespec *timeout);
//
//	#include <sys/socket.h>
//		int socket(int domain, int type, int protocol);
//		int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
//		int listen(int socket, int backlog);
//		ssize_t send(int socket, const void *buffer, size_t length, int flags);
//		ssize_t recv(int socket, void *buffer, size_t length, int flags);
//		int bind(int socket, const struct sockaddr *address, socklen_t address_len);
//		int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
//		int getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
//	#include <sys/types.h>
//	#include <sys/socket.h>
//		int connect(int socket, const struct sockaddr *address, socklen_t address_len);
//
//	#include <fcntl.h>
//		int fcntl(int fildes, int cmd, ...);

#include <iostream>

using std::cout;
using std::endl;

#include <arpa/inet.h>	// inet_addr()
#include <netinet/in.h>	// struct sockaddr_in
#include <sys/socket.h>	// socket(), accept(), listen(), bind(), connect()
#include <unistd.h>	// read(),write()
#include <sys/time.h>
#include <fcntl.h>
#include <sys/select.h>
#include <errno.h>

void coutWithTime(const char* str);
void throwRuntimeError(const char* str);

#ifdef CLIENT

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "usage: " << argv[0] << " <server ip> <server port>" << endl;
		return 0;
	}

	//	socket()
	int client = socket(PF_INET, SOCK_STREAM, 0);
	if (client == -1)
		throwRuntimeError("fail socket()");
	else
		coutWithTime("success socket()");

	//	struct sockaddr_in
	struct sockaddr_in serverSocketAddress;
	memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
	serverSocketAddress.sin_family = AF_INET;
	serverSocketAddress.sin_addr.s_addr = inet_addr(argv[1]);
	serverSocketAddress.sin_port = htons(atoi(argv[2]));

	//	connect()
	if (connect(client, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress)) == -1)
		throwRuntimeError("fail connect()");
	else
		coutWithTime("success connect()");

	const char* message = "Hello, world!";
	sleep(2);
	if (write(client, message, sizeof(message) - 1) == -1)
		throwRuntimeError("fail read()");
	else
		coutWithTime("success write()");

	close(client);

	return 0;
}
#endif

#ifdef SERVER
void describeFDSET(fd_set& set);
int lmiBind(int serverSocket, char* argv[]);

char msg[1024];
fd_set readfds;
fd_set writefds;
fd_set errorfds;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "usage: " << argv[0] << " <server port>" << endl;
		return 0;
	}

	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&errorfds);

	//	socket()
	int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
		throwRuntimeError("fail socket()");
	else
		coutWithTime("success socket()");
	fcntl(serverSocket, F_SETFL, O_NONBLOCK);

	//	bind()
	if (lmiBind(serverSocket, argv))
		throwRuntimeError("fail bind()");
	else
		coutWithTime("success bind()");

	//	listen()
	if (listen(serverSocket, 5) == -1)
		throwRuntimeError("fail listen()");
	else
		coutWithTime("success listen()");

	int clientSocket;
	int maxSocketCount = 0;
	struct timeval timeout = { 0, 0 };
	timeout.tv_sec = 1;
	while (true) {
		cout << endl;

		//	struct sockaddr_in
		struct sockaddr_in clientAddress;
		socklen_t clientAddress_size = sizeof(clientAddress);

		//	accept()
		clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &clientAddress_size);
		if (clientSocket == -1) {
			coutWithTime("fail accept()");
		}
		else {
			coutWithTime("success accept()");
			FD_SET(clientSocket, &readfds);
			if (maxSocketCount < clientSocket)
				maxSocketCount = clientSocket;
		}

		describeFDSET(readfds);

		int result = select(maxSocketCount + 1, &readfds, &writefds, &errorfds, &timeout);
		if (result == -1)
			throwRuntimeError("fail select");
		else if (result == 0) {
			cout << "not read for reading" << endl;
		}
		else {
			cout << "result: " << result << endl;
			if (read(clientSocket, msg, sizeof(msg)) == -1)
				coutWithTime("fail read");
			else {
				coutWithTime("success read()");
				cout << msg << endl;
			}
		}
	}

	close(clientSocket);
	close(serverSocket);

	return 0;
}

void describeFDSET(fd_set& set) {
	for (int i = 0; i < 16; ++i)
		cout << set.fds_bits[i] << ' ';
	cout << endl;
}

int lmiBind(int serverSocket, char* argv[]) {
	struct sockaddr_in serverSocketAddress;
	memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
	serverSocketAddress.sin_family = AF_INET;
	serverSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverSocketAddress.sin_port = htons(atoi(argv[1]));

	return bind(serverSocket, (struct sockaddr*) &serverSocketAddress, sizeof(serverSocketAddress));
}
#endif

void coutWithTime(const char* str) {
	timeval tv;
	gettimeofday(&tv, NULL);
	cout << "[" << tv.tv_sec << "." << tv.tv_usec << "] " << str << endl;
}

void throwRuntimeError(const char* str) {
	throw std::runtime_error(str);
}
