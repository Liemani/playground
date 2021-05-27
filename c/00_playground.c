#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/types.h>
#include <string.h>

#include "libft.h"
// #include "ft_printf.h"
#include "lmt.h"

#define MAIN_EXPRESSION a048

#ifndef STRING
#define STRING "\a \n"
#endif

void	a048()
{
	int a = 12 % 11;
	int b = -1 % 11;
	int c = -12 % 11;

	PRINT(a, d);
	PRINT(b, d);
	PRINT(c, d);
}

void	a047()
{
	int i = INT_MAX;
	int j = INT_MAX;
	long l;

	PRINT(i * 10 > j, d);
	l = i * 10;
	PRINT(l > j, d);
	l = (long)i * 10;
	PRINT(l > j, d);
}

void	a046()
{
	PRINT(sizeof(void *), lu);
}

void	a045()
{
	float	f = 123456.78;
	PRINT(f, f);
	float	f2 = 123.45678;
	PRINT(f2, .10f);
}

void	a044()
{
	printf("[%x] \n", 0);
	printf("[%.x] \n", 0);
}

void	a043()
{
	printf("%-12345678901234567890d \n", 0);
	printf("%12345678901234567890d \n", 0);
	printf("%-1234567890123456789d \n", 0);
	printf("%1234567890123456789d \n", 0);
	printf("%d \n", 0);
	printf("%0d \n", 0);
	printf("%-1d \n", 0);
	printf("\n");

	printf("[%-12345678901234567890.d] \n", 0);
	printf("[%12345678901234567890.d] \n", 0);
	printf("[%-1234567890123456789.d] \n", 0);
	printf("[%1234567890123456789.d] \n", 0);
	printf("[%.d] \n", 0);
	printf("[%0.d] \n", 0);
	printf("[%-1.d] \n", 0);
}

void	a042()
{
	int		d = 12;
	char	*s = "hi";

	PRINT(d, 5.3d);
	PRINT(s, 5.3s);
	PRINT(d, 5.8d);
	PRINT(s, 5.8s);
}

void	a041()
{
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
	PRINT(sizeof(long long), lu);
	PRINT(sizeof(void *), lu);
}

void	a040()
{
	int		result;

	result = strcmp(NULL, "hi");    // segmentation fault
	printf("result: %d \n", result);
}

void	a039()
{
	char	*string;

	string = strdup(NULL);    // segmentation fault
	printf("string: %p \n", string);
}

void	a038()
{
	if ('\0' == '\x0')
		printf("'\\0' is equal to '\\x' \n");
}

// void	a037()
// {
// 	int	i;
// 	int	*n;
// 
// 	n = &i;
// 	printf("n [as %%n] -> [as %n] \n", n);
// 	printf("n [as %%n] -> [as %5n] \n", n);
// 	printf("n [as %%n] -> [as %.n] \n", n);
// 	printf("n [as %%n] -> [as %05n] \n", n);
// 	printf("n [as %%n] -> [as %-05n] \n", n);
// 	printf("n [as %%n] -> [as %-5n] \n", n);
// 	printf("n [as %%n] -> [as %.5n] \n", n);
// }

void	a036()
{
	int	i;
	int	*n;
	int	return_value;

	n = &i;
	return_value = printf("n [as %%n] -> [as %n] \n", n);
	printf("*n [as %%d] -> [%d] \n", *n);
	printf("return_value [as %%d] -> [%d] \n", return_value);
}

void	a035()
{
	int				i;
	unsigned int	u;

	i = -1;
	u = 1;
	printf("i as [%%o] -> [%o] \n", i);
	printf("u as [%%o] -> [%o] \n", u);
}

