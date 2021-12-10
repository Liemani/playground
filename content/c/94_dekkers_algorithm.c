// link -> https://en.wikipedia.org/wiki/Dekker%27s_algorithm#/media/File:Dekker's_Algorithm.svg
// I saw this algorithm.
// They said this algorithm is the first known correct solution to the mutual exclusion problem.
// What about implement this algorithm myself in c?
// First, I made a program causing race condition intentionally
#include <pthread.h>	// phtread_
#include <stddef.h>	// NULL
#include <stdio.h>	// printf()
#include <unistd.h>	// usleep()

#define LOOP_COUNT	5

static void	*thread_run(void *arg);
static int	plus_one(int number);
static void	do_other_job(void);

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	int			shared_resource;

	shared_resource = 0;
	pthread_create(&tid1, NULL, thread_run, &shared_resource);
	pthread_create(&tid2, NULL, thread_run, &shared_resource);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return (0);
}

static void	*thread_run(void *arg)
{
	int	*shared_data;
	int	before_shared_data;
	int	computed_data;
	int	index;

	shared_data = (int *)arg;
	for (index = 0; index < LOOP_COUNT; ++index)
	{
		before_shared_data = *shared_data;
		computed_data = plus_one(before_shared_data);
		printf("shared_data: before[%3d], computed[%3d], after[%3d] \n",
				before_shared_data, computed_data, *shared_data);
		*shared_data = computed_data;
		do_other_job();
	}
	return (NULL);
}

static int	plus_one(int number)
{
	usleep(1);
	return (number + 1);
}

static void	do_other_job(void)
{
	usleep(1);
}
