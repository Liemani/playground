#include <unistd.h>	// fork(), pid_t, sleep()
#include <stdio.h>	// printf()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	- Then what if I set stat_loc before first wait()?
///	- stat_loc is changed by first wait().
///	- If wait() finish without error, it set stat_loc.

/// - What if parent wait() it's child after the child exit()?



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
	stat_loc = 1;
	wait_pid = wait(&stat_loc);
	printf("Child pid was [%d]. \n", child_pid);
	printf("I(parent) waited [%d]. \n", wait_pid);
	printf("And stat_loc was [%d]. \n", stat_loc);
	stat_loc = 1;
	wait_pid = wait(&stat_loc);
	printf("Wait again without child. \n");
	printf("Reurned pid is [%d]. \n", wait_pid);
	printf("And stat_loc was [%d]. \n", stat_loc);
}



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
