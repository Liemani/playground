#include "lmt.h"

typedef struct	s_test
{
	int			int_value;
	long		long_value;
	int			second_int_value;
	long		second_long_value;
	char		array[100];
}				t_test;

int	main(void)
{
	t_test	test;

	PRINT(sizeof(test), lu);
	return (0);
}
