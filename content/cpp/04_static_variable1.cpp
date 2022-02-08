#include <iostream>

int	global_int;
static int	static_int;

void	print_static_int(void);

int	main(void) {
	using std::cout;
	using std::endl;

	static_int = 42;
	print_static_int();
	cout << static_int << endl;
	cout << global_int << endl;
	cout << &static_int << endl;

	return 0;
}
