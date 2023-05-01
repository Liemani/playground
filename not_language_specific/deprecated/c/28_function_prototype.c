#include <stdio.h>

typedef void (*fct_type)(void);

fct_type fct;
fct_type fct2;

int main(void)
{
	fct();
	fct = fct2;
	fct();

	return (0);
}

void fct(void)
{
	printf("fct \n");
}

void fct2(void)
{
	printf("fct2 \n");
}
