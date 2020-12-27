#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define SIZE 20
#define N 10

int main(void)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			n;

	unsigned char	*ptr;
	void			*result;

	dst = malloc(SIZE);
	src = malloc(SIZE);
	n = N;

	ptr = dst;
	for (int i = 0; i < SIZE; ++i)
		*ptr++ = (unsigned char) i + 1;
	ptr = src;
	for (int i = 0; i < SIZE; ++i)
		*ptr++ = (unsigned char) i + 21;

	result = memcpy(dst, src, n);

	PRINT(dst, p);
	PRINT(src, p);
	PRINT(result, p);
	PRINT(*(unsigned char *) result, 2d);

	for (int i = 0; i < SIZE; ++i)
	{
		PRINT(i, 2d);
		PRINT(*(unsigned char *) dst++, 2d);
		PRINT(*(unsigned char *) src++, 2d);
	}

	return (0);
}
