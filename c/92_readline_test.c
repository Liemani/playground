#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int	main()
{
	char	*line;

	line = readline("prompt test");
	printf("%s", line);
	free(line);
	return (0);
}
