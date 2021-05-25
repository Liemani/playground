#ifndef T_QUEUE_H
# define T_QUEUE_H

typedef struct	s_queue
{
	int			*p_array;
	int			front_index;
	int			rear_index;
}				t_queue;

void			init_queue(t_queue *p_queue, int *p_array, int front_index, int rear_index);

#endif
