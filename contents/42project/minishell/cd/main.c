#include <stdio.h>	// printf()
#include <unistd.h>	// chdir(), execve()

#define GROUND001

#define fileName	"myEcho0.out"
#define fileDirectory	"myEcho"

#ifdef GROUND001
int	main(int argc, char **argv, char **envp) {
	(void)argc;
	(void)argv;

	char*	myArgv[2] = { fileName, 0 };

	chdir(fileDirectory);
	execve(myArgv[0], myArgv, envp);
	printf("Failed execve!\n");

	return 0;
}
#endif

#ifdef GROUND000
int	main(int argc, char **argv, char **envp) {
	(void)argc;
	(void)argv;

	char*	myArgv[2] = { fileDirectory "/" fileName, 0 };

	execve(myArgv[0], myArgv, envp);
	printf("Failed execve!\n");

	return 0;
}
#endif
