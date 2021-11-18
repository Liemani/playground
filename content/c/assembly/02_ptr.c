#include <stddef.h>

#define STRING	"hello, world"

size_t	lmt_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr++ != '\0')
		;
	return (ptr - str);
}

int	main(void)
{
	lmt_strlen(STRING);
	return (0);
}
