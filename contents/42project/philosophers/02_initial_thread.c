#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*sleep_for(void *seconds)
{
	write(1, "Start sleep \n", 13);
	sleep((int)seconds);
	write(1, "End sleep \n", 11);
	return (NULL);
}

int	main(void)
{
	pthread_t	first_thread;
	pthread_t	second_thread;

	pthread_create(&first_thread, NULL, sleep_for, (void *)5);
	pthread_create(&second_thread, NULL, sleep_for, (void *)1);
	pthread_join(first_thread, NULL);
	printf("First thread returned \n");
	pthread_join(second_thread, NULL);
	printf("Second thread returned \n");
	return (0);
}
