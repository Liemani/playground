#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include "lmt.h"

#define FUNCTION a004

void	a004()
{
	printf("%ld \n", __STDC_VERSION__);
}

void	a003()
{
	wchar_t	*ls;
	char	*s;
	char	*ptr;
	int		return_value;
	
	setlocale(LC_ALL, "");
	ls = L"ㄱㄴㄷㄹ";
	return_value = printf("ls [as %%5ls] -> [%5ls] \n", ls);
	return_value = printf("ls [as %%5.3ls] -> [%5.3ls] \n", ls);
	return_value = printf("ls [as %%3.5ls] -> [%3.5ls] \n", ls);
	ptr = (char *)ls;
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	ls = L"abcd";
	return_value = printf("ls [as %%5ls] -> [%5ls] \n", ls);
	return_value = printf("ls [as %%5.3ls] -> [%5.3ls] \n", ls);
	return_value = printf("ls [as %%3.5ls] -> [%3.5ls] \n", ls);
	ptr = (char *)ls;
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	PRINT(*ptr++, 2x);
	s = "ㄱㄴㄷㄹ";
	return_value = printf("ls [as %%5s] -> [%5s] \n", s);
	return_value = printf("ls [as %%5.3s] -> [%5.3s] \n", s);
	return_value = printf("ls [as %%3.5s] -> [%3.5s] \n", s);
	s = "abcd";
	return_value = printf("ls [as %%5s] -> [%5s] \n", s);
	return_value = printf("ls [as %%5.3s] -> [%5.3s] \n", s);
	return_value = printf("ls [as %%3.5s] -> [%3.5s] \n", s);
}

void	a002()
{
	wchar_t	lc;
	wchar_t	*ls;
	char	*ptr;

	lc = L'ㅇ';
	ptr = (char *)&lc;
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	lc = L'ㄴ';
	ptr = (char *)&lc;
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	ls = L"ㅇ아안ㄴ녀녕";
	ptr = (char *)ls;
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
	PRINT(*ptr++, d);
}

void	a001()
{
	printf("sizeof(wint_t) [as %%ld] -> [%ld] \n", sizeof(wint_t));
	printf("sizeof(wchar_t) [as %%ld] -> [%ld] \n", sizeof(wchar_t));
	PRINT(WEOF, d);
	PRINT(EOF, d);
}

int		main(void)
{
	FUNCTION();
	return (0);
}
