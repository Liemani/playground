#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

#define FALSE	0
#define TRUE	1

int	global_variable;

typedef void    (*t_signal_handler)(int);

static void lmt_signal_set(int signal_number, t_signal_handler handler)
{
    if (signal(signal_number, handler) == SIG_ERR)
       printf("signal() failed in lmt_signal_set() \n");
}

static void signal_handler_sigint(int signal)
{
    (void)signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void    lmt_signal_init(void)
{
    lmt_signal_set(SIGINT, signal_handler_sigint);
    lmt_signal_set(SIGQUIT, SIG_IGN);
}



int	main()
{
	char	*line;

	lmt_signal_init();
	while ((line = readline("<prompt>")) != NULL)
	{
		printf("line -> [%s] as %%s \n", line);
		add_history(line);
		free(line);
	}

	return (0);
}
