#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please enter only 1 argument! \n");
		return (0);
	}

	if (unlink(argv[1]) == 0)
		printf("[%s] was unlinked! \n", argv[1]);
	else
		printf("failed unlinking [%s]! \n", argv[1]);
	return (0);
}
