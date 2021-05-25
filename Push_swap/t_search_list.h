#ifndef T_SEARCH_LIST_H
# define T_SEARCH_LIST_H

# include "t_queue.h"

typedef struct s_search_list	t_search_list;
typedef void					(*t_instruction)(t_search_list *p_search_list);

typedef	struct					s_search_list
{
	t_queue						*p_queue_a;
	t_queue						*p_queue_b;
	t_instruction_function		p_instruction;
	struct s_search_list		*p_next;
}								t_search_list;

t_search_list					*new_root_list(int *p_array_a, int count);

#endif
