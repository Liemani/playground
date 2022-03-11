#include <stdio.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

void	substitutePoint(t_point *lhs, t_point *rhs)
{
	*lhs = *rhs;
}

int 	main()
{
	t_point	point1;
	t_point	point2;

	point1.x = 12.34;
	point1.y = 23.45;
	point1.z = 34.56;

	printf("(%.2f, %.2f, %.2f) \n", point2.x, point2.y, point2.z);
	substitutePoint(&point2, &point1);
	printf("(%.2f, %.2f, %.2f) \n", point2.x, point2.y, point2.z);

	return (0);
}
