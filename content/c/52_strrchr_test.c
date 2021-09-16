#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define DST_SIZE 10
#define SRC_SIZE 0
#define DSTSIZE 0
#ifndef C
# define C 5
#endif
#ifndef N
# define N 0
#endif

int main(void)
{
	unsigned char	*s;
	unsigned char	*src;

	size_t			ssize;
	int				c;
	size_t			n;

	unsigned char	*ptr;
	char			*result;

	s = malloc(DST_SIZE);
	ptr = s;
	for (int i = 0; i < DST_SIZE; ++i)
		*ptr++ = (unsigned char) i + 1;
	*(s + (size_t) DST_SIZE / 2) = 0;

	src = malloc(SRC_SIZE);
	ptr = src;
	for (int i = 0; i < SRC_SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 11;
	*(src + ((size_t) DST_SIZE + (size_t) SRC_SIZE) / 2) = 0;

	ssize = DSTSIZE;
	c = C;
	n = N;

	result = strrchr(NULL, 0);

	PRINT(result, p);
	if (result)
		PRINT(*result, d);
	putchar('\n');
	for (size_t i = 0; i < DST_SIZE; ++i)
		if (s)
		{
			PRINT(i, 2lu);
			PRINT(*(unsigned char *) s++, 3d);
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
