#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define DST_SIZE 0
#define SRC_SIZE 10
#ifndef C
# define C 40
#endif
#ifndef N
# define N 0
#endif

int main(void)
{
	unsigned char	*dst;
	unsigned char	*src;

	size_t			dstsize;
	int				c;
	size_t			n;

	unsigned char	*ptr;
	size_t			result;

	dst = malloc(DST_SIZE);
	ptr = dst;
	for (int i = 0; i < DST_SIZE; ++i)
		*ptr++ = (unsigned char) 1;
	*(dst + (size_t) DST_SIZE / 2) = 0;

	src = malloc(SRC_SIZE);
	ptr = src;
	for (int i = 0; i < SRC_SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 1;
	*(src + ((size_t) DST_SIZE + (size_t) SRC_SIZE) / 2) = 0;

	dstsize = DST_SIZE;
	c = C;
	n = N;

	result = strlcpy((char *) dst, (char *) src, dstsize);

	PRINT(result, lu);
	putchar('\n');
	for (size_t i = 0; i < DST_SIZE; ++i)
		if (dst)
		{
			PRINT(i, 2lu);
			PRINT(*(unsigned char *) dst++, 3d);
		}
	putchar('\n');
	for (size_t i = 0; i < SRC_SIZE; ++i)
		if (src)
		{
			PRINT(i, 2lu);
			PRINT(*(unsigned char *) src++, 3d);
		}

	return (0);
}
