#include <iostream>

extern int	global_int;
int	static_int = 10;

void	print_static_int(void) {
	using std::cout;
	using std::endl;

	global_int = 42;
	cout << static_int << endl;
	cout << &static_int << endl;
}
