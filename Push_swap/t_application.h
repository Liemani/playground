#ifndef T_APPLICATION_H
# define T_APPLICATION_H

# include "t_instruction.h"
# include "t_branch.h"

typedef struct		s_application
{
	t_instruction	instruction_array[INSTRUCTION_COUNT];
	t_branch		list;
	int				depth;
}					t_application;

void				init_application(t_application *p_application, int argc, char **argv);
void				application_run(t_application *p_application);

#endif
