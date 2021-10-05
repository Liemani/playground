#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*string;

	if (argc != 2)
	{
		printf("usage: %s <error code> \n", argv[0]);
		exit(1);
	}

	string = strerror(strtol(argv[1], NULL, 10));
	printf("%s \n", string);
	return(0);
}
