#include <unistd.h> // read()
#include <errno.h> // errno
#include <fcntl.h> // open()
#include "lmt.h"

#define file_name "test.txt"
#ifndef BUF_SIZE
# define BUF_SIZE 2
#endif

int	main(void)
{
	char	buf[10];
	int		fd;
	ssize_t	result;

	fd = open(file_name, O_RDONLY);

	for (int i = 0; i < 3; ++i)
	{
		result = read(fd, buf, BUF_SIZE);
		PRINT(result, zd);
		PRINT(*buf, d);
		PRINT(*(buf + 1), d);
		PRINT(errno, d);
		putchar('\n');
	}

	close(fd);
	return (0);
}
