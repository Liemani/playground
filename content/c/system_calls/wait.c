#include <unistd.h>	// fork(), pid_t, sleep(), getpgid(), execve()
#include <stdio.h>	// printf(), perror()
#include <stdlib.h>	// exit(), NULL
#include <sys/wait.h>	// wait()
#include <signal.h>	// signal()

#define NORMAL	0
#define ERROR	1



///	- If option of waitpid() is WNOHANG, and there is no terminated process at that time,
///		waitpid() returns 0.
///	- If terminal get signal, it propagate the signal to the child process.
///	- But i send a signal by kill command on cli, it seems not propagated to child process.



typedef void	(*t_signal_handler)(int);

void	nothing(int a)
{
	(void)a;
}

static void	signal_set(int signal_number, t_signal_handler handler)
{
	signal(signal_number, handler);
}

static void	signal_set_parent(void)
{
	signal_set(SIGINT, SIG_IGN);
}

static void	signal_set_child(void)
{
	signal_set(SIGINT, SIG_DFL);
}



void	child(char **envp)
{
	char	*argv[3];
	(void)envp;

	signal_set_child();
	argv[0] = "sleep";
	argv[1] = "10";
	argv[2] = NULL;
	execve("/bin/sleep", argv, envp);
}

void	parent(pid_t pid)
{
	int		stat_loc;
	pid_t	waited_process;

	waited_process = waitpid(pid, &stat_loc, 0);
	printf("waited_process: [%d]. \n", waited_process);
	printf("stat_loc: [%d]. \n", stat_loc);
}



int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	pid_t	pid;

	signal_set_parent();

	pid = 0;

	pid = fork();
	if (pid == -1)
		return (ERROR);
	else if (pid == 0)
		child(envp);

	parent(pid);

	return (NORMAL);
}
