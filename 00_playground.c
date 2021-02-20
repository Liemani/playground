#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/types.h>
#include "libft.h"
#include "lmt.h"

#define MAIN_EXPRESSION a024();

#ifndef STRING
#define STRING "\a \n"
#endif

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
	printf("(unsigned int) &i1 [as %%#x] -> [%#x] \n", (unsigned int) &i1);
	printf("(unsigned int) &i1 [as %%x] -> [%x] \n", (unsigned int) &i1);
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
	MAIN_EXPRESSION

	return (0);
}
