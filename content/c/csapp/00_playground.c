#include <stdio.h>

#define EXECUTE	a001



// 38p
int	a001(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("hello, world\n");
	return (0);
}


int	a000(int argc, char **argv)
{
	int	c;

	(void)argc;
	(void)argv;
	while ((c = getchar()) != EOF)
		putchar(c);
	return (0);
}



int	main(int argc, char **argv)
{
	return (EXECUTE(argc, argv));
}
