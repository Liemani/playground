#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	unsigned char	*s;

	s = malloc(20);

	for (int i = 0; i < 20; ++i)
		*(s + i) = 19 - i;

	bzero(s, 0);

	for (int i = 0; i < 20; ++i)
		printf("%2d: %d \n", i, *(s + i));

	return (0);
}
