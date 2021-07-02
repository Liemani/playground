#include <stdlib.h>
#include <unistd.h>

#define EXECUTE	a001

void	a001(int argc, char **argv, char **envp)
{
	char	**process_argv;
	int		index;

	process_argv = malloc(sizeof(char *) * (argc + 1));
	process_argv[0] = "/bin/ls";
	index = 1;
	while (index < argc)
	{
		process_argv[index] = argv[index];
		++index;
	}
	process_argv[index] = NULL;
	execve("/bin/ls", process_argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	EXECUTE(argc, argv, envp);
	return (0);
}
