#include <stdio.h>

#define PRINT_ADDRESS(x) printf(#x": %p \n", x)

int main(void)
{
	int	a;

	PRINT_ADDRESS(&a);

	return (0);
}
