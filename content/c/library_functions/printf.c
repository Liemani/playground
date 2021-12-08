#include <stdio.h>

#define FIRST_WIDTH		10
#define SECOND_WIDTH	3
#define THIRD_WIDTH		10
#define FOURTH_WIDTH	10

int	main(void)
{
	int		sec = 10;
	int		usec = 321;
	int		numb = 1234;
	char	*message = "abcdefghi";

	printf("%*d%*d %*d %*s\n",
			FIRST_WIDTH, sec,
			SECOND_WIDTH, usec,
			THIRD_WIDTH, numb,
			FOURTH_WIDTH - 1, message);
	return (0);
}
