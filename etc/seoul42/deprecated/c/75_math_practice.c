#include <stdio.h>
#include <math.h>

int	main()
{
	double	cosTheta;
	double	rad;
	double	angle;

	const double a = sqrt(6.0) / 3;
	const double b = sqrt(3.0) / 3;
	const double c = 1;

	printf("sqrt(3.0) / 3 [as %%f] -> [%f] \n", sqrt(3.0) / 3);
	cosTheta = ( pow(b, 2.0) + pow(c, 2.0) - pow(a, 2.0)) / (2 * b * c);
	printf("cosTheta [as %%f] -> [%f] \n", cosTheta);
	rad = acos(cosTheta);
	printf("rad [as %%f] -> [%f] \n", rad);
	angle = rad * 180 / M_PI;
	printf("angle [as %%f] -> [%f] \n", angle);

	rad = acos(1 / sqrt(3.0));
	printf("rad [as %%f] -> [%f] \n", rad);
	angle = rad * 180 / M_PI;
	printf("angle [as %%f] -> [%f] \n", angle);

	return (0);
}
