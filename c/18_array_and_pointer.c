#include <stdio.h>

void my_function(int array[])
{
	printf("array        : %p \n", array);
	printf("&array       : %p \n", &array);
	printf("sizeof(array): %lu \n", sizeof(array));
	
	int another_array[4];
	array = another_array;
	printf("array        : %p \n", array);
}

int main()
{
	int array[4];

	printf("array        : %p \n", array);
	printf("&array       : %p \n", &array);

	my_function(array);

	return 0;
}
