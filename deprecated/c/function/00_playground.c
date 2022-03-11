#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include "../lmt.h"

#define IN	0
#define OUT	1
#define ERR	2

#define EXECUTE	a007
#define PARAMETERS	char **argv, char **envp
#define ARGUMENTS	argv, envp

//	Print parent pid
void	a007(PARAMETERS)
{
	pid_t	ppid;

	(void)argv;
	(void)envp;
	ppid = getppid();
	PRINT(ppid, d);
}

//	What would happen if sleep until child to terminate and call wait() the terminated child?
//		Print the return value and errno
void	a006(PARAMETERS)
{
	pid_t	pid;
	int	stat_loc;

	(void)argv;
	(void)envp;
	pid = fork();
	PRINT(pid, d);
	if (pid > 0)
		sleep(1);
	else
		exit(0);
	pid = waitpid(pid, &stat_loc, 0);
	PRINT(pid, d);
	PRINT(errno, d);
	perror(NULL);
}

void	a005(PARAMETERS)
{
	DIR	*p_dir;

	(void)argv;
	(void)envp;
	p_dir = opendir(".");
}

void	a004(PARAMETERS)
{
	(void)envp;
	argv[1] = NULL;
	printf("eof \n");
}

//	print '$PATH' and all env

void	a003(PARAMETERS)
{
	char	*env_path;

	(void)argv;
	(void)envp;
	env_path = getenv("PATH");
	printf("env_path: [%s] \n", env_path);
	while (*envp != NULL)
	{
		printf("*envp: [%s] \n", *envp);
		++envp;
	}
}

//	write after close fd

void	a002(PARAMETERS)
{
	int	fd;

	(void)argv;
	(void)envp;
	fd = open("test", O_WRONLY | O_CREAT | O_TRUNC);
	if (write(fd, "before\n", 7) == -1)
		return ;
	close(fd);
	if (write(fd, "after\n", 6) == -1)
	{
		printf("%d is invalid \n", fd);
		return ;
	}
}



typedef struct s_command
{
	int		fd[3];
}	t_command;



//void	command_init(t_command *p_command, char *path, char **argv)
//{
//	p_command->path = path;
//	p_command->argv = argv;
//}

void	b002(PARAMETERS)
{
//	int	test_fd;

//	test_fd = open("test", O_WRONLY | O_CREAT | O_TRUNC);
//	if (test_fd == -1)
//		return ;
//	if (dup2(test_fd, OUT) == -1)
//		return ;

//	'/' 을 포함하고 있으면 builtin command 를 실행하지 않는다 (basename 이 builtin command 이더라도)
//		echo -> builtin
//		/bin/echo -> /bin/echo
//		./echo ->./echo
	if (execve(*argv, argv, envp) == -1)
	{
		printf("%d: %s \n", errno, strerror(errno));
		return ;
	}
}

void	b001()
{
	int		status;
	pid_t	waiting_pid;

	waiting_pid = wait(&status);
	printf("Finish waiting [%d] \n", waiting_pid);
}

void	a001(PARAMETERS)
{
//	t_command	command1;
//	t_command	command2;
	int			child_pid;
//	int			pipe_fd[2];
//
//	if (pipe(pipe_fd) == -1)
//		return ;
//	command1->argv = argv[1];





	child_pid = fork();
	if (child_pid == -1)
		return ;
	if (child_pid > 0)
		b001();
	else
		b002(argv + 1, envp);
}

int	main(int argc, PARAMETERS)
{
	(void)argc;
	EXECUTE(ARGUMENTS);
	return (0);
}
