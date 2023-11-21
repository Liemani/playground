#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

void	handle_return_value(int return_value)
{
	if (return_value == 1)
		printf("success [%d] \n", return_value);
	if (return_value == 0)
		printf("there is no such entry \n");
	if (return_value == -1)
		printf("the terminfo database could not be found \n");
}

void	tgetent_test(const char *name)	// entry name to load, check '/usr/share/terminfo'
{
	int			return_value;

	return_value = tgetent(NULL, name);
	handle_return_value(return_value);
}

int	main(int argc, char **argv)
{
	int		count;
	char	**name_array;

	if (argc == 1)
	{
		printf("You must input at least 1 argument \n");
		return (0);
	}

	count = argc;
	name_array = argv + 1;

	while (count > 1)
	{
		tgetent_test((const char *)*name_array);
		--count;
		++name_array;
	}

	return (0);
}
