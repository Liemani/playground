#include <stdio.h>

int main()
{
	void *ptr;
	int *ptr_i = NULL;
	char *ptr_c;

	ptr = ptr_i;
	ptr_c = ptr;

	return 0;
}
