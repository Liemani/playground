#include <stdio.h>
#include <stdlib.h>
#include "t_application.h"

int	main(int argc, char **argv)
{
	t_application	application;

	init_application(&application, argc, argv);
	application_run(&application);
	return (0);
}
