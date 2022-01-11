#include <hardware_interrupt.h>

#define signal_count 32

typedef struct	s_signal
{
	pid_t		pid;
	int			signal;
}				t_signal;

typedef struct	s_command
{
	int			argc;
	char		**argv;
}				t_command;



typedef struct	s_process
{
	pid_t		pid;
	sigfunction	sigfunctions[signal_count];
}				t_process;

typedef struct	s_parent_of_process
{
	t_process	*p_processes;
	t_process	*p_foreground;
	t_signal	*p_signal;
	t_command	*p_command;
	sigfunction	sigfunction[signal_count];
}				t_parent_of_process;



void	do_signal(t_parent_of_process *p_pprocess)
{
	if (signal is default)
		p_pprocess->sigfunction[signal]();
	else
		p_process->sigfunction[signal]();
}

void	terminal_run(t_parent_of_process *p_pprocess)
{
	while (get_command())
		run_command();
}

void	main()
{
	t_parent_of_process	*p_pprocess = new_parent_of_process();

	hardware_add_interrupt_signal(do_signal);
	terminal_run(p_pprocess);
}
