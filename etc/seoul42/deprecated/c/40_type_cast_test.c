#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *p_void = NULL;
	unsigned char *p_c = NULL;
	char c;

	p_void = &c;
	p_c = p_void;
	c = 'A';

	printf("p_void    : %p \n", p_void);
	printf("p_void + 1: %p \n", p_void + 1);

	*(char *) p_void = 'z';

	printf("*(char *) p_void: %c \n", *(char *) p_void);

	return (0);
}
