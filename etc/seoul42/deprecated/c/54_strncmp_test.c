#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define HAYSTACK_SIZE 10
#define NEEDLE_SIZE 10
#define HAYSTACKSIZE 0
#ifndef C
# define C 40
#endif
#ifndef LEN
# define LEN 1
#endif

int main(void)
{
	unsigned char	*haystack;
	unsigned char	*needle;

	size_t			haystacksize;
	int				c;
	size_t			len;

	unsigned char	*ptr;
	int				result;

	haystack = malloc(HAYSTACK_SIZE);
	ptr = haystack;
	for (int i = 0; i < HAYSTACK_SIZE; ++i)
		*ptr++ = (unsigned char) i + 1;
	*haystack = 100;

	needle = malloc(NEEDLE_SIZE);
	ptr = needle;
	for (int i = 0; i < NEEDLE_SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 6;
	*needle = 110;

	haystacksize = HAYSTACKSIZE;
	c = C;
	len = LEN;

	result = strncmp("z", "ab", 1);

	PRINT(result, d);
	putchar('\n');
	for (size_t i = 0; i < HAYSTACK_SIZE; ++i)
		if (haystack)
		{
			PRINT(i, 2lu);
			PRINT(*(unsigned char *) haystack++, 3d);
		}
	putchar('\n');
	for (size_t i = 0; i < NEEDLE_SIZE; ++i)
		if (needle)
		{
			PRINT(i, 2lu);
			PRINT(*(unsigned char *) needle++, 3d);
		}

	return (0);
}
