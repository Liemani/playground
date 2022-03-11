#include <stdio.h>

typedef int	t_vector3[3];

void	vector3_copy(t_vector3 lhs, t_vector3 rhs)
{
	if (lhs == NULL || rhs == NULL)
		return ;
	lhs[0] = rhs[0];
	lhs[1] = rhs[1];
	lhs[2] = rhs[2];
}

int	main()
{
	t_vector3	lhs;
	t_vector3	rhs;

	rhs[0] = 1;
	rhs[1] = 2;
	rhs[2] = 3;

	printf("%d, %d, %d \n", lhs[0], lhs[1], lhs[2]);
	vector3_copy(lhs, rhs);
	printf("%d, %d, %d \n", lhs[0], lhs[1], lhs[2]);
	vector3_copy(rhs, 0);

	return (0);
}
