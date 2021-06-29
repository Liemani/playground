#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main()
{
	pid_t	pid;
	pid_t	child_pid;

	pid = fork();
	printf("pid: %d \n", pid);
	child_pid = wait(NULL);
	printf("child_pid: %d \n", child_pid);
}
