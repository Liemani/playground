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
#include <iomanip>

using std::cout;
using std::endl;

#include <arpa/inet.h>	// inet_addr()
#include <netinet/in.h>	// struct sockaddr_in
#include <sys/socket.h>	// socket(), accept(), listen(), bind(), connect()
#include <sys/time.h>
#include <fcntl.h>
#include <sys/select.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>

template <typename Printable>
void coutWithTime(Printable str);
void throwRuntimeError(const char* str);

template <typename T, typename DescribeFunction>
void describeEveryNth(T target, int index, DescribeFunction f);

#ifdef CLIENT

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "usage: " << argv[0] << " <server ip> <server port>" << endl;
		return 0;
	}

	//	socket()
	int server = socket(PF_INET, SOCK_STREAM, 0);
	if (server == -1)
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
	if (connect(server, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress)) == -1)
		throwRuntimeError("fail connect()");
	else
		coutWithTime("success connect()");

	std::string message;
	while (true) {
		std::getline(std::cin, message);
		if (send(server, message.c_str(), message.size(), 0) == -1)
			throwRuntimeError("fail write()");
		else
			coutWithTime("success write()");
	}

	close(server);

	return 0;
}
#endif

#ifdef SERVER
void describeFDSET(fd_set& set);
int lmiBind(int serverSocket, char* argv[]);

int main(int argc, char* argv[]) {
	char msg[1024];
	struct pollfd pollfd[32] = {};

	if (argc != 2) {
		cout << "usage: " << argv[0] << " <server port>" << endl;
		return 0;
	}

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

	int clientSocket = -1;
	int clientSocketCount = 0;
	struct timeval timeout = { 0, 0 };
	timeout.tv_usec = 1;
	int index = 0;
	int result;
	while (true) {
		//	struct sockaddr_in
		struct sockaddr_in clientAddress;
		socklen_t clientAddress_size = sizeof(clientAddress);

		//	accept()
		result = accept(serverSocket, (struct sockaddr*) &clientAddress, &clientAddress_size);
		if (result == -1) {
			describeEveryNth("fail accept()", index, coutWithTime<const char*>);
		}
		else {
			pollfd[clientSocketCount].fd = result;
			pollfd[clientSocketCount].events = POLLRDNORM;
			++clientSocketCount;
			describeEveryNth("success accept()", index, coutWithTime<const char*>);
		}

		result = poll(pollfd, 32, 1);

		describeEveryNth("select result: ", index, coutWithTime<const char*>);
		describeEveryNth(result, index, coutWithTime<int>);
		if (result == -1)
			throwRuntimeError("fail select");
		else if (result == 0) {
			describeEveryNth("no readfd to read", index, coutWithTime<const char*>);
		}
		else {
			int eventCount = result;
			for (int i = 0; eventCount > 0 && i < clientSocketCount; ++i) {
				if (pollfd[i].revents == 0)
					continue;
				else if (pollfd[i].revents & POLLRDNORM) {
					clientSocket = pollfd[i].fd;
					result = recv(clientSocket, msg, sizeof(msg), 0);
					describeEveryNth("read result: ", index, coutWithTime<const char*>);
					describeEveryNth(result, index, coutWithTime<int>);
					if (result == -1) {
						describeEveryNth("fail read", index, coutWithTime<const char*>);
						describeEveryNth("errno: ", index, coutWithTime<const char*>);
						describeEveryNth(errno, index, coutWithTime<int>);
					}
					else if (result == 0) {
						describeEveryNth("result is 0", index, coutWithTime<const char*>);
					}
					else {
						coutWithTime("success read()");
						cout << msg << endl;
					}
					--eventCount;
				}
			}
		}

		describeEveryNth("\n", index, coutWithTime<const char*>);

		++index;
	}

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

template <typename T, typename DescribeFunction>
void describeEveryNth(T target, int index, DescribeFunction f) {
	if (index % 2000 == 0)
		f(target);
}

template <typename Printable>
void coutWithTime(Printable str) {
	timeval tv;
	gettimeofday(&tv, NULL);
	cout << "[" << tv.tv_sec << "." << std::setw(6) << tv.tv_usec << "] " << str << endl;
}

void throwRuntimeError(const char* str) {
	throw std::runtime_error(str);
}
