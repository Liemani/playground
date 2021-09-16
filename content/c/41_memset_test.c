#include <string.h>
#include <stdlib.h>
#include "lmt.h"

#define SIZE_B 10

int main(void)
{
	unsigned char	*b;
	unsigned char	*ptr;
	int				c;
	size_t			len;
	void			*result;

	b = malloc(SIZE_B);
	c = 50;
	len = SIZE_B;
	ptr = b;
	for (int i = 0; i < SIZE_B; ++i)
		*ptr++ = i + 1;

	result = memset(b, c, 0);

	PRINT(b, p);
	PRINT(result, p);

	for (int i = 0; i < SIZE_B; ++i)
	{
		PRINT(i, 2d);
		PRINT(*b++, 3d);
	}

	return (0);
}
