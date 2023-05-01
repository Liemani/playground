#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	pid_t	partner_pid;

	if (argc != 2)
		return (1);
	partner_pid = atoi(argv[1]);
	while (1)
	{
		printf("Send a signal and sleep for 3 sec, SIGUSR1 \n");
		kill(partner_pid, SIGUSR1);
		sleep(3);
		printf("Send a signal and sleep for 3 sec, SIGUSR2 \n");
		kill(partner_pid, SIGUSR2);
		sleep(3);
	}
	return (0);
}
