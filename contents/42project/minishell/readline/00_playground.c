#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>

#define FALSE	0
#define TRUE	1

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

void    signal_set_reading(void)
{
    lmt_signal_set(SIGINT, signal_handler_sigint);
    lmt_signal_set(SIGQUIT, SIG_IGN);
}

void	signal_set_parsing(void)
{
	lmt_signal_set(SIGINT, SIG_IGN);
}

void	signal_set_child(void)
{
	lmt_signal_set(SIGINT, SIG_DFL);
	lmt_signal_set(SIGQUIT, SIG_DFL);
}

static void	set_readline_variable(void)
{
	rl_catch_signals = 0;
}

//	static void	set_termios(void)
//	{
//		struct termios	termios;
//		unsigned long	isig;
//	
//		tcgetattr(1, &termios);
//		isig = (termios.c_lflag & ISIG) != 0;
//		printf("Current ISIG setting: %lu \n", isig);
//		termios.c_lflag |= ISIG;
//		tcsetattr(1, TCSADRAIN, &termios);
//	}

static int	eof_occured(char *line)
{
	return (line == NULL);
}



int	main(int argc, char **argv, char **envp)
{
	char	*line;
	pid_t	pid;
	int		stat_loc;

	if (argc != 3)
	{
		printf("usage: %s sleep <time>", argv[0]);
		exit(1);
	}

	set_readline_variable();
//		set_termios();
	signal_set_reading();

	while ((line = readline("<prompt> ")) != NULL)
	{
		signal_set_parsing();
		printf("line -> [%s] as %%s \n", line);
		if (*line != '\0')
			add_history(line);
		free(line);
		pid = fork();
		if (pid == 0)
		{
			signal_set_child();
			execve("/bin/sleep", argv + 1, envp);
		}
		else
			wait(&stat_loc);
		signal_set_reading();
	}
	if (eof_occured(line))
	{
//			rl_replace_line("exit\n", 0);
//			rl_redisplay();
		printf("\nexit\n");
	}

	return (0);
}
