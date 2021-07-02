#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

char	*signals[31] = {
	"SIGHUP",		// 1
	"SIGINT",		// 2
	"SIGQUIT",		// 3
	"SIGILL",		// 4
	"SIGTRAP",		// 5
	"SIGABRT",		// 6
	"SIGEMT",		// 7
	"SIGFPE",		// 8
	"SIGKILL",		// 9	no overridable
	"SIGBUS",		// 10
	"SIGSEGV",		// 11
	"SIGSYS",		// 12
	"SIGPIPE",		// 13
	"SIGALRM",		// 14
	"SIGTERM",		// 15
	"SIGURG",		// 16
	"SIGSTOP",		// 17	no overridable
	"SIGTSTP",		// 18
	"SIGCONT",		// 19
	"SIGCHLD",		// 20
	"SIGTTIN",		// 21
	"SIGTTOU",		// 22
	"SIGIO",		// 23
	"SIGXCPU",		// 24
	"SIGXFSZ",		// 25
	"SIGVTALRM",	// 26
	"SIGPROF",		// 27
	"SIGWINCH",		// 28
	"SIGINFO",		// 29
	"SIGUSR1",		// 30
	"SIGUSR2"		// 31
};

void	signal_handler(int signal)
{
	printf("Received signal: [%d: %s] \n", signal, signals[signal - 1]);
}

void	nothing(int signal)
{
	printf("Fake signal: [%d: %s] \n", signal, signals[signal - 1]);
}

int	main()
{
	struct sigaction	*p_sa;
	int					index;

	p_sa = malloc(sizeof(struct sigaction));
	p_sa->sa_handler = signal_handler;
	sigemptyset(&p_sa->sa_mask);
	p_sa->sa_flags = 0;
	index = 1;
	while (index < 32)
	{
		if (index == SIGKILL || index == SIGSTOP)
		{
			++index;
			continue ;
		}
		if (sigaction(index, p_sa, NULL) == -1)
		{
			printf("Sigaction error occured: [%d] \n", index);
			return (1);
		}
		++index;
	}
	p_sa->sa_handler = nothing;
	while (1)
		pause();
	return (0);
}
