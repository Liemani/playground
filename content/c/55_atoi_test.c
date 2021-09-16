#include <stdlib.h> // NULL
#include <string.h>
#include "lmt.h"

int main(int argc, char **argv)
{
	int				result;

	if (argc != 2)
	{
		printf("argc is not 2 \n");
		return (0);
	}

	result = atoi((const char *) argv[1]);

	PRINT(result, d);
	return (0);
}
