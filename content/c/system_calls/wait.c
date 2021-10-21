#include <unistd.h>	// fork(), pid_t, sleep(), getpgid()
#include <stdio.h>	// printf(), perror()
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// wait()

#define NORMAL	0
#define ERROR	1



///	- print rusage.
///	- result:
///		This is child1 process.
///		tv_sec: [0], tv_usec: [124]
///		tv_sec: [0], tv_usec: [186]
///		rusage->ru_maxress: [450560].
///		rusage->ru_ixrss: [0].
///		rusage->ru_idrss: [0].
///		rusage->ru_isrss: [0].
///		rusage->ru_minflt: [126].
///		rusage->ru_majflt: [0].
///		rusage->ru_nswap: [0].
///		rusage->ru_inblock: [0].
///		rusage->ru_oublock: [0].
///		rusage->ru_msgsnd: [0].
///		rusage->ru_msgrcv: [0].
///		rusage->ru_nsignals: [0].
///		rusage->ru_nvcsw: [0].
///		rusage->ru_nivcsw: [1].
///	- There is lots of information than I expected.



void	timeval_describe(struct timeval *timeval)
{
	printf("tv_sec: [%ld], tv_usec: [%d] \n", timeval->tv_sec, timeval->tv_usec);
}

void	rusage_describe(struct rusage *rusage)
{
	timeval_describe(&rusage->ru_utime);
	timeval_describe(&rusage->ru_stime);
	printf("rusage->ru_maxress: [%ld]. \n", rusage->ru_maxrss);
	printf("rusage->ru_ixrss: [%ld]. \n", rusage->ru_ixrss);
	printf("rusage->ru_idrss: [%ld]. \n", rusage->ru_idrss);
	printf("rusage->ru_isrss: [%ld]. \n", rusage->ru_isrss);
	printf("rusage->ru_minflt: [%ld]. \n", rusage->ru_minflt);
	printf("rusage->ru_majflt: [%ld]. \n", rusage->ru_majflt);
	printf("rusage->ru_nswap: [%ld]. \n", rusage->ru_nswap);
	printf("rusage->ru_inblock: [%ld]. \n", rusage->ru_inblock);
	printf("rusage->ru_oublock: [%ld]. \n", rusage->ru_oublock);
	printf("rusage->ru_msgsnd: [%ld]. \n", rusage->ru_msgsnd);
	printf("rusage->ru_msgrcv: [%ld]. \n", rusage->ru_msgrcv);
	printf("rusage->ru_nsignals: [%ld]. \n", rusage->ru_nsignals);
	printf("rusage->ru_nvcsw: [%ld]. \n", rusage->ru_nvcsw);
	printf("rusage->ru_nivcsw: [%ld]. \n", rusage->ru_nivcsw);
}

void	child()
{
	printf("This is child1 process. \n");
	exit(2);
}

void	parent(pid_t pid)
{
	int				stat_loc;
	struct rusage	rusage;

	wait4(pid, &stat_loc, 0, &rusage);
	rusage_describe(&rusage);
}



int	main()
{
	pid_t	pid;

	pid = 0;

	pid = fork();
	if (pid == -1)
		return (ERROR);
	else if (pid == 0)
		child();

	parent(pid);

	return (NORMAL);
}
