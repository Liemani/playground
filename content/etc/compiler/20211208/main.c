#include <stdio.h>
#include "main.h"

void		first(void);
static void	second(void);
static void	second(void);

int	main(void)
{
	printf("In main \n");
	first();
	second();
	return (0);
}

void	first(void)
{
	printf("In first \n");
}

static void	second(void)
{
	printf("In second \n");
}
