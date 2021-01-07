#include <unistd.h> // read()
#include <errno.h> // errno
#include <fcntl.h> // open()
#include "lmt.h"

#define file_name "test.txt"

int	main(void)
{
	char	buf[10];
	int		fd;
	ssize_t	result;

	fd = open(file_name, O_RDONLY);
	PRINT(*buf, d);
	PRINT(*buf, c);
	PRINT(errno, d);
	putchar('\n');

	for (int i = 0; i < 3; ++i)
	{
		result = read(fd, buf, 1);
		PRINT(result, zd);
		PRINT(*buf, d);
		PRINT(*buf, c);
		PRINT(errno, d);
		putchar('\n');
	}

	return (0);
}
