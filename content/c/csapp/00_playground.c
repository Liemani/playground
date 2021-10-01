#include <stdio.h>

#define EXECUTE	a000

void	a000()
{
	int	c;

	while ((c = getchar()) != EOF)
		putchar(c);
}

int	main()
{
	EXECUTE();
	return (0);
}
