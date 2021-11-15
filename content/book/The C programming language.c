#include <stdio.h>

#define EXECUTE	a009



//	copy paste this function prototype
//	int	a000(int argc, char **argv)
//	{
//		(void)argc;
//		(void)argv;
//		return (0);
//	}



int	a009(int argc, char **argv)
{
	int	c;

	(void)argc;
	(void)argv;
	while ((c = getchar()) != EOF)
		putchar(c);
	printf("EOF: [%d]\n", c);
	return (0);
}



int	a008(int argc, char **argv)
{
	int	c;

	(void)argc;
	(void)argv;
	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}
	return (0);
}



#define LOWER	0
#define UPPER	300
#define STEP	20

int	a007(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;

	(void)argc;
	(void)argv;
	printf("fahrenheit celsius\n");
	fahrenheit = LOWER;
	while (fahrenheit <= UPPER)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += STEP;
	}
	return (0);
}



int	a006(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;
	int		lower;
	int		upper;
	int		step;

	(void)argc;
	(void)argv;
	lower = 300;
	upper = 0;
	step = -20;
	printf("fahrenheit celsius\n");
	fahrenheit = lower;
	while (fahrenheit >= upper)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a005(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;
	int		lower;
	int		upper;
	int		step;

	(void)argc;
	(void)argv;
	lower = 0;
	upper = 300;
	step = 20;
	printf("fahrenheit celsius\n");
	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a004(int argc, char **argv)
{
	float	fahrenheit;
	float	celsius;
	int		lower;
	int		upper;
	int		step;

	(void)argc;
	(void)argv;
	lower = 0;
	upper = 300;
	step = 20;
	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("%5.1f %8.1f\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a003(int argc, char **argv)
{
	int	fahrenheit;
	int	celsius;
	int	lower;
	int	upper;
	int	step;

	(void)argc;
	(void)argv;
	lower = 0;
	upper = 300;
	step = 20;
	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = (fahrenheit - 32) * (5.0 / 9.0);
		printf("%3d %6d\n", fahrenheit, celsius);
		fahrenheit += step;
	}
	return (0);
}



int	a002(int argc, char **argv)
{
	float	celsius;
	float	fahrenheit;

	(void)argc;
	(void)argv;
	celsius = 0;
	while (celsius <= 300)
	{
		fahrenheit = celsius * (9.0 / 5.0) + 32;
		printf("%.0f\t%.0f\n", celsius, fahrenheit);
		celsius += 20;
	}
	return (0);
}



int	a001(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("hello, ");
	printf("world");
	printf("\n");
//		printf("\c");
	return (0);
}



int	a000(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("hello, world\n");
	return (0);
}



int	main(int argc, char **argv)
{
	return (EXECUTE(argc, argv));
}
