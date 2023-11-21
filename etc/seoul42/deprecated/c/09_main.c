#include <stdio.h>

void my_function();
void print_my_function();

int main()
{
	my_function();
	print_my_function();
	return (0);
}

void my_function()
{
	printf("Hello, world! \n");
}
