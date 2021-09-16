#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define EXECUTE isatty_example

void	isatty_example()
{
	const char *tty_path = "/dev/ttys0";
	char	*tty_name;
	int	tty_fd;

	tty_fd = open(tty_path, O_RDWR);
	if (tty_fd == -1)
	{
		printf("failed opening [%s] \n", tty_path);
		close(tty_fd);
		return;
	}

	printf("success opening [%s] \n", tty_path);
	if (!isatty(tty_fd))
		printf("false [%d] is not a fd of a tty \n", tty_fd);

	printf("true [%d] is a fd of a tty \n", tty_fd);
	tty_name = ttyname(tty_fd);
	printf("The ttyname of [%d] is [%s] \n", tty_fd, tty_name);

	close(tty_fd);
}

int	main()
{
	EXECUTE();
	return (0);
}
