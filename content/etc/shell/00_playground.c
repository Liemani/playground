#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define EXECUTE	a001

void	a001()
{
	int	fd;
	int duplicated_fd;

	fd = open("test", O_WRONLY | O_APPEND);
	dup2(fd, 1);
	printf("This is test message \n");
	duplicated_fd = dup(fd);
	printf("duplicated_fd: [%d] \n", duplicated_fd);
	printf("fd: [%d] \n", fd);
}

void	a000()
{
	pid_t	pid;
	pid_t	child_pid;

	pid = fork();
	printf("pid: %d \n", pid);
	child_pid = wait(NULL);
	printf("child_pid: %d \n", child_pid);
}

int	main(void)
{
	EXECUTE();
	return (0);
}
