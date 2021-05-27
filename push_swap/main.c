#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define PA	0
#define PB	1
#define SA	2
#define SB	3
#define SS	4
#define RA	5
#define RB	6
#define RR	7
#define RRA	8
#define RRB	9
#define RRR	10

#define INSTRUCTION_COUNT	11

typedef struct			s_element
{
	struct s_element	*p_prev;
	int					i;
	struct s_element	*p_next;
}						t_element;

typedef struct			s_list
{
	t_element			*p_front;
	t_element			*p_rear;
	int					count;
}						t_list;

typedef struct			s_process
{
	t_list				*p_list_a;
	t_list				*p_list_b;
}						t_process;

t_element	*new_element(int i)
{
	t_element	*p_element;

	p_element = malloc(sizeof(t_element));
	p_element->i = i;
	return (p_element);
}

t_list	*new_list()
{
	t_list		*p_list;
	t_element	*p_front;
	t_element	*p_rear;

	p_list = malloc(sizeof(t_list));
	p_front = new_element(0);
	p_rear = new_element(0);
	p_front->p_prev = NULL;
	p_front->p_next = p_rear;
	p_rear->p_prev = p_front;
	p_rear->p_next = NULL;
	p_list->p_front = p_front;
	p_list->p_rear = p_rear;
	p_list->count = 0;
	return (p_list);
}

void	list_add_new_element_front(t_list *p_list, int i)
{
	t_element	*p_front;
	t_element	*p_next;
	t_element	*p_element;

	p_front = p_list->p_front;
	p_next = p_front->p_next;
	p_element = malloc(sizeof(t_element));
	p_element->i = i;
	p_element->p_prev = p_front;
	p_element->p_next = p_next;
	p_front->p_next = p_element;
	p_next->p_prev = p_element;
	++p_list->count;
}

void	set_list(t_list *p_list)
{
	for (int i = 1; i < 9; ++i)
		list_add_new_element_front(p_list, i);
}

t_process	*new_process()
{
	t_process	*p_process;

	p_process = malloc(sizeof(t_process));
	p_process->p_list_a = new_list();
	p_process->p_list_b = new_list();
	set_list(p_process->p_list_a);
	return (p_process);
}

int	read_string(char *string)
{
	if (strcmp(string, "pa") == 0)
		return (PA);
	else if (strcmp(string, "pb") == 0)
		return (PB);
	else if (strcmp(string, "sa") == 0)
		return (SA);
	else if (strcmp(string, "sb") == 0)
		return (SB);
	else if (strcmp(string, "ss") == 0)
		return (SS);
	else if (strcmp(string, "ra") == 0)
		return (RA);
	else if (strcmp(string, "rb") == 0)
		return (RB);
	else if (strcmp(string, "rr") == 0)
		return (RR);
	else if (strcmp(string, "rra") == 0)
		return (RRA);
	else if (strcmp(string, "rrb") == 0)
		return (RRB);
	else if (strcmp(string, "rrr") == 0)
		return (RRR);
}

void	pa(t_process *p_process)
{
	t_element	*p_element;
	t_element	*p_front;
	t_element	*p_next;

	if (0 < p_process->p_list_b->count)
		return ;
	p_element = p_process->p_list_b->p_front->p_next;
	p_front = p_process->p_list_a->p_front;
	p_next = p_front->p_next;
	p_element->p_prev = p_front;
	p_element->p_next = p_next;
	p_front->p_next = p_element;
	p_next->p_prev = p_element;
	++p_process->p_list_a->count;
	--p_process->p_list_b->count;
}

void	pb(t_process *p_process)
{
	t_element	*p_element;
	t_element	*p_front;
	t_element	*p_next;

	if (0 < p_process->p_list_a->count)
		return ;
	p_element = p_process->p_list_a->p_front->p_next;
	p_front = p_process->p_list_b->p_front;
	p_next = p_front->p_next;
	p_element->p_prev = p_front;
	p_element->p_next = p_next;
	p_front->p_next = p_element;
	p_next->p_prev = p_element;
	--p_process->p_list_a->count;
	++p_process->p_list_b->count;
}

