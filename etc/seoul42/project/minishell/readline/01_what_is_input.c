#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>	// open()



int	main()
{
	char	*line;
	int		fd;

	fd = open("temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	while ((line = readline("<prompt> ")) != NULL)
	{
		printf("line -> [%s] as %%s \n", line);
		free(line);
	}
	close(fd);

	return (0);
}
