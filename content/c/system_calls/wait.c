#include <unistd.h>	// fork(), pid_t, sleep(), getpgid()
#include <stdio.h>	// printf(), perror()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	- print pgid of parent and child process.
///	- man page said that "If the pid parameter of wait4() is 0, the call waits for any child process in the process group of the caller.".
///	- So i want to see the pgid of each process.
///	- I'm not sure if the getpgid() function work for terminated child process.
///	- So i called sleep(1) for each child process.
///	- Next time, let remove that sleep().

///	- result:
///		pid1: [72325].
///		pid2: [72326].
///		pgid0: [72324], pgid1: [72324], pgid2: [72324].
///		This is child2 process.
///		This is child1 process.
///	- Parent process and child process's pgid was same.

///	- todo:
///		- print rusage.



void	child1()
{
	sleep(1);
	printf("This is child1 process. \n");
	exit(2);
}

void	child2()
{
	sleep(1);
	printf("This is child2 process. \n");
	exit(3);
}

void	parent(pid_t pid1, pid_t pid2)
{
//		pid_t	wait_pid;
	int		stat_loc;
	pid_t	pgid0;
	pid_t	pgid1;
	pid_t	pgid2;

	printf("pid1: [%d]. \n", pid1);
	printf("pid2: [%d]. \n", pid2);

	pgid0 = getpgid(getpid());
	pgid1 = getpgid(pid1);
	pgid2 = getpgid(pid2);
	printf("pgid0: [%d], pgid1: [%d], pgid2: [%d]. \n", pgid0, pgid1, pgid2);

	wait(&stat_loc);
	wait(&stat_loc);
}



int	main()
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = 0;
	pid2 = 0;

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
