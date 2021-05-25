#include "t_queue.h"

void	init_queue(t_queue *p_queue, int *p_array, int front_index, int rear_index)
{
	p_queue->p_array = p_array;
	p_queue->front_index = front_index;
	p_queue->rear_index = rear_index;
}
