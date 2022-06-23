#include <stddef.h>

#define STRING	"hello, world"

size_t	lmt_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index++] != '\0')
		;
	return (index);
}

int	main(void)
{
	lmt_strlen(STRING);
	return (0);
}
