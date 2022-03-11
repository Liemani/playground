#include <stdio.h>

int a = 0;

int main()
{
	printf("a: %d \n", a);

	int a = 10;
	printf("a: %d \n", a);

	if (1)
	{
		int a = 20;
		printf("a: %d \n", a);
	}

	printf("a: %d \n", a);
}
