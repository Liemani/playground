#include <stdio.h>

int main()
{
	int array[4];

	printf("array        : %p \n", array);
	printf("&array       : %p \n", &array);

	int array2[4][4];

	array2[0][0] = 42;

	printf("array2       : %p \n", array2);
	printf("&array2      : %p \n", &array2);
	printf("*array2      : %p \n", *array2);
	printf("*(array2 + 1): %p \n", *(array2 + 1));
	printf("**array2     : %d \n", **array2);

	return 0;
}
