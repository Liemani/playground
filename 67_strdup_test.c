#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "lmt.h"

int main(void)
{
	char	*s1;
	char	*result;

	s1 = malloc(0);
	*s1 = '\0';
	PRINT(errno, d);
	PRINT(result, p);
	putchar('\n');
	result = strdup(s1);
	PRINT(errno, d);
	PRINT(result, p);
	if (result)
		PRINT(*result, d);
	return (0);
}
