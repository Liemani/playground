#include <unistd.h>	// fork(), close(), sleep()
#include <fcntl.h>	// open()
#include <stdio.h>	// printf()

int	main()
{
	pid_t	pid;
	int		fd;

	fd = open("temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid = fork();
	if (pid > 0)
	{
		close(fd);
	}
	else
	{
		sleep(1);
		dup2(fd, 1);
		printf("hi\n");
	}

	return (0);
}
