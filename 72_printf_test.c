#include <stdio.h>
#include <wchar.h>
#include "lmt.h"

#define FUNCTION a002

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
