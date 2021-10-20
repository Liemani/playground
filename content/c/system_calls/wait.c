#include <unistd.h>	// fork(), pid_t, sleep()
#include <stdio.h>	// printf()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	Now let child1 sleep for a short time to exit after child2.
/// And I will put sleep to parent also.
///	If there is no sleep in parent, it wait child2 first, and wait child1 second.
/// There is no things to think.
///	I want to see child2 exit, child1 exit, and parent wait.

///	- result:
///		This is child2 process.
///		This is child1 process.
///		pid1: [10664].
///		pid2: [10665].
///		pid waited: [10665].
///		stat_loc: [768].
///		pid waited: [10664].
///		stat_loc: [512].
///	- parent's first wait() returned pid of child2.
///	- We can assume that when child process call exit(),
///		the status is saved on queue buffer.
///	- So when we request the data by calling wait(),
///		the first exited process data is returned.

///	- But it is difficult to be certain that
///		all wait() work like queue structure.
///		- If the man page doesn't mention about that feature,
///			that can not be a common behavior.
///		- For this reason, it is best to avoid using such features undescribed on documentation.

///	- Now let's dig into the wait4() function.

void	child1()
{
	sleep(1);
	printf("This is child1 process. \n");
	exit(2);
}

void	child2()
{
	printf("This is child2 process. \n");
	exit(3);
}

void	parent(pid_t pid1, pid_t pid2)
{
	pid_t	wait_pid;
	int		stat_loc;

	sleep(1);
	printf("pid1: [%d]. \n", pid1);
	printf("pid2: [%d]. \n", pid2);

	wait_pid = wait(&stat_loc);
	printf("pid waited: [%d]. \n", wait_pid);
	printf("stat_loc: [%d]. \n", stat_loc);
	wait_pid = wait(&stat_loc);
	printf("pid waited: [%d]. \n", wait_pid);
	printf("stat_loc: [%d]. \n", stat_loc);
}



int	main()
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		return (ERROR);
	else if (pid1 == 0)
		child1();

	pid2 = fork();
	if (pid2 == -1)
		return (ERROR);
	else if (pid2 == 0)
		child2();

	parent(pid1, pid2);

	return (NORMAL);
}
