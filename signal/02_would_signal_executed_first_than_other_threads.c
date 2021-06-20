#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	signal_handler_usr1(int signal)
{
	(void)signal;
	printf("Sleep for 7 sec, %d \n", signal);
	sleep(7);
	printf("Awaked \n");
}

void	signal_handler_usr2(int signal)
{
	(void)signal;
	printf("Sleep for 5 sec, %d \n", signal);
	sleep(5);
	printf("Awaked \n");
}

int		main(void)
{
	struct sigaction	sa;

	printf("%d \n", getpid());
	sa.sa_handler = signal_handler_usr1;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);

	sa.sa_handler = signal_handler_usr2;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
	{
		printf("I'm in the while loop! \n");
		pause();
	}
	return (0);
}
