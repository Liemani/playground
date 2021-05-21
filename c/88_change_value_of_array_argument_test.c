#include "lmt.h"

void	test001(int array[3])
{
	int	second_array[4] = {2, 3, 4, 5};

	PRINT(array[0], d);
	PRINT(array[4], d);
	PRINT(second_array[0], d);
	array = second_array;
	PRINT(array[0], d);
}

int		main(void)
{
	int	array[3] = {1, 2, 3};
	int second_array[4] = {2, 3, 4, 5};

	array = second_array;
	test001(array);
	return (0);
}
