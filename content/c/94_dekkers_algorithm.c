// link -> https://en.wikipedia.org/wiki/Dekker%27s_algorithm#/media/File:Dekker's_Algorithm.svg
// Now, let's apply dekker's algorithm
// This commit i analyze dekker's algorithm on my mind
// Initial turn order must defined
// And turn must be given sequentially
// I thought that if remove wants_to_enter[], it would be compacted
// But as a result, it is caused the possibility of deadlock and starvation
#include <pthread.h>	// phtread_
#include <stddef.h>	// NULL
#include <stdio.h>	// printf()
#include <unistd.h>	// usleep()

#define LOOP_COUNT	5

#define FALSE	0
#define TRUE	1



typedef struct s_thread_res
{
	pthread_t	tid;
	int			*shared_data;
	int			*current_turn;
	int			*last_turn;
	int			my_turn;
}	t_thread_res;

static void	thread_res_init(t_thread_res *tres, int *shared_data,
		int *current_turn, int *last_turn);
static void	*thread_run(void *arg);
static void	want_to_enter(t_thread_res *tres,
		int *shared_data,
		int *before_shared_data,
		int *computed_data);
static int	plus_one(int number);
static void	do_some_job(void);



int	main(void)
{
	int				shared_data;
	int				current_turn;
	int				last_turn;
	t_thread_res	tres1;
	t_thread_res	tres2;

	shared_data = 0;
	current_turn = 0;
	last_turn = 2;

	tres1.my_turn = 0;
	tres2.my_turn = 1;
	thread_res_init(&tres1, &shared_data, &current_turn, &last_turn);
	thread_res_init(&tres2, &shared_data, &current_turn, &last_turn);

	pthread_create(&tres1.tid, NULL, thread_run, &tres1);
	pthread_create(&tres2.tid, NULL, thread_run, &tres2);

	pthread_join(tres1.tid, NULL);
	pthread_join(tres2.tid, NULL);

	return (0);
}

static void	thread_res_init(t_thread_res *tres, int *shared_data,
		int *current_turn, int *last_turn)
{
	tres->shared_data = shared_data;
	tres->current_turn = current_turn;
	tres->last_turn = last_turn;
}

static void	*thread_run(void *arg)
{
	t_thread_res	*tres;
	int				*shared_data;
	int				before_shared_data;
	int				computed_data;
	int				index;

	tres = (t_thread_res *)arg;
	shared_data = tres->shared_data;
	for (index = 0; index < LOOP_COUNT; ++index)
	{
		want_to_enter(tres, shared_data, &before_shared_data, &computed_data);
		do_some_job();
	}
	return (NULL);
}

static void	want_to_enter(t_thread_res *tres,
		int *shared_data,
		int *before_shared_data,
		int *computed_data)
{
	while (tres->my_turn != *tres->current_turn)
		;

	*before_shared_data = *shared_data;
	*computed_data = plus_one(*before_shared_data);
	printf("shared_data: before[%3d], computed[%3d], after[%3d] \n",
			*before_shared_data, *computed_data, *shared_data);
	*shared_data = *computed_data;

	tres->my_turn = *tres->last_turn;
	++*tres->last_turn;
	++*tres->current_turn;
}

static int	plus_one(int number)
{
	usleep(1);
	return (number + 1);
}

static void	do_some_job(void)
{
	usleep(1);
}
