#include <stdio.h>

int main(void)
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p_int = NULL;
	int **dptr = &array;

	printf("&array: %p \n", &array);
	printf("dptr  : %p \n", dptr);

	printf("array : %p \n", array);
	printf("*dptr : %p \n", *dptr);

	*dptr = p_int;

	printf("dptr  : %p \n", dptr);

	printf("*dptr : %p \n", *dptr);

	printf("*array: %d \n", *array);

	return (0);
}
