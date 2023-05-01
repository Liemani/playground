#include <stdio.h>
#include <math.h>

#define X 0
#define Y 1
#define Z 2

typedef double	t_vector3[3];
typedef double	t_matrix3[3][3];

void    vector3_set(t_vector3 vector, double x, double y, double z)
{
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}

double  vector3_magnitude(t_vector3 vector)
{
    return (sqrt(
                + vector[X] * vector[X]
                + vector[Y] * vector[Y]
                + vector[Z] * vector[Z]));
}

void    vector3_copy(t_vector3 lhs, t_vector3 rhs)
{
    lhs[X] = rhs[X];
    lhs[Y] = rhs[Y];
    lhs[Z] = rhs[Z];
}

void    vector3_normalize(t_vector3 vector)
{
    if (vector[X] == 0
            && vector[Y] == 0
            && vector[Z] == 0)
        return ;

    const double magnitude = vector3_magnitude(vector);

    vector[X] /= magnitude;
    vector[Y] /= magnitude;
    vector[Z] /= magnitude;
}

void        matrix3_basis_vector(t_vector3 orientation_vector, t_matrix3 basis_vector)
{
    t_vector3   normalized_orientation;

    vector3_copy(normalized_orientation, orientation_vector);
    vector3_normalize(normalized_orientation);
    if (normalized_orientation[X] == 0
            && normalized_orientation[Z] == 0)
    {
        vector3_set(basis_vector[X], 1.0, 0.0, 0.0);
        vector3_set(basis_vector[Y], 0.0, 0.0, -1.0);
        vector3_set(basis_vector[Z], 0.0, 1.0, 0.0);
        return ;
    }

    const double xz_magnitude = sqrt(
            + normalized_orientation[X] * normalized_orientation[X]
            + normalized_orientation[Z] * normalized_orientation[Z]);

    vector3_set(basis_vector[X],
            -normalized_orientation[Z] / xz_magnitude,
            -normalized_orientation[X] * normalized_orientation[Y] / xz_magnitude,
            -normalized_orientation[X]);
    vector3_set(basis_vector[Y],
            0,
            xz_magnitude,
            -normalized_orientation[Y]);
    vector3_set(basis_vector[Z],
            normalized_orientation[X] / xz_magnitude,
            -normalized_orientation[Y] * normalized_orientation[Z] / xz_magnitude,
            -normalized_orientation[Z]);
}

void        matrix3_multiply_vector3(t_matrix3 matrix, t_vector3 vector)
{
    t_vector3   result;

    result[X] =
        + matrix[X][X] * vector[X]
        + matrix[X][Y] * vector[Y]
        + matrix[X][Z] * vector[Z];
    result[Y] =
        + matrix[Y][X] * vector[X]
        + matrix[Y][Y] * vector[Y]
        + matrix[Y][Z] * vector[Z];
    result[Z] =
        + matrix[Z][X] * vector[X]
        + matrix[Z][Y] * vector[Y]
        + matrix[Z][Z] * vector[Z];
	vector[X] = result[X];
	vector[Y] = result[Y];
	vector[Z] = result[Z];
}

int	main()
{
	t_vector3	orientation = {1, 1, 1};
	t_matrix3	basis;
	t_vector3	point;

	vector3_set(point, 0, 0, -1);
	matrix3_basis_vector(orientation, basis);
	matrix3_multiply_vector3(basis, point);
	printf("(%f, %f, %f) \n(%f, %f, %f) \n(%f, %f, %f) \n", basis[X][X], basis[X][Y], basis[X][Z], basis[Y][X], basis[Y][Y], basis[Y][Z], basis[Z][X], basis[Z][Y], basis[Z][Z]);
	printf("point: (%f, %f, %f) \n", point[X], point[Y], point[Z]);
	return (0);
}
