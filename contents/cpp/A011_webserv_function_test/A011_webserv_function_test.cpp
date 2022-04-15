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

int main(void) {
}
