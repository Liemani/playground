#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define SIZE 10
#ifndef C
# define C 40
#endif
#ifndef N
# define N 1
#endif

int main(void)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				c;
	size_t			n;

	unsigned char	*ptr;
	int				result;

	s1 = malloc(SIZE);
	s2 = malloc(SIZE);
	c = C;
	n = N;

	ptr = s1;
	for (int i = 0; i < SIZE; ++i)
		*ptr++ = (unsigned char) i + 1;
	*s1 = 110;
	ptr = s2;
	for (int i = 0; i < SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 1;
	*s2 = 100;

	result = memcmp("a", "c", n);

	PRINT(result, d);
	putchar('\n');
	for (int i = 0; i < SIZE; ++i)
	{
		PRINT(i, 2d);
		if (s1)
			PRINT(*(unsigned char *) s1++, 2d);
		if (s2)
			PRINT(*(unsigned char *) s2++, 2d);
	}

	return (0);
}
