#include "t_search_list.h"
#include "util.h"

t_search_list	*new_root_list(int *p_array_a, int count)
{
	t_search_list *const	p_list = lmt_alloc(sizeof(t_search_list));

	p_list->p_array_a = p_array_a;
	p_list->p_array_b = lmt_alloc(count + 1);
	p_list->front_index_a = 0;
	p_list->rear_index_a = count;
	p_list->front_index_b = 0;
	p_list->rear_index_b = 0;
	p_list->p_instruction = NULL;
	p_list->p_next = NULL;
	return (p_list);
}

