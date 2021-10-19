#include <unistd.h>	// fork(), pid_t, sleep()
#include <stdio.h>	// printf()
#include <stdlib.h>	// exit()

#define NORMAL	0
#define ERROR	1



void	child()
{
	printf("This is child process. \n");
	exit(NORMAL);
}

void	parent()
{
	sleep(1);
	printf("This is parent process. \n");
}



///	- If parent sleep for a short time, child print string first.
int	main()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ERROR);
	else if (pid == 0)
		child();
	else
		parent();
	return (NORMAL);
}
