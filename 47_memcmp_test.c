#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define SIZE 10
#ifndef C
# define C 40
#endif
#ifndef N
# define N 0
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
	ptr = s2;
	for (int i = 0; i < SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 1;

	result = memcmp(s1, s2, n);

	putchar('\n');

	PRINT(result, d);

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
