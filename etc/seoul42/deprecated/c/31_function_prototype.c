#include <stdio.h>

void fct(void)
{
	printf("in fct \n");
}

int main(void)
{
	void (*p_fct)(void);

	p_fct = &fct;
	(*p_fct)();

	p_fct = fct;
	p_fct();

	printf("fct : %p \n", fct);
	printf("*fct: %p \n", *fct);
	printf("&fct: %p \n", &fct);

	return (0);
}
