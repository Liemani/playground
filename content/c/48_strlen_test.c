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
	unsigned char	*s;
	unsigned char	*s2;
	int				c;
	size_t			n;

	unsigned char	*ptr;
	size_t			result;

	s = malloc(SIZE);
	s2 = malloc(SIZE);
	c = C;
	n = N;

	ptr = s;
	for (int i = 0; i < SIZE; ++i)
		*ptr++ = (unsigned char) i;
	ptr = s + 5;
	*ptr = '\0';
	ptr = s2;
	for (int i = 0; i < SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 1;

	result = strlen((const char *)s);
	PRINT(result, lu);
	putchar('\n');
	for (int i = 0; i < SIZE; ++i)
	{
		PRINT(i, 2d);
		if (s)
			PRINT(*(unsigned char *) s++, 2d);
		if (s2)
			PRINT(*(unsigned char *) s2++, 2d);
	}

	return (0);
}
