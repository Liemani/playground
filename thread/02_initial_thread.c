#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*sleep_for(void *seconds)
{
	write(1, "?\n", 2);
	sleep((int)seconds);
	write(1, "?\n", 2);
	return (NULL);
}

int	main(void)
{
	pthread_t	first_thread;

	pthread_create(&first_thread, NULL, sleep_for, (void *)1);
	pthread_join(first_thread, NULL);
	printf("Exiting main function \n");
	return (0);
}
