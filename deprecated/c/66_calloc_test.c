#include <stdlib.h>
#include <errno.h>
#include "lmt.h"

int main(void)
{
	int	*i;

	PRINT(errno, d);
	PRINT(i, p);
	i = calloc(0, 10);
	PRINT(errno, d);
	PRINT(i, p);
	i = malloc(0);
	PRINT(errno, d);
	PRINT(i, p);
	return (0);
}