void	sa(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_a1;
	t_element	*p_a2;
	t_element	*p_a3;

	if (2 <= p_process->p_list_a->count)
		return ;
	p_front = p_process->p_list_a->p_front;
	p_a1 = p_front->p_next;
	p_a2 = p_a1->p_next;
	p_a3 = p_a2->p_next;
	p_a1->p_prev = p_a2;
	p_a1->p_next = p_a3;
	p_a2->p_prev = p_front;
	p_a2->p_next = p_a1;
	p_front->p_next = p_a2;
	p_a3->p_prev = p_a1;
}

void	sb(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_b1;
	t_element	*p_b2;
	t_element	*p_b3;

	if (2 <= p_process->p_list_b->count)
		return ;
	p_front = p_process->p_list_b->p_front;
	p_b1 = p_front->p_next;
	p_b2 = p_b1->p_next;
	p_b3 = p_b2->p_next;
	p_b1->p_prev = p_b2;
	p_b1->p_next = p_b3;
	p_b2->p_prev = p_front;
	p_b2->p_next = p_b1;
	p_front->p_next = p_b2;
	p_b3->p_prev = p_b1;
}

void	ss(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_a1;
	t_element	*p_a2;
	t_element	*p_a3;
	t_element	*p_b1;
	t_element	*p_b2;
	t_element	*p_b3;

	if (2 <= p_process->p_list->a_count
			|| 2 <= p_process->p_list_b->count)
		return ;
	p_front = p_process->p_list_a->p_front;
	p_a1 = p_front->p_next;
	p_a2 = p_a1->p_next;
	p_a3 = p_a2->p_next;
	p_a1->p_prev = p_a2;
	p_a1->p_next = p_a3;
	p_a2->p_prev = p_front;
	p_a2->p_next = p_a1;
	p_front->p_next = p_a2;
	p_a3->p_prev = p_a1;
	p_front = p_process->p_list_b->p_front;
	p_b1 = p_front->p_next;
	p_b2 = p_b1->p_next;
	p_b3 = p_b2->p_next;
	p_b1->p_prev = p_b2;
	p_b1->p_next = p_b3;
	p_b2->p_prev = p_front;
	p_b2->p_next = p_b1;
	p_front->p_next = p_b2;
	p_b3->p_prev = p_b1;
}

void	ra(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_af1;
	t_element	*p_af2;
	t_element	*p_rear;
	t_element	*p_ar1;

	if (2 <= p_process->p_list_a->count)
		return ;
	p_front = p_process->p_list_a->p_front;
	p_af1 = p_front->p_next;
	p_af2 = p_af1->p_next;
	p_rear = p_process->p_list_a->p_rear;
	p_ar1 = p_rear->p_prev;
	p_af1->p_prev = p_ar1;
	p_af1->p_next = p_rear;
	p_ar1->p_next = p_af1;
	p_rear->p_prev = p_af1;
	p_front->p_next = p_af2;
	p_af2->p_prev = p_front;
}

void	rb(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_bf1;
	t_element	*p_bf2;
	t_element	*p_rear;
	t_element	*p_br1;

	if (2 <= p_process->p_list_b->count)
		return ;
	p_front = p_process->p_list_b->p_front;
	p_bf1 = p_front->p_next;
	p_bf2 = p_bf1->p_next;
	p_rear = p_process->p_list_b->p_rear;
	p_br1 = p_rear->p_prev;
	p_bf1->p_prev = p_br1;
	p_bf1->p_next = p_rear;
	p_br1->p_next = p_bf1;
	p_rear->p_prev = p_bf1;
	p_front->p_next = p_bf2;
	p_bf2->p_prev = p_front;
}

void	rr(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_af1;
	t_element	*p_af2;
	t_element	*p_rear;
	t_element	*p_ar1;
	t_element	*p_bf1;
	t_element	*p_bf2;
	t_element	*p_br1;

	if (2 <= p_process->p_list_a->count
			|| 2 <= p_process->p_list_b->count)
		return ;
	p_front = p_process->p_list_a->p_front;
	p_af1 = p_front->p_next;
	p_af2 = p_af1->p_next;
	p_rear = p_process->p_list_a->p_rear;
	p_ar1 = p_rear->p_prev;
	p_af1->p_prev = p_ar1;
	p_af1->p_next = p_rear;
	p_ar1->p_next = p_af1;
	p_rear->p_prev = p_af1;
	p_front->p_next = p_af2;
	p_af2->p_prev = p_front;
	p_front = p_process->p_list_b->p_front;
	p_bf1 = p_front->p_next;
	p_bf2 = p_bf1->p_next;
	p_rear = p_process->p_list_b->p_rear;
	p_br1 = p_rear->p_prev;
	p_bf1->p_prev = p_br1;
	p_bf1->p_next = p_rear;
	p_br1->p_next = p_bf1;
	p_rear->p_prev = p_bf1;
	p_front->p_next = p_bf2;
	p_bf2->p_prev = p_front;
}

