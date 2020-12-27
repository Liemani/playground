#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define SIZE_S 20

int main(void)
{
	unsigned char	*s;
	unsigned char	*ptr;
	void	*result;

	s = malloc(SIZE_S);
	ptr = s;
	for (int i = 0; i < SIZE_S; ++i)
		*ptr++ = (unsigned char) i + 1;
	result = memchr(s, 10, SIZE_S);
	PRINT(s, p);
	PRINT(result, p);
	PRINT(*(unsigned char *) result, d);
	return (0);
}
