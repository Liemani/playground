#include <stdlib.h>	// atoi(), NULL
#include <stdio.h>	// printf()
#include <unistd.h>	// sleep()
#include <pthread.h>	// pthread_craete()

#define EXECUTE	a004



//	Copy paste this function template
//	int	a000(int argc, char **argv)
//	{
//		if (argc != 2)
//		{
//			printf("usage: %s <thing> \n", argv[0]);
//			return (0);
//		}
//		return (0);
//	}


// Let's try double destroy mutex
int	a004(int argc, char **argv)
{
	pthread_mutex_t	mutex;
	int				return_value;

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	return_value = pthread_mutex_destroy(&mutex);
	printf("return_value -> [%d] \n", return_value);
	return_value = pthread_mutex_destroy(&mutex);
	printf("return_value -> [%d] \n", return_value);
	return (0);
}

int	a003(int argc, char **argv)
{
	pthread_mutex_t	mutex;

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	printf("After mutex lock \n");
	pthread_mutex_lock(&mutex);
	printf("After mutex lock again \n");
	return (0);
}



void	cleanup_routine(void *arg)
{
	(void)arg;
	printf("In the cleanup_routine \n");
}

void	*start_routine(void *arg)
{
	(void)arg;
	pthread_cleanup_push(cleanup_routine, NULL);
	printf("Starting start_routine \n");
//		pthread_exit((void *)0);
	while (1)
		sleep(1);
	pthread_cleanup_pop(1);
	return ((void *)0);
}

void	*observer_routine(void *arg)
{
	pthread_t	thread;

	(void)arg;
	printf("In observer thread \n");
	pthread_create(&thread, NULL, start_routine, NULL);
//		pthread_join(thread, NULL);
	printf("Terminating observer thread \n");
	return ((void *)0);
}

int	a002(int argc, char **argv)
{
	pthread_t	thread;

	(void)argc;
	(void)argv;
	pthread_create(&thread, NULL, observer_routine, NULL);
	pthread_join(thread, NULL);
//		sleep(1);
	printf("Terminating process \n");
	return (0);
}



int	a001(int argc, char **argv)
{
	int	return_value;
	if (argc != 2)
	{
		printf("usage: %s <exit_code> \n", argv[0]);
		return (0);
	}
	return_value = atoi(argv[1]);
	printf("before ptherad_exit \n");
	pthread_exit((void *)2);
	printf("after ptherad_exit \n");
	return (0);
}



void	*thread_routine(void *arg)
{
	(void)arg;
	printf("In ther thread_routine \n");
	pthread_exit((void *)1);
	return ((void *)0);
}

int	a000(int argc, char **argv)
{
	pthread_t	pthread;
	int			exit_status;

	(void)argc;
	(void)argv;
	printf("Start \n");
	pthread_create(&pthread, NULL, thread_routine, NULL);
	pthread_join(pthread, (void **)&exit_status);
	printf("exit_status: %d \n", exit_status);
	return (0);
}



int	main(int argc, char **argv)
{
	return (EXECUTE(argc, argv));
}
