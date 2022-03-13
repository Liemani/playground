#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define EXECUTE getttyent_example

#include <ttyent.h>

void	getttyent_example()
{
	struct ttyent	*tty_entry;
	tty_entry = getttyent();
	printf("tty_entry->ty_name -> [%s] \n", tty_entry->ty_name);
	printf("tty_entry->ty_getty -> [%s] \n", tty_entry->ty_getty);
	printf("tty_entry->ty_type -> [%s] \n", tty_entry->ty_type);
}

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
