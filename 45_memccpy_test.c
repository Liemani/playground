#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define SIZE 10
#ifndef C
# define C 40
#endif
#define N 0

int main(void)
{
	unsigned char	*dst;
	unsigned char	*src;
	int				c;
	size_t			n;

	unsigned char	*ptr;
	void			*result;

	dst = malloc(SIZE);
	src = malloc(SIZE);
	c = C;
	n = N;

	ptr = dst;
	for (int i = 0; i < SIZE; ++i)
		*ptr++ = (unsigned char) i + 1;
	ptr = src;
	for (int i = 0; i < SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 21;

	result = memccpy(dst, src, c, n);

	PRINT(dst, p);
	PRINT(src, p);
	PRINT(result, p);
	if (result)
		PRINT(*(unsigned char *) result, 2d);

	for (int i = 0; i < SIZE; ++i)
	{
		PRINT(i, 2d);
		if (dst)
			PRINT(*(unsigned char *) dst++, 2d);
		if (src)
			PRINT(*(unsigned char *) src++, 2d);
	}

	return (0);
}
