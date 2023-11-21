#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "libft.h"
#include "lmt.h"

#define HAYSTACK_SIZE 5
#define NEEDLE_SIZE 5
#define HAYSTACKSIZE 5
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
	char			*result;

	haystack = malloc(HAYSTACK_SIZE);
	ptr = haystack;
	for (int i = 0; i < HAYSTACK_SIZE; ++i)
		*ptr++ = (unsigned char)0;
	*(haystack + (size_t) HAYSTACK_SIZE - 1) = 0;

	needle = malloc(NEEDLE_SIZE);
	ptr = needle;
	for (int i = 0; i < NEEDLE_SIZE + 1; ++i)
		*ptr++ = (unsigned char) i + 1;
	*(needle + 3) = 0;

	haystacksize = HAYSTACKSIZE;
	c = C;
	len = LEN;

	result = ft_strtrim((char const *)haystack, (char const *)needle);

	PRINT(haystack, p);
	PRINT(needle, p);
	PRINT(result, p);
	len = strlen(result) + 1;

	for (size_t i = 0; i < len; ++i)
		if (result)
			PRINT(*(unsigned char *) result++, 3d);
	putchar('\n');

	for (size_t i = 0; i < HAYSTACK_SIZE; ++i)
		if (haystack)
			PRINT(*(unsigned char *) haystack++, 3d);
	putchar('\n');

	for (size_t i = 0; i < NEEDLE_SIZE; ++i)
		if (needle)
			PRINT(*(unsigned char *) needle++, 3d);

	return (0);
}
