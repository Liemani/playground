#include <stdio.h>

int main(void)
{
	char	c = -128;
	int		i = -2100000000;

	printf("(unsigned char)c: %d \n", (unsigned char) c);
	printf("(unsigned char)i: %d \n", (unsigned char) i);

	return (0);
}
