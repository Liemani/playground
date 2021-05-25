#include "t_application.h"
#include "t_instruction.h"
#include "t_branch.h"

void	apply_argument(t_application *p_application, int argc, char **argv)
{
}

void	init_application(t_application *p_application, int argc, char **argv)
{
	t_instruction	*p_instruction;

	p_instruction = p_application->instruction_array;
	*p_instruction++ = pa;
	*p_instruction++ = pb;
	*p_instruction++ = sa;
	*p_instruction++ = sb;
	*p_instruction++ = ss;
	*p_instruction++ = ra;
	*p_instruction++ = rb;
	*p_instruction++ = rr;
	*p_instruction++ = rra;
	*p_instruction++ = rrb;
	*p_instruction = rrr;
	init_branch(&p_application->list);
	p_application->depth = 0;
	apply_argument(p_application, argc, argv);
}

bfs(t_application t_application)
{
	



	instruction_index = 0;
	while (count < maximum count)
	{
		if (check(instruction))
		{
			make child;
			do instruction;
		}
	}
}

void	application_run(t_application *p_application)
{
	bfs(p_application);
}
