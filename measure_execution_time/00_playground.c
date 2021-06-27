#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#define SEC_LEN		19
#define USEC_LEN	6

#define EXECUTE	a004

void	*b000(void *nothing)
{
	int	another_nothing = 0;

	(void)nothing;
	while (true)
	{
		++another_nothing;
	}
}

#ifndef THREAD_COUNT
# define THREAD_COUNT	20
#endif

void	a004()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	result;
	pthread_t		threads[THREAD_COUNT];
	int				index;

	gettimeofday(&time_prev, NULL);
	index = 0;
	while (index < THREAD_COUNT)
	{
		if (pthread_create(&threads[index], NULL, b000, NULL) != 0)
			return ;
		++index;
	}
	index = 0;
	while (index < 100)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &result);
		time_prev = time_curr;
		printf("%19ld %06d \n", result.tv_sec, result.tv_usec);
		usleep(1);
		++index;
	}
}

void	a003()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	result;
	pthread_t		threads[THREAD_COUNT];
	int				index;
	struct timespec	time;

	gettimeofday(&time_prev, NULL);
	index = 0;
	while (index < THREAD_COUNT)
	{
		if (pthread_create(&threads[index], NULL, b000, NULL) != 0)
			return ;
		++index;
	}
	index = 0;
	time.tv_sec = 0;
	time.tv_nsec = 100000000;
	while (index < 100)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &result);
		time_prev = time_curr;
		printf("%19ld %06d \n", result.tv_sec, result.tv_usec);
		nanosleep(&time, NULL);
		++index;
	}
}

void	a002()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	result;

	gettimeofday(&time_prev, NULL);
	while (true)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &result);
		time_prev = time_curr;
		printf("%19ld %06d \n", result.tv_sec, result.tv_usec);
		usleep(1000);
	}
}

void	a001()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	result;
	pthread_mutex_t	mutex;

	gettimeofday(&time_prev, NULL);
	pthread_mutex_init(&mutex, NULL);
	while (true)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &result);
		time_prev = time_curr;
		printf("%19ld %06d \n", result.tv_sec, result.tv_usec);
		pthread_mutex_lock(&mutex);
		pthread_mutex_unlock(&mutex);
	}
}

void	a000()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	result;
	pthread_mutex_t	mutex;

	gettimeofday(&time_prev, NULL);
	pthread_mutex_init(&mutex, NULL);
	while (true)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &result);
		time_prev = time_curr;
		printf("%19ld %06d \n", result.tv_sec, result.tv_usec);
	}
}

int	main()
{
	EXECUTE();
	return (0);
}
