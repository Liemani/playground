#include <stdlib.h> // atoi()
#include <ctype.h> // isalpha()
#include "lmt.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		printf("argc != 2 \n");

	const int input = atoi(argv[1]);
	int	result;

	result = tolower(input);

	PRINT(input, 3d);
	PRINT(input, c);
	PRINT(result, d);
	PRINT(result, c);

	return (0);
}
