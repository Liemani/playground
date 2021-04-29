#include <stdio.h>
#include <math.h>

#define X 0
#define Y 1
#define Z 2

typedef double		t_vector3[3];

void				vector3_vector_product(const t_vector3 lhs, const t_vector3 rhs, t_vector3 result)
{
	result[X] = lhs[Y] * rhs[Z] - rhs[Y] * lhs[Z];
	result[Y] = lhs[Z] * rhs[X] - rhs[Z] * lhs[X];
	result[Z] = lhs[X] * rhs[Y] - rhs[X] * lhs[Y];
}

void				vector3_describe(const t_vector3 vector)
{
	printf("(%f, %f, %f) \n", vector[X], vector[Y], vector[Z]);
}

int					main()
{
//	const double	fovx = 90;
	const double	fovy = 70;
//	const double	xPercent = 0.1;
	const double	yPercent = 0.1;
//	const double	radx = (fovx * xPercent - fovx / 2) * M_PI / 180;
	const double	rady = -((fovy * yPercent) - fovy / 2) * M_PI / 180;
	const t_vector3	y_p = {0, sin(rady), -cos(rady)};
	const t_vector3	x_axis = {1, 0, 0};
	t_vector3		xy_p_plane;

	printf("rady: %f \n", rady);
	vector3_describe(y_p);

	vector3_vector_product(x_axis, y_p, xy_p_plane);
	vector3_describe(xy_p_plane);

	return (0);
}
