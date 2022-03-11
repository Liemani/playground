#include <stdio.h>

int	global_int;
static int	static_int;

void	print_static_int(void);

int	main(void) {
	static_int = 42;
	print_static_int();
	printf("%d\n", static_int);
	printf("%d\n", global_int);
	printf("%p\n", &global_int);
	printf("%p\n", &static_int);

	return 0;
}
