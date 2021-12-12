// winsize
// rusage
// pid_t
// __darwin_pid_t
// dirnet
// stat
// pid_t
// __darwin_pid_t
//
// PTHREAD_MUTEX_INITIALIZER
// INT_MAX
// time_t				: long
// suseconds_t			: int
// __darwin_suseconds_t	: int
// useconds_t			: unsigned int
//
// pthread_t			: struct _opaque_pthread_t
//
//struct _opaque_pthread_t {
//	long	__sig;
//	struct	__darwin_pthread_handler_rec  *__cleanup_stack;
//	char	__opaque[__PTHREAD_SIZE__];
//};
//
//struct __darwin_pthread_handler_rec {
//	void	(*__routine)(void *);	// Routine to call
//	void	*__arg;			// Argument to pass
//	struct	__darwin_pthread_handler_rec *__next;
//};
//
//pthread_attr_t
//
//pthread_mutex_t
//
//pthread_mutexattr_t
//
//	#include <stddef.h>
//	#include <errno.h> // errno
//	#include <sys/types.h>
//	#include <sys/uio.h>
//	#include <stdarg.h>
//	#include <wchar.h>
//	#include <stdbool.h>
//	#include <stdlib.h>
//	#include <math.h>
//	#include <limits.h>
//	#include <signal.h>
//	#include <ucontext.h>
//	#include <unistd.h>
//	#include <sys/time.h>
#include <pthread.h>
//	#include <sysexits.h>
//	#include <sys/ioctl.h>
//	#include <termios.h>
//	#include <sys/stat.h>
//	#include <dirent.h>
//	#include <stdio.h>
//	#include <sys/wait.h>
//	#include <term.h>
//	#include <stdio.h>
//	#include <mach-o/loader.h>
//	#include <float.h>

int main(void)
{
//	#ifdef __DARWIN_UNIX03
//		printf("darwin unix03 \n");
//	#else
//		printf("not darwin unix03 \n");
//	#endif
//	#if defined(_POSIX_C_SOURCE) && !defined(_DARWIN_C_SOURCE)
//		printf("true \n");
//	#else
//		printf("false \n");
//	#endif
	return (0);
}
