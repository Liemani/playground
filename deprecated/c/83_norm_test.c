#include <stdlib.h>

unsigned int	test001(unsigned int i)
{
	unsigned char	array[4];

	*(unsigned int *)array = i;
	return (*(unsigned char *)&i);
}

typedef	struct	s_test
{
	int			value;
}				t_test;

void			another_function(t_test *p_test)
{
	t_test *const	another_test = p_test;

	(void)another_test;
}

int				main(void)
{
	t_test			*p_test;
	unsigned int	i;

	p_test = malloc(sizeof(t_test));
	another_function(p_test);
	i = 1;
	test001(i);
	return (0);
}
