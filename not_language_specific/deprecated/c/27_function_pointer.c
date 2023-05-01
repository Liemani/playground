#include <stdio.h>

int fct(char c)
{
	printf("%c \n", c);

	return (0);
}

int main(void)
{
	int (*my_fct)(char);
	my_fct = fct;
	my_fct('L');

	return (0);
}
