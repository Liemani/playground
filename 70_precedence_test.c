#include <stdlib.h>
#include "lmt.h"

typedef struct	s_test
{
	int			*p_count;
}				t_test;

int main()
{
	t_test	*p_test;
	int		count;
	
	count = 10;
	p_test = malloc(sizeof(*p_test));
	p_test->p_count = &count;
	PRINT(*p_test->p_count, d);
	return (0);
}
