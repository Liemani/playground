#include <stdio.h>

int	main()
{
	double d = 3.0;

	printf("%d \n", d);
	printf("%d \n", d);
	printf("%#.16x \n", d);
	printf("%#.16x \n", d);
	printf("%d \n", 3 * d);
	printf("%d \n", 3 * d);
	printf("%#.16x \n", 3 * d);
	printf("%#.16x \n", 3 * d);
	printf("\n");
	unsigned char *p_d = &d;
	for (int i = 0; i < 8; ++i)
	{
		printf("%d \n", p_d[i]);
	}
	return (0);
}
