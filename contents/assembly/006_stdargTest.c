#include <stdarg.h>

void	stdargTest(const char* str, ...) {
	va_list	ap;

	va_start(ap, str);
	va_arg(ap, int);
	va_arg(ap, int);
	va_arg(ap, double);
	va_end(ap);
}

int	main(void) {
	stdargTest("abc", 2147483648, 10, 1.1);
	return 0;
}
