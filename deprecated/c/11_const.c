#include <stdio.h>

/*
void test_const_function(const int* pInt)
{
	printf("pInt: %p \n", pInt);
	int my_int;
	pInt = &my_int;
	printf("pInt: %p \n", pInt);
}
*/

/*
void test_const_function(const int* pInt)
{
	printf("*pInt: %d \n", *pInt);
	*pInt = 0;
	printf("*pInt: %d \n", *pInt);
}
*/

/*
void test_const_function(int const* pInt)
{
	printf("pInt: %p \n", pInt);
	int my_int;
	pInt = &my_int;
	printf("pInt: %p \n", pInt);
}
*/

void test_const_function(int const* pInt)
{
	printf("*pInt: %d \n", *pInt);
	*pInt = 0;
	printf("*pInt: %d \n", *pInt);
}

/*
void test_const_function(int* const pInt)
{
	printf("*pInt: %d \n", *pInt);
	*pInt = 0;
	printf("*pInt: %d \n", *pInt);
}
*/

int main()
{
	int my_int;

	my_int = 42;
	test_const_function(&my_int);
	
	return 0;
}
