#include "instruction.h"

#define TRUE	1
#define FALSE	0

int	pa(t_branch *p_parent, t_branch *p_child)
{
	if (p_parent->p_instruction == pb)
		return (FALSE);
	if (p_parent->p_front_b == p_parent->p_rear_b)
		return (FALSE);
}

int	pb(t_branch *p_parent, t_branch *p_child)
{
}

int	sa(t_branch *p_parent, t_branch *p_child)
{
}

int	sb(t_branch *p_parent, t_branch *p_child)
{
}

int	ss(t_branch *p_parent, t_branch *p_child)
{
}

int	ra(t_branch *p_parent, t_branch *p_child)
{
}

int	rb(t_branch *p_parent, t_branch *p_child)
{
}

int	rr(t_branch *p_parent, t_branch *p_child)
{
}

int	rra(t_branch *p_parent, t_branch *p_child)
{
}

int	rrb(t_branch *p_parent, t_branch *p_child)
{
}

int	rrr(t_branch *p_parent, t_branch *p_child)
{
}
