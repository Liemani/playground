#ifndef T_BRANCH_H
# define T_BRANCH_H

# include "t_queue.h"
# include "t_instruction.h"

typedef	struct				s_branch
{
	t_queue					*p_queue_a;
	t_queue					*p_queue_b;
	t_instruction_function	p_instruction;
	struct s_branch			*p_next;
}							t_branch;

void						init_root_list(t_branch *p_list, int *p_array_a, int count);

#endif
