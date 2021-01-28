#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include "libft.h"
#include "lmt.h"

#define MAIN_EXPRESSION a014();

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
