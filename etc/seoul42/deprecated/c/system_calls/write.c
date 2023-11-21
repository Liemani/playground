#include <stdio.h>	// printf()
#include <stdlib.h>	// atoi()
#include <unistd.h>	// write()

int	main(int argc, char **argv)
{
	ssize_t	return_value;
	if (argc != 3)
	{
		printf("usage: %s <string to write> <length to write> \n", argv[0]);
		return (0);
	}
	return_value = write(1, argv[1], atoi(argv[2]));
	printf("\nreturn_value: [%zd] \n", return_value);
	return (0);
}
