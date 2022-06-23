#include <unistd.h>
#include <termios.h>
#include "../../c/lmt.h"

void	print_ttyname(void)
{
	char	*name;

	name = ttyname(0);
	PRINT(name, s);
	name = ttyname(1);
	PRINT(name, s);
	name = ttyname(2);
	PRINT(name, s);
}

int	main(void)
{
	struct termios	terminal_state;
	int	index;

	tcgetattr(0, &terminal_state);
	print_ttyname();
	PRINT(terminal_state.c_iflag, lu);
	PRINT(terminal_state.c_oflag, lu);
	PRINT(terminal_state.c_cflag, lu);
	PRINT(terminal_state.c_lflag, lu);
	index = 0;
	while (index < NCCS)
	{
		PRINT(terminal_state.c_cc[index], d);
		++index;
	}
	PRINT(terminal_state.c_ispeed, lu);
	PRINT(terminal_state.c_ospeed, lu);
}
