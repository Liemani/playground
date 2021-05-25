#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# define INSTRUCTION_COUNT	11

int	pa(t_search_list *p_child, t_search_list *p_parent);
int	pb(t_search_list *p_child, t_search_list *p_parent);
int	sa(t_search_list *p_child, t_search_list *p_parent);
int	sb(t_search_list *p_child, t_search_list *p_parent);
int	ss(t_search_list *p_child, t_search_list *p_parent);
int	ra(t_search_list *p_child, t_search_list *p_parent);
int	rb(t_search_list *p_child, t_search_list *p_parent);
int	rr(t_search_list *p_child, t_search_list *p_parent);
int	rra(t_search_list *p_child, t_search_list *p_parent);
int	rrb(t_search_list *p_child, t_search_list *p_parent);
int	rrr(t_search_list *p_child, t_search_list *p_parent);

#endif
