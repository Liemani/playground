#include <stdio.h>

int main()
{
	int array[4];
	int two_dimension_array[4][4];

	printf("sizeof(array): %lu \n", sizeof(array));
	printf("sizeof(two_dimension_array): %lu \n", sizeof(two_dimension_array));
	printf("sizeof(two_dimension_array[0]): %lu \n", sizeof(two_dimension_array[0]));

	return 0;
}
