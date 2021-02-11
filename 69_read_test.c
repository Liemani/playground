#include <unistd.h> // read()
// #include <errno.h> // errno
#include <fcntl.h> // open()
#include "lmt.h"

#define file_name "69_read_test.c"
#ifndef BUF_SIZE
# define BUF_SIZE 1024
#endif

int	main(void)
{
	char	buf[BUF_SIZE + 1];
	int		fd;
	ssize_t	bytes_read;
	int		count;

	fd = open(file_name, O_RDONLY);
	count = 0;
	while ((bytes_read = read(fd, buf, BUF_SIZE)) >= 0
			&& count < 3)
	{
		*(buf + bytes_read) = '\0';
		PRINT(bytes_read, zd);
		PRINT(buf, s);
//		PRINT(*buf, d);
//		PRINT(errno, d);
		putchar('\n');
		++count;
	}
	close(fd);
	return (0);
}