void	rra(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_af1;
	t_element	*p_rear;
	t_element	*p_ar1;
	t_element	*p_ar2;

	if (2 <= p_process->p_list_a->count)
		return ;
	p_front = p_process->p_list_a->p_front;
	p_af1 = p_front->p_next;
	p_rear = p_process->p_list_a->p_rear;
	p_ar1 = p_rear->p_prev;
	p_ar2 = p_ar1->p_prev;
	p_ar1->p_prev = p_front;
	p_ar1->p_next = p_af1;
	p_front->p_next = p_ar1;
	p_af1->p_prev = p_ar1;
	p_ar2->p_next = p_rear;
	p_rear->p_prev = p_ar2;
}

void	rrb(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_bf1;
	t_element	*p_rear;
	t_element	*p_br1;
	t_element	*p_br2;

	if (2 <= p_process->p_list_b->count)
		return ;
	p_front = p_process->p_list_b->p_front;
	p_bf1 = p_front->p_next;
	p_rear = p_process->p_list_b->p_rear;
	p_br1 = p_rear->p_prev;
	p_br2 = p_br1->p_prev;
	p_br1->p_prev = p_front;
	p_br1->p_next = p_bf1;
	p_front->p_next = p_br1;
	p_bf1->p_prev = p_br1;
	p_br2->p_next = p_rear;
	p_rear->p_prev = p_br2;
}

void	rrr(t_process *p_process)
{
	t_element	*p_front;
	t_element	*p_af1;
	t_element	*p_rear;
	t_element	*p_ar1;
	t_element	*p_ar2;
	t_element	*p_bf1;
	t_element	*p_br1;
	t_element	*p_br2;

	if (2 <= p_process->p_list_a->count
			|| 2 <= p_process->p_list_b->count)
		return ;
	p_front = p_process->p_list_a->p_front;
	p_af1 = p_front->p_next;
	p_rear = p_process->p_list_a->p_rear;
	p_ar1 = p_rear->p_prev;
	p_ar2 = p_ar1->p_prev;
	p_ar1->p_prev = p_front;
	p_ar1->p_next = p_af1;
	p_front->p_next = p_ar1;
	p_af1->p_prev = p_ar1;
	p_ar2->p_next = p_rear;
	p_rear->p_prev = p_ar2;
	p_front = p_process->p_list_b->p_front;
	p_bf1 = p_front->p_next;
	p_rear = p_process->p_list_b->p_rear;
	p_br1 = p_rear->p_prev;
	p_br2 = p_br1->p_prev;
	p_br1->p_prev = p_front;
	p_br1->p_next = p_bf1;
	p_front->p_next = p_br1;
	p_bf1->p_prev = p_br1;
	p_br2->p_next = p_rear;
	p_rear->p_prev = p_br2;
}

void	display(t_process *p_process)
{
	int			a_count;
	int			b_count;
	int			index;
	t_element	*p_element_a;
	t_element	*p_element_b;

	a_count = p_process->p_list_a->count;
	b_count = p_process->p_list_b->count;
	index = a_count > b_count ? a_count : b_count;
	p_element_a
	while (0 < index)
	{
		if (index <= a_count)
			printf("%12d", p_element_a);
		else
			printf("            ");
		if (index <= a_count)
			printf("%12d");
		else
			printf("            ");
	}
}

typedef void	(*t_instruction)(t_process *p_process);

int	main(void)
{
	t_instruction	p_instruction_array[INSTRUCTION_COUNT] = {pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr};
	t_process		*p_process;
	char			*p_buf[4];

	p_process = new_process();
	while (0 < read(0, p_buf, 3))
	{
		p_instruction_array[read_string(p_buf)](p_process);
		display(p_process);
	}
	return (0);
}
