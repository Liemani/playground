#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double	t_vector3[3];
typedef double	t_matrix3[3][3];

t_matrix3   *matrix3_unit_vector(t_vector3 *p_camera_direction)
{
    const double magnitude_of_camera_direction_vector_projected_onto_xz_plane =
        sqrt(
            pow((*p_camera_direction)[0], 2.0) +
            pow((*p_camera_direction)[2], 2.0));
    const double magnitude_of_camera_direction_vector =
        sqrt(
            pow((*p_camera_direction)[0], 2.0) +
            pow((*p_camera_direction)[1], 2.0) +
            pow((*p_camera_direction)[2], 2.0));
    t_matrix3   *p_matrix;

    p_matrix = malloc(sizeof(*p_matrix));

    (*p_matrix)[0][0] = - ((*p_camera_direction)[2]) / magnitude_of_camera_direction_vector_projected_onto_xz_plane;
    (*p_matrix)[0][1] = 0;
    (*p_matrix)[0][2] = - ((*p_camera_direction)[0]) / magnitude_of_camera_direction_vector_projected_onto_xz_plane;

    (*p_matrix)[1][0] = - ((*p_camera_direction)[0] * (*p_camera_direction)[1]) / (magnitude_of_camera_direction_vector * magnitude_of_camera_direction_vector_projected_onto_xz_plane);
    (*p_matrix)[1][1] = magnitude_of_camera_direction_vector_projected_onto_xz_plane / magnitude_of_camera_direction_vector;
    (*p_matrix)[1][2] = ((*p_camera_direction)[1] * (*p_camera_direction)[2]) / (magnitude_of_camera_direction_vector * magnitude_of_camera_direction_vector_projected_onto_xz_plane);

    (*p_matrix)[2][0] = 0;
    (*p_matrix)[2][1] = 0;
    (*p_matrix)[2][2] = 1;

    return (p_matrix);
}

int	main(void)
{
	t_vector3	vector = {1.0, 0.0, 0.0};
	t_matrix3	*p_matrix = matrix3_unit_vector(&vector);
	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 3)
		{
			printf("%f, ", (*p_matrix)[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	return (0);
}