void	a034()
{
	int	i;
	int	return_value;

	i = 0;
	return_value = printf("%*i", INT_MAX -1, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
	return_value = printf("%*i", INT_MAX, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
	return_value = printf("%*i \n", INT_MAX -1, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
	return_value = printf("%*i \n", INT_MAX, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
}

// void	a033()
// {
// 	char	c;
// 	int		a;
// 	int		i;
// 
// 	c = 10;
// 	printf("c as [%%-00-i] -> [%-00-i]", c);
// 	a = 12;
// 	i = 18;
// 	MPRIN("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i);
// }

void	a032()
{
	char	c;

	c = 0;
	while (c < 127)
	{
		printf("c as [%%d] -> [%d] \n", c);
		printf("c as [%%c] -> [%c] \n", c);
		printf("c as [%%.c] -> [%.c] \n", c);
		++c;
	}
}

void	a031()
{
	int	i;
	int	j;
	int k;

	printf("\ntest start \n");
	i = -1;
	while (i < 2)
	{
		printf("i: [%d] \n", i);
		printf("i [as %%d] -> [%d] \n", i);
		printf("i [as %%.d] -> [%.d] \n", i);
		printf("i [as %%.0d] -> [%.0d] \n", i);
		printf("i [as %%u] -> [%u] \n", i);
		printf("i [as %%.u] -> [%.u] \n", i);
		printf("i [as %%.0u] -> [%.0u] \n", i);
		printf("i [as %%x] -> [%x] \n", i);
		printf("i [as %%.x] -> [%.x] \n", i);
		printf("i [as %%.0x] -> [%.0x] \n", i);
		++i;
	}

	printf("\ntest  start \n");
	i = -1;
	while (i < 2)
	{
		j = -1;
		printf("i: [%d] \n", i);
		while (j < 2)
		{
			printf("j: [%d] \n", j);
			printf("j, i [as %%.*d] -> [%.*d] \n",j , i);
			printf("j, i [as %%.*u] -> [%.*u] \n",j , i);
			printf("j, i [as %%.*x] -> [%.*x] \n",j , i);
			++j;
		}
		++i;
	}

	printf("\ntest  start \n");
	k = -1;
	while (k < 2)
	{
		i = -1;
		while (i < 2)
		{
			j = -1;
			while (j < 2)
			{
				printf("k: [%d] \n", k);
				printf("i: [%d] \n", i);
				printf("j: [%d] \n", j);
				printf("k, j, i [as %%*.*d] -> [%*.*d] \n", k, j, i);
				printf("k, j, i [as %%*.*u] -> [%*.*u] \n", k, j, i);
				printf("k, j, i [as %%*.*x] -> [%*.*x] \n", k, j, i);
				++j;
			}
			++i;
		}
		++k;
	}
}

void	a030()
{
	printf("'a' [as %%.c] -> [%.c] \n", 'a');
	printf("\"a\" [as %%.s] -> [%.s] \n", "a");
	printf("(void *)1 [as %%.p] -> [%.p] \n", (void *)1);
	printf("[as %%.%%] -> [%.%] \n");
	printf("'a' [as %%.c] -> [%.c] \n", 'a');
	printf("\"a\" [as %%.0s] -> [%.0s] \n", "a");
	printf("(void *)1 [as %%.p] -> [%.p] \n", (void *)1);
	printf("[as %%.0%%] -> [%.0%] \n");
}

void	a029()
{
	printf("%d", -0);
}

void	a028()
{
	printf("[%-7.*s$] \n", -3, "yolo");
	printf("[%*.*s$] \n",-7,-3, "yolo");
}

// void	a027()
// {
// 	ft_printf("(void *)0 [as %%.p] -> [%.p] \n", (void *)0);
// 	ft_printf("(void *)0 [as %%5p] -> [%5p] \n", (void *)0);
// 	ft_printf("(void *)0 [as %%5.p] -> [%5.p] \n", (void *)0);
// 	printf("(void *)0 [as %%.p] -> [%.p] \n", (void *)0);
// 	printf("(void *)0 [as %%5p] -> [%5p] \n", (void *)0);
// 	printf("(void *)0 [as %%5.p] -> [%5.p] \n", (void *)0);
// }

// void	a026()
// {
// 	int i;
// 
// 	i = -1;
// 	ft_printf("i [as %%i] -> [%i] \n", i);
// 	ft_printf("i [as %%5i] -> [%5i] \n", i);
// 	ft_printf("i [as %%-5i] -> [%-5i] \n", i);
// 	ft_printf("i [as %%05i] -> [%05i] \n", i);
// 	ft_printf("i [as %%.5i] -> [%.5i] \n", i);
// 	ft_printf("i [as %%3.5i] -> [%3.5i] \n", i);
// 	ft_printf("i [as %%-3.5i] -> [%-3.5i] \n", i);
// 	ft_printf("i [as %%5.3i] -> [%5.3i] \n", i);
// 	ft_printf("i [as %%-5.3i] -> [%-5.3i] \n", i);
// 	ft_printf("i [as %%0.5i] -> [%0.5i] \n", i);
// 	ft_printf("i [as %%03.5i] -> [%03.5i] \n", i);
// 	ft_printf("i [as %%05.3i] -> [%05.3i] \n", i);
// 	ft_printf("i [as %%05.2i] -> [%05.2i] \n", i);
// 	ft_printf("i [as %%05.1i] -> [%05.1i] \n", i);
// 	ft_printf("i [as %%05.0i] -> [%05.0i] \n", i);
// 	ft_printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
// 	ft_printf("i [as %%05.i] -> [%05.i] \n", i);
// }

void	a025()
{
	int i;

	printf("ft_printf: \n");
// 	a026();
	putchar('\n');
	printf("printf: \n");
	i = -1;
	printf("i [as %%i] -> [%i] \n", i);
	printf("i [as %%5i] -> [%5i] \n", i);
	printf("i [as %%-5i] -> [%-5i] \n", i);
	printf("i [as %%05i] -> [%05i] \n", i);
	printf("i [as %%.5i] -> [%.5i] \n", i);
	printf("i [as %%3.5i] -> [%3.5i] \n", i);
	printf("i [as %%-3.5i] -> [%-3.5i] \n", i);
	printf("i [as %%5.3i] -> [%5.3i] \n", i);
	printf("i [as %%-5.3i] -> [%-5.3i] \n", i);
	printf("i [as %%0.5i] -> [%0.5i] \n", i);
	printf("i [as %%03.5i] -> [%03.5i] \n", i);
	printf("i [as %%05.3i] -> [%05.3i] \n", i);
	printf("i [as %%05.2i] -> [%05.2i] \n", i);
	printf("i [as %%05.1i] -> [%05.1i] \n", i);
	printf("i [as %%05.0i] -> [%05.0i] \n", i);
	printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
	printf("i [as %%05.i] -> [%05.i] \n", i);
}

void	a024()
{
	printf("[as %%%%] -> [%%] \n");
	printf("[as %%5%%] -> [%5%] \n");
	printf("[as %%-5%%] -> [%-5%] \n");
	printf("[as %%05%%] -> [%05%] \n");
	printf("[as %%.5%%] -> [%.5%] \n");
	printf("[as %%3.5%%] -> [%3.5%] \n");
	printf("[as %%-3.5%%] -> [%-3.5%] \n");
	printf("[as %%5.3%%] -> [%5.3%] \n");
	printf("[as %%-5.3%%] -> [%-5.3%] \n");
}

void	a023()
{
	PRINT(sizeof(ssize_t), lu);
	PRINT(sizeof(size_t), lu);
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
}

void	a022()
{
	unsigned int x;

	x = 0x1;
	printf("x [as %%x] -> [%x] \n", x);
	printf("x [as %%5x] -> [%5x] \n", x);
	printf("x [as %%-5x] -> [%-5x] \n", x);
	printf("x [as %%05x] -> [%05x] \n", x);
	printf("x [as %%.5x] -> [%.5x] \n", x);
	printf("x [as %%3.5x] -> [%3.5x] \n", x);
	printf("x [as %%-3.5x] -> [%-3.5x] \n", x);
	printf("x [as %%5.3x] -> [%5.3x] \n", x);
	printf("x [as %%-5.3x] -> [%-5.3x] \n", x);
}

void	a021()
{
	unsigned int u;

	u = 1;
	printf("u [as %%u] -> [%u] \n", u);
	printf("u [as %%5u] -> [%5u] \n", u);
	printf("u [as %%-5u] -> [%-5u] \n", u);
	printf("u [as %%05u] -> [%05u] \n", u);
	printf("u [as %%.5u] -> [%.5u] \n", u);
	printf("u [as %%3.5u] -> [%3.5u] \n", u);
	printf("u [as %%-3.5u] -> [%-3.5u] \n", u);
	printf("u [as %%5.3u] -> [%5.3u] \n", u);
	printf("u [as %%-5.3u] -> [%-5.3u] \n", u);
	printf("u [as %%0.5u] -> [%0.5u] \n", u);
	printf("u [as %%03.5u] -> [%03.5u] \n", u);
	printf("u [as %%05.3u] -> [%05.3u] \n", u);
}

void	a020()
{
	int	i;
	int	*p;

	p = &i;
	printf("p [as %%p] -> [%p] \n", p);
	printf("p [as %%15p] -> [%15p] \n", p);
	printf("p [as %%-15p] -> [%-15p] \n", p);
//	printf("p [as %%015p] -> [%015p] \n", p);
//	printf("p [as %%.15p] -> [%.15p] \n", p);
//	printf("p [as %%15.20p] -> [%15.20p] \n", p);
//	printf("p [as %%-15.20p] -> [%-15.20p] \n", p);
//	printf("p [as %%20.15p] -> [%20.15p] \n", p);
//	printf("p [as %%-20.15p] -> [%-20.15p] \n", p);
}

void	a019()
{
	char	*s1;

	s1 = "s";
	printf("s1 [as %%s] -> [%s] \n", s1);
	printf("s1 [as %%5s] -> [%5s] \n", s1);
	printf("s1 [as %%-5s] -> [%-5s] \n", s1);
//	printf("s1 [as %%05s] -> [%05s] \n", s1);
	printf("s1 [as %%.5s] -> [%.5s] \n", s1);
	printf("s1 [as %%3.5s] -> [%3.5s] \n", s1);
	printf("s1 [as %%-3.5s] -> [%-3.5s] \n", s1);
	printf("s1 [as %%5.3s] -> [%5.3s] \n", s1);
	printf("s1 [as %%-5.3s] -> [%-5.3s] \n", s1);
}

void	a018()
{
	char c1;

	c1 = 'c';
	printf("c1 [as %%c] -> [%c] \n", c1);
	printf("c1 [as %%5c] -> [%5c] \n", c1);
//	printf("c1 [as %%05c] -> %05c \n", c1);
//	printf("c1 [as %%.5c] -> %.5c \n", c1);
//	printf("c1 [as %%3.5c] -> %3.5c \n", c1);
//	printf("c1 [as %%5.3c] -> %5.3c \n", c1);
	printf("c1 [as %%-5c] -> [%-5c] \n", c1);
//	printf("c1 [as %%-5.3c] -> %-5.3c \n", c1);
//	printf("c1 [as %%-3.5c] -> %-3.5c \n", c1);
}

void	a017()
{
	int		i1;
	int		i2;
	int		x3;
	int 	i4;
	double	d5;
	int		i6;

	i1 = 20;
	i2 = 30;
	x3 = 0x10;
	i4 = 2;
	d5 = 12.34567;
	i6 = -x3;
	PRINT(i1, d);
	PRINT(i2, d);
	PRINT(x3, i);
	PRINT(i4, d);
	PRINT(d5, f);
	PRINT(i6, d);
	printf("start: [%d, %d, %n] \n", i1, i2, &x3);
	printf("second: [%1$d, %2$d, %3$d, %3$d, %2$d, %1$d] \n", i1, i2, x3);
//	printf("(unsigned int) &i1 [as %%#x] -> [%#x] \n", (unsigned int) &i1);
//	printf("(unsigned int) &i1 [as %%x] -> [%x] \n", (unsigned int) &i1);
	printf("i1, &i2 [as %%*p] -> [%*p] \n", i1, &i2);
	printf("i1, &i2 [as %%2$*1$p] -> [%2$*1$p] \n", i1, &i2);
	printf("&i2, i1 [as %%1$*2$p] -> [%1$*2$p] \n", &i2, i1);
	printf("x3, i4, d5 [as %%3$*1$.*2$f] -> [%3$*1$.*2$f] \n", x3, i4, d5);
	printf("x3, i4, d5 [as %%*.*f] -> [%*.*f] \n", x3, i4, d5);
	printf("x3, i4, d5 [as %%-*.*f] -> [%-*.*f] \n", x3, i4, d5);
	printf("i6, i4, d5 [as %%*.*f] -> [%*.*f] \n", i6, i4, d5);
	printf("i6, i4, d5 [as %%-*.*f] -> [%-*.*f] \n", i6, i4, d5);
	printf("i6, i4, d5 [as %%--*.*f] -> [%--*.*f] \n", i6, i4, d5);
	printf("i6, i4, d5 [as %%0000*.*f] -> [%0000*.*f] \n", i6, i4, d5);
	printf("i4, d5 [as %%*f] -> [%*f] \n", i4, d5);
	printf("i4, d5 [as %%*.f] -> [%*.f] \n", i4, d5);
	printf("i4, i6, d5 [as %%*.*f] -> [%*.*f] \n", i4, i6, d5);
	printf("i1 [as %%.3d] -> [%.3d] \n", i1);
	printf("d5 [as %%a] -> [%a] \n", d5);
	printf("d5 [as %%A] -> [%A] \n", d5);
	PRINT(i1, 4d);
	PRINT(i1, -4d);
	PRINT(i1, 04d);
	PRINT(i1, 3.4d);
	PRINT(i1, .4d);
	PRINT(i1, 03.4d);
	PRINT(i1, 0.4d);
//	printf("100, i1 [as %%0*d] -> [%0*d] \n", 100, i1);
	printf("\"\" [as %%-*s] -> [%-*s] \n", 0, "");
	printf("-5, i4 [as %%.*d] -> [%.*d] \n", -5, i4);
	printf("5, i4 [as %%.*d] -> [%.*d] \n", 5, i4);
	printf("i4 [as %%.5d] -> [%.5d] \n", i4);
	printf("i4 [as %%10.5d] -> [%10.5d] \n", i4);
	printf("i4 [as %%010.5d] -> [%010.5d] \n", i4);
	printf("i4 [as %%010d] -> [%010d] \n", i4);
	printf("i4 [as %%5.10d] -> [%5.10d] \n", i4);
	printf("i4 [as %%-10.5d] -> [%-10.5d] \n", i4);
	printf("\"a\" [as %%10.5s] -> [%10.5s] \n", "a");
//	printf("\"a\" [as %%#10.5s] -> [%#10.5s] \n", "a");
}

void	a016()
{
	const char	*str = STRING;
	
	printf(STRING);
	PRINT(*str, x);
	PRINT(*(str + 1), x);
}

void	a015()
{
	int				d;
	unsigned char	*c;

	d = 0x12345678;
	c = (unsigned char *)&d;
	for (int i = 0; i < 4; ++i)
	{
		PRINT(*c, x);
		++c;
	}
}

void	a014()
{
	PRINT(sizeof(size_t), lu);
	PRINT(sizeof(ssize_t), lu);
}

int		ft_wordcount(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c || i == 0) && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

void	a013()
{
	int count = ft_wordcount("a", 'c');

	PRINT(count, d);
}

/*
static int  word_count(char const *str, char c)
{
    int count;

    if (!str)
        return (0);
    if (!c)
        return (*str ? 1 : 0); 
    count = (*str == c ? -1 : 0); 
    while (*str)
    {   
        ++count;
        while (*str != c)
            ++str;
        while (*str == c)
            ++str;
    }   
    return (count);
}

void	a012()
{
	char	**result;
	int		count = word_count("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');

	PRINT(count, d);
	putchar('\n');

	result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	PRINT(result, p);
	if (result)
	{
		while (*result)
		{
			PRINT(*result, p);
			PRINT(*result++, s);
		}
		PRINT(*result, p);
	}
}

void	a011()
{
	char	s[1] = {0};
	char	**result = ft_split(s, 65);
	if (result)
	{
		PRINT(result, p);
		PRINT(*result, p);
	}
	else
		printf("result is empty \n");
}
*/

void	a010()
{
	PRINT('\t', d);
	PRINT('\n', d);
	PRINT('\v', d);
	PRINT('\f', d);
	PRINT('\r', d);
	printf("\' \': %d \n", ' ');
}

void	a009(void (*f)(void))
{
	if (f)
		printf("f is not NULL \n");
	else
		printf("f is NULL \n");
	f();
}

void	a008(void)
{
	a009(NULL);
}

size_t	a007(void)
{
	return (5);
}

void	a006(void)
{
	int i = 2;
	int j = 3;
	int k[i + j];
	int l = 4;
	int m[a007()];

	PRINT(&i, p);
	PRINT(&j, p);
	PRINT(k, p);
	PRINT(&l, p);
	PRINT(m, p);
	PRINT(sizeof(k), lu);
	PRINT(sizeof(m), lu);
}

void	a005(void)
{
	char	string[10];

	PRINT(string, p);
	PRINT(1 + string, p);
}

void	a004(void)
{
	int	test;

	test = -15 % 10;
	PRINT(test, d);
}

void	a003(void)
{
	char	*p_c;

	p_c = malloc(4000000000000000000);
	PRINT(p_c, p);
	PRINT(errno, d);
}

void	a002(void)
{
	char	*p_c;

	p_c = calloc(2, 1);
	free(p_c);
	free(p_c + 1);
}

void	a001(void)
{
	char	c0;
	char	array[1];
	char	c1;

	PRINT(&c0, p);
	PRINT(array, p);
	PRINT(&c1, p);
	PRINT(c0, d);
	PRINT(*array, d);
	PRINT(c1, d);
}

void	a000(void)
{
	if (1) // (1, 0)
		PRINT(1, d);
	else
		PRINT(0, d);
}

int main(void)
{
	MAIN_EXPRESSION();

	return (0);
}
