#include <stdio.h>

int main()
{
	int	array[2][3];

	printf("&array[0][0]: %p \n", &array[0][0]);
	printf("&array[0][1]: %p \n", &array[0][1]);
	printf("&array[0][2]: %p \n", &array[0][2]);
	printf("&array[1][0]: %p \n", &array[1][0]);
	printf("&array[1][1]: %p \n", &array[1][1]);
	printf("&array[1][2]: %p \n", &array[1][2]);

	return 0;
}
