#include <stdio.h>

int main()
{
#if 42 > 40
	printf("42 is greater than 40 \n");
#endif
#if 42 < 40
	printf("42 is less than 40 \n");
#endif
	return (0);
}
