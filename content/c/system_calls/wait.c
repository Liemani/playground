#include <unistd.h>	// fork(), pid_t, sleep(), getpgid()
#include <stdio.h>	// printf(), perror()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	- Next time, let remove that sleep().
///	- This time, parent process rather than child process calls sleep(1).

///	- result:
///		This is child1 process.
///		This is child2 process.
///		pid1: [72662].
///		pid2: [72663].
///		pgid0: [72660], pgid1: [-1], pgid2: [-1].
///	- As expected, getpgid() of terminated process returns -1.

///	- todo:
///		- print rusage.



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
//		pid_t	wait_pid;
	int		stat_loc;
	pid_t	pgid0;
	pid_t	pgid1;
	pid_t	pgid2;

	sleep(1);
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
