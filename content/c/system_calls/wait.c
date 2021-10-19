#include <unistd.h>	// fork(), pid_t, sleep()
#include <stdio.h>	// printf()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



void	child()
{
	printf("This is child process. \n");
	exit(NORMAL);
}

void	parent(pid_t child_pid)
{
	pid_t	wait_pid;
	int		stat_loc;

	printf("This is parent process. \n");
	wait_pid = wait(&stat_loc);
	printf("Child pid was [%d]. \n", child_pid);
	printf("I(parent) waited [%d]. \n", wait_pid);
	printf("And stat_loc was [%d]. \n", stat_loc);
	wait_pid = wait(&stat_loc);
	printf("Wait again without child. \n");
	printf("Reurned pid is [%d]. \n", wait_pid);
	printf("And stat_loc was [%d]. \n", stat_loc);
}



///	- If I try to wait again without additional child, wait() returns -1.
///	- And stat_loc steal 0.
int	main()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ERROR);
	else if (pid == 0)
		child();
	else
		parent(pid);
	return (NORMAL);
}
