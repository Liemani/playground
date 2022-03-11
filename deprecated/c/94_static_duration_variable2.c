#include <stdio.h>

int	global_int;
int	static_int = 10;

void	print_static_int(void) {
	global_int = 42;
	printf("%d\n", static_int);
	printf("%p\n", &global_int);
	printf("%p\n", &static_int);
}
