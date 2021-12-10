// link -> https://en.wikipedia.org/wiki/Dekker%27s_algorithm#/media/File:Dekker's_Algorithm.svg
// Now refactoring code base psudo code on the link
// dekker algorithm work only for variable shared between exactly 2 thread
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
	int			tindex;
	int			*shared_data;
	int			*current_turn;
	int			*wants_to_enter;
}	t_thread_res;

static void	thread_res_init(t_thread_res *tres, int *shared_data,
		int *current_turn, int *wants_to_enter);
static void	*thread_run(void *arg);
static void	dekker_algorithm(t_thread_res *tres,
		int *shared_data,
		int *before_shared_data,
		int *computed_data);
static int	plus_one(int number);
static void	do_some_job(void);



int	main(void)
{
	int				shared_data;
	int				current_turn;
	int				wants_to_enter[2];
	t_thread_res	tres1;
	t_thread_res	tres2;

	shared_data = 0;
	current_turn = 0;
	wants_to_enter[0] = FALSE;
	wants_to_enter[0] = FALSE;

	tres1.tindex = 0;
	tres2.tindex = 1;
	thread_res_init(&tres1, &shared_data, &current_turn, wants_to_enter);
	thread_res_init(&tres2, &shared_data, &current_turn, wants_to_enter);

	pthread_create(&tres1.tid, NULL, thread_run, &tres1);
	pthread_create(&tres2.tid, NULL, thread_run, &tres2);

	pthread_join(tres1.tid, NULL);
	pthread_join(tres2.tid, NULL);

	return (0);
}

static void	thread_res_init(t_thread_res *tres, int *shared_data,
		int *current_turn, int *wants_to_enter)
{
	tres->shared_data = shared_data;
	tres->current_turn = current_turn;
	tres->wants_to_enter = wants_to_enter;
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
		dekker_algorithm(tres, shared_data, &before_shared_data, &computed_data);
		do_some_job();
	}
	return (NULL);
}

static void	dekker_algorithm(t_thread_res *tres,
		int *shared_data,
		int *before_shared_data,
		int *computed_data)
{
	const int	tindex = tres->tindex;
	int	*const	wants_to_enter = tres->wants_to_enter;
	int	*const	current_turn = tres->current_turn;

	wants_to_enter[tindex] = TRUE;
	while (wants_to_enter[!tindex])
	{
		if (*current_turn != tindex)
			wants_to_enter[tindex] = FALSE;
		while (*current_turn != tindex)
			;
		wants_to_enter[tindex] = TRUE;
	}

	*before_shared_data = *shared_data;
	*computed_data = plus_one(*before_shared_data);
	printf("tindex: %d, shared_data: before[%3d], computed[%3d], after[%3d] \n",
			tindex, *before_shared_data, *computed_data, *shared_data);
	*shared_data = *computed_data;

	*current_turn = !*current_turn;
	wants_to_enter[tindex] = FALSE;
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
