#include <stdlib.h> // NULL, malloc
#include <string.h>
#include "lmt.h"

#define SIZE_S 20

int main(void)
{
	unsigned char	*s;
	unsigned char	*p_s;
	void	*result;

	s = malloc(sizeof(*s) * SIZE_S);
	p_s = s;
	for (int i = 0; i < SIZE_S; ++i)
		*p_s++ = (unsigned char) i + 48;

	result = memchr(s, 305, SIZE_S);

	PRINT(s, p);
	PRINT(result, p);
	if (result)
		PRINT(*(unsigned char *) result, d);
	return (0);
}
