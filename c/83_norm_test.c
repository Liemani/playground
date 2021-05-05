#include <stdlib.h>

typedef	struct	s_test
{
	int			value;
}				t_test;

void			another_function(t_test *p_test)
{
	t_test	*another_test = p_test;

	(void)another_test;
}

int				main(void)
{
	t_test	*p_test;

	p_test = malloc(sizeof(t_test));
	another_function(p_test);
	return (0);
}
