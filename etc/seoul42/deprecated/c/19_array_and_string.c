#include <stdio.h>

int main(int argc, char **argv)
{
	(void) argv;

	char *string = "Hello, world!";
	char *string2 = "Hello, world!";
	char array[] = "Hello, world!";
	char array2[1];

	printf("string  : %p \n", string);
	printf("string2 : %p \n", string2);
	printf("array   : %p \n", array);

	printf("&array  : %p \n", &array);
	printf("&argc   : %p \n", &argc);
	printf("&string : %p \n", &string);
	printf("&string2: %p \n", &string2);
	printf("array2  : %p \n", array2);

	return 0;
}
