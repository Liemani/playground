#include <unistd.h>	// fork(), pid_t, sleep(), getpgid()
#include <stdio.h>	// printf(), perror()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	- Now let's dig into the wait4() function.

///	- man page said, "If pid is -1, the call waits for any child process.".
///	- If there is no child process ever, or additional child process to wait, what would be happended?

///	- call fork() only 1 time, and wait() twice.
///	- result:
///		pid1: [70390]. 
///		pid2: [0]. 
///		This is child1 process. 
///		pid waited: [70390]. 
///		stat_loc: [512]. 
///		ERROR: Undefined error: 0
///		pid waited: [-1]. 
///		stat_loc: [512]. 
///		ERROR: No child processes

///	- Because there was no more child process in second call of wait(), it  returned -1.

///	- todo:
///		- print pgid of parent and child process.
///		- print rusage.



void	child1()
{
	printf("This is child1 process. \n");
	exit(2);
}

//	void	child2()
//	{
//		printf("This is child2 process. \n");
//		exit(3);
//	}

void	parent(pid_t pid1, pid_t pid2)
{
	pid_t	wait_pid;
	int		stat_loc;

	printf("pid1: [%d]. \n", pid1);
	printf("pid2: [%d]. \n", pid2);

	wait_pid = wait4(-1, &stat_loc, 0, 0);
	printf("pid waited: [%d]. \n", wait_pid);
	printf("stat_loc: [%d]. \n", stat_loc);
	perror("ERROR");
	wait_pid = wait4(-1, &stat_loc, 0, 0);
	printf("pid waited: [%d]. \n", wait_pid);
	printf("stat_loc: [%d]. \n", stat_loc);
	perror("ERROR");
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

//		pid2 = fork();
//		if (pid2 == -1)
//			return (ERROR);
//		else if (pid2 == 0)
//			child2();

	parent(pid1, pid2);

	return (NORMAL);
}
