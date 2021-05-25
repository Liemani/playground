#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# define INSTRUCTION_COUNT	11

typedef	struct s_branch	t_branch;

typedef void			(*t_instruction)(t_branch *p_parent, t_branch *p_child);

int						pa(t_branch *p_parent, t_branch *p_child);
int						pb(t_branch *p_parent, t_branch *p_child);
int						sa(t_branch *p_parent, t_branch *p_child);
int						sb(t_branch *p_parent, t_branch *p_child);
int						ss(t_branch *p_parent, t_branch *p_child);
int						ra(t_branch *p_parent, t_branch *p_child);
int						rb(t_branch *p_parent, t_branch *p_child);
int						rr(t_branch *p_parent, t_branch *p_child);
int						rra(t_branch *p_parent, t_branch *p_child);
int						rrb(t_branch *p_parent, t_branch *p_child);
int						rrr(t_branch *p_parent, t_branch *p_child);

#endif
