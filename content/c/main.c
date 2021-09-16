#include <fcntl.h>
#include "lmt.h"

void display_str(char *str);

int main()
{
	int	fd = open("main.c", O_RDONLY);

	PRINT(fd, d);

	while(1);

	return (0);
}
