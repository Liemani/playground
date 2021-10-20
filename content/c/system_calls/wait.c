#include <unistd.h>	// fork(), pid_t, sleep()
#include <stdio.h>	// printf()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	- What if there is several child rather than only 1?
///	- Would the order of calling exit() between child be important of the operating of wait()?

///	- I called fork() twice, and wait() twice also.
///	- result:
///		pid1: [9277].
///		pid2: [9278].
///		This is child1 process.
///		This is child2 process.
///		pid waited: [9277].
///		stat_loc: [512].
///		pid waited: [9278].
///		stat_loc: [768].
///	- We can earn exit code from stat_loc.
///		- exit_code = (stat_loc >> 8) & 0x000000ff;
///		- So the value of stat_loc set by wait() is normal.

///	Now let child1 sleep for a short time to exit after child2.
/// And I will put sleep to parent also.
///	If there is no sleep in parent, it wait child2 first, and wait child1 second.
/// There is no things to think.
///	I want to see child2 exit, child1 exit, and parent wait.

void	child1()
{
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
