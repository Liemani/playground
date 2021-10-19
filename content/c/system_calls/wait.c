#include <unistd.h>	// fork(), pid_t
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
	printf("This is parent process. \n");
}



///	- Generally, parent print string faster than child.
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
