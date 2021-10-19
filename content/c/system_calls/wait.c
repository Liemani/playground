#include <unistd.h>	// fork(), pid_t, sleep()
#include <stdio.h>	// printf()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



/// - What if parent wait() it's child after the child exit()?
///	- Now parent sleep() for a second.
///	- So child must call exit() before parent call wait().

///	- wait() operated normally with it's already exited child.

///	- What if there is several child rather than only 1?



void	child()
{
	printf("This is child process. \n");
	exit(NORMAL);
}

void	parent(pid_t child_pid)
{
	pid_t	wait_pid;
	int		stat_loc;

	sleep(1);
	wait_pid = wait(&stat_loc);
	printf("Child pid was [%d]. \n", child_pid);
	printf("I(parent) waited [%d]. \n", wait_pid);
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
