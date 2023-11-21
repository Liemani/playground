#include <stdarg.h>
#include <errno.h>
#include "lmt.h"

#define RUN_FUNCTION test002()

void	read_value(va_list ap)
{
	PRINT(va_arg(ap, int), d);
}

void	test0020(char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	PRINT(va_arg(ap, int), d);
	read_value(ap);
	PRINT(va_arg(ap, int), d);
}

void	test002()
{
	int	d1;
	int	d2;
	int d3;

	d1 = 1;
	d2 = 2;
	d3 = 3;
	test0020("", d1, d2, d3);
}

void	test_int(va_list *ap)
{
	int	d;

	d = va_arg(*ap, int);
	PRINT(d, d);
}

void	test(const char *fmt, ...)
{
	va_list			ap;
	char			c;
	unsigned int	u;
	// int				d;
	long			ld;
	void			*whatever;

	va_start(ap, fmt);
	c = va_arg(ap, int);
	PRINT(c, c);
	test_int(&ap);
	ld = va_arg(ap, long);
	PRINT(ld, ld);
	whatever = &ld;
	PRINT(*(long *) whatever, lx);
	u = va_arg(ap, unsigned int);
	PRINT(u, u);
	u = va_arg(ap, unsigned int);
	PRINT(u, u);
	va_end(ap);
}

void	test001()
{
	char			c;
	int				d;
	unsigned int	u;
	long			ld;
	double			lf;

	c = 'a';
	d = -10;
	u = 20;
	ld = -1;
	lf = 11.111111;
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
	test("", c, d, lf, u);
}

int		main()
{
	RUN_FUNCTION;
	return (0);
}
