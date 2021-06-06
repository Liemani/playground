#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	int count = atoi(argv[1]);
	int is_first = true;
	while (0 < count)
	{
		if (is_first == false)
			printf(" ");
		printf("%d", 2 * count - 1);
		printf(" ");
		printf("%d", 2 * count);
		is_first = false;
		--count;
	}
	printf("\n");
	return (0);
}
