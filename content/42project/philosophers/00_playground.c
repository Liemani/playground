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
# define THREAD_COUNT	200
#endif
#ifndef SLEEP_MICRO
# define SLEEP_MICRO	1
#endif
#ifndef LOOP_COUNT
# define LOOP_COUNT		10
#endif



void	*a0030(void *arg);

void	a004(void)
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



#define STATUS_READY	0
#define STATUS_GO		1

int	a003_create_threads(pthread_t *array, int *arg)
{
	int	index;

	for (index = 0; index < THREAD_COUNT; ++index)
		if (pthread_create(array + index, NULL, a0030, arg) != 0)
			return (1);
	return (0);
}

void	a003_join_threads(pthread_t *array)
{
	int	index;

	for (index = 0; index < THREAD_COUNT; ++index)
		pthread_join(array[index], NULL);
}

void	*a0030(void *status)
{
	int	count;

	count = 0;
	while (*(int *)status == STATUS_READY)
		usleep(100);
	while (*(int *)status == STATUS_GO)
		++count;
	return (NULL);
}

//	If thread 20,
//	If nanosleep(     1000),       3 <= time_diff.tv_usec <=       5
//	If nanosleep(    10000),      17 <= time_diff.tv_usec <=      18
//	If nanosleep(   100000),     130 <= time_diff.tv_usec <=     135
void	a003(void)
{
	pthread_t		threads[THREAD_COUNT];
	struct timeval	time_diff[LOOP_COUNT];
	struct timeval	time_prev;
	struct timeval	time_curr;
	size_t			index;
	int				status;

	status = STATUS_READY;
	gettimeofday(&time_prev, NULL);
	if (a003_create_threads(threads, &status) != 0)
		return ;
	status = STATUS_GO;
//		usleep(SLEEP_MICRO);
//		usleep(SLEEP_MICRO);
//		usleep(SLEEP_MICRO);
//		usleep(SLEEP_MICRO);
	for (index = 0; index < LOOP_COUNT; ++index)
	{
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, time_diff + index);
		time_prev = time_curr;
		usleep(SLEEP_MICRO);
	}
	status = STATUS_READY;
	a003_join_threads(threads);
	for (index = 0; index < LOOP_COUNT; ++index)
		printf("%06d \n", time_diff[index].tv_usec);
}



//	If usleep(0_000_001), 000_003 <= time_diff.tv_usec <= ~ 000_005
//	If usleep(0_000_010),      14 <= time_diff.tv_usec <= ~      19
//	If usleep(0_000_100),     127 <= time_diff.tv_usec <= ~     134
//	If usleep(0_001_000),    13time_diff.tv_usec <= ~     1361
//	If usleep(0_010_000), time_diff.tv_usec <= ~ 012_647
//	If usleep(0_100_000), time_diff.tv_usec <= ~ 105_143
//	If usleep(1_000_000), time_diff.tv_usec <= ~ 005_139
void	a002(void)
{
	int				index;
	struct timeval	time_prev;
	struct timeval	time_curr;
	struct timeval	time_diff[LOOP_COUNT];

	index = 0;
	gettimeofday(&time_prev, NULL);
	while (index < LOOP_COUNT)
	{
		usleep(SLEEP_MICRO);
		gettimeofday(&time_curr, NULL);
		timersub(&time_curr, &time_prev, &time_diff[index]);
		time_prev = time_curr;
		++index;
	}
	index = 0;
	while (index < LOOP_COUNT)
	{
		printf("%06d \n", time_diff[index].tv_usec);
		++index;
	}
}



void	a001(void)
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



void	a000(void)
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



int	main(void)
{
	EXECUTE();
	return (0);
}
