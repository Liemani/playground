#include <stdio.h>

int	main()
{
	int	array[2] = {1, 2};
	int	**p_array;

	p_array = &array;
	printf("first: %d, second: %d \n", (*p_array)[0], (*p_array)[1]);
	return (0);
}
