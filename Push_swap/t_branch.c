#include "t_branch.h"
#include "t_queue.h"
#include "util.h"

void	init_branch(t_branch *p_list)
{
	p_list->p_next = NULL;
}

void	init_search_element(t_branch *p_list, t_queue *p_queue_a, t_queue *p_queue_b, t_instruction_function p_instruction)
{
	p_list->p_queue_a = p_queue_a;
	p_list->p_queue_b = p_queue_b;
	p_list->p_instruction = p_instruction;
	p_list->p_next = NULL;
}
