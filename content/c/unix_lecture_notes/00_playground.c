//	http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/?C=M;O=D

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
