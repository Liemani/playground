#include <stdlib.h>
#include <errno.h>
#include "lmt.h"

#define MAIN_EXPRESSION a006();

size_t	a007(void)
{
	return (5);
}

void	a006(void)
{
	int i = 2;
	int j = 3;
	int k[i + j];
	int l = 4;
	int m[a007()];

	PRINT(&i, p);
	PRINT(&j, p);
	PRINT(k, p);
	PRINT(&l, p);
	PRINT(m, p);
	PRINT(sizeof(k), lu);
	PRINT(sizeof(m), lu);
}

void	a005(void)
{
	char	string[10];

	PRINT(string, p);
	PRINT(1 + string, p);
}

void	a004(void)
{
	int	test;

	test = -15 % 10;
	PRINT(test, d);
}

void	a003(void)
{
	char	*p_c;

	p_c = malloc(4000000000000000000);
	PRINT(p_c, p);
	PRINT(errno, d);
}

void	a002(void)
{
	char	*p_c;

	p_c = calloc(2, 1);
	free(p_c);
	free(p_c + 1);
}

void	a001(void)
{
	char	c0;
	char	array[1];
	char	c1;

	PRINT(&c0, p);
	PRINT(array, p);
	PRINT(&c1, p);
	PRINT(c0, d);
	PRINT(*array, d);
	PRINT(c1, d);
}

void	a000(void)
{
	if (1) // (1, 0)
		PRINT(1, d);
	else
		PRINT(0, d);
}

int main(void)
{
	MAIN_EXPRESSION

	return (0);
}
