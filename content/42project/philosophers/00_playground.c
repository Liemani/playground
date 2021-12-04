#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#ifndef	EXECUTE
# define EXECUTE	a003
#endif

#define USEC_IN_NSEC	1000
#define SEC_LEN			19
#define USEC_LEN		6
#ifndef THREAD_COUNT
# define THREAD_COUNT	20
#endif
#ifndef SLEEP_NANO
# define SLEEP_NANO		100000
#endif
#define LOOP_TIME		1000



void	*a0030(void *arg);

void	a004()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	time_diff;
	pthread_t		threads[THREAD_COUNT];
	int				index;

	gettimeofday(&time_prev, NULL);
	index = 0;
	while (index < THREAD_COUNT)
	{
		if (pthread_create(&threads[index], NULL, a0030, NULL) != 0)
			return ;
		++index;
	}
	index = 0;
	while (index < 100)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &time_diff);
		time_prev = time_curr;
		printf("%19ld %06d \n", time_diff.tv_sec, time_diff.tv_usec);
		usleep(1);
		++index;
	}
}



void	*a0030(void *arg)
{
	int	count;

	(void)arg;
	count = 0;
	while (true)
	{
		++*(unsigned int *)arg;
//			++*(int *)arg;
//			printf("In the thread %d \n", *(int *)arg);
//			sleep(1);
	}
	return (NULL);
}

//	If thread 20,
//	If nanosleep(     1000),       3 <= time_diff.tv_usec <=       5
//	If nanosleep(    10000),      17 <= time_diff.tv_usec <=      18
//	If nanosleep(   100000),     130 <= time_diff.tv_usec <=     135
void	a003()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	pthread_t		threads[THREAD_COUNT];
	unsigned int	thread_args[THREAD_COUNT];
	struct timeval	time_diff[LOOP_TIME];
	int				index;
	struct timespec	time;

	gettimeofday(&time_prev, NULL);
	for (index = 0; index < THREAD_COUNT; ++index)
	{
		thread_args[index] = index;
		if (pthread_create(&threads[index], NULL, a0030, thread_args + index) != 0)
			return ;
	}
	time.tv_sec = 0;
	time.tv_nsec = SLEEP_NANO;
	sleep(1);
	for (index = 0; index < LOOP_TIME; ++index)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, time_diff + index);
		time_prev = time_curr;
		nanosleep(&time, NULL);
	}
	for (index = 0; index < LOOP_TIME; ++index)
		printf("%06d \n", time_diff[index].tv_usec);
}



//	If usleep(0_000_001), 000_003 <= time_diff.tv_usec <= ~ 000_005
//	If usleep(0_000_010),      14 <= time_diff.tv_usec <= ~      19
//	If usleep(0_000_100),     127 <= time_diff.tv_usec <= ~     134
//	If usleep(0_001_000),    13time_diff.tv_usec <= ~     1361
//	If usleep(0_010_000), time_diff.tv_usec <= ~ 012_647
//	If usleep(0_100_000), time_diff.tv_usec <= ~ 105_143
//	If usleep(1_000_000), time_diff.tv_usec <= ~ 005_139
void	a002()
{
	int				index;
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	time_diff[LOOP_TIME];

	index = 0;
	gettimeofday(&time_prev, NULL);
	while (index < LOOP_TIME)
	{
		usleep(SLEEP_NANO / USEC_IN_NSEC);
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &time_diff[index]);
		time_prev = time_curr;
		++index;
	}
	index = 0;
	while (index < LOOP_TIME)
	{
		printf("%06d \n", time_diff[index].tv_usec);
		++index;
	}
}



void	a001()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	time_diff;
	pthread_mutex_t	mutex;

	gettimeofday(&time_prev, NULL);
	pthread_mutex_init(&mutex, NULL);
	while (true)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &time_diff);
		time_prev = time_curr;
		printf("%19ld %06d \n", time_diff.tv_sec, time_diff.tv_usec);
		pthread_mutex_lock(&mutex);
		pthread_mutex_unlock(&mutex);
	}
}



void	a000()
{
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	time_diff;
	pthread_mutex_t	mutex;

	gettimeofday(&time_prev, NULL);
	pthread_mutex_init(&mutex, NULL);
	while (true)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &time_diff);
		time_prev = time_curr;
		printf("%19ld %06d \n", time_diff.tv_sec, time_diff.tv_usec);
	}
}



int	main()
{
	EXECUTE();
	return (0);
}
