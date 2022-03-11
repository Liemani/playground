#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p_null = NULL;
	char *str1 = malloc(50);
	char *str2 = malloc(50);
	char *result;

	result = memccpy(str1, "Hello, world!", 14);

	printf("str1: %s \n", str1);
	printf("str1: %p \n", str1);
	printf("result: %p \n", result);

	result = memccpy(str1, p_null, 0);

	printf("str1: %s \n", str1);
	printf("str1: %p \n", str1);
	printf("result: %p \n", result);

	return (0);
}
