#include <stdio.h>

#define MESSAGE_FIRST	"This is first message"
#define MESSAGE_SECOND	"This is second message"
#define MESSAGE_THIRD	"This is third message"
#define MESSAGE_COUNT	3

int	main(void)
{
	const char			*messages[MESSAGE_COUNT] = {MESSAGE_FIRST,
		MESSAGE_SECOND, MESSAGE_THIRD};
	const char *const	str1 = "Hello, world";
	char *const			str2 = "Hello, world2";
	int					index;

	index = 0;
	while (index < MESSAGE_COUNT)
	{
		printf("message [%d]: %s \n", index, messages[index]);
		++index;
	}
	return (0);
}
