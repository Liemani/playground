//	http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/?C=M;O=D


#define EXECUTE	a006

//	chapter 1, page 41
#include <stdio.h>

void	a006()
{
	int	ch;

	printf("hello\n");
	printf("there\n");
	ch = getchar();
	printf("\033[1;1Hhi\n");
	printf("\033[7m[there]");
}

//	chpater 1, page 40
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>

void	a005()
{
	int				tty;
	struct winsize	window_structure;

	tty = open("/dev/tty", O_RDONLY);
	if (tty == -1)
		return;
	if (ioctl(tty, TIOCGWINSZ, &window_structure) == -1)
		return;
	printf("row: %d, col: %d \n", window_structure.ws_row, window_structure.ws_col);
	printf("xpixel: %d, ypixel: %d \n", window_structure.ws_xpixel, window_structure.ws_ypixel);
}

// chapter 1, page 37
#include <stdio.h>

void	a004()
{
	FILE	*tty;
	int		ch;

	tty = fopen("/dev/tty", "r");
	while ((ch = fgetc(tty)) != EOF)
	{
		if (ch == 'q')
			break;
		putchar(ch);
		putchar('\n');
	}
	if (ch == EOF)
		printf("EOF occured \n");
}


//	chapter 1, page 36
#include <stdio.h>

void	a003()
{
	FILE	*tty;
	tty = fopen("/dev/tty", "w");
	if (tty == NULL)
		return;
	fprintf(tty, "hi \n");
}

//	chapter 1, page 12
#define _GNU_SOURCE
#include <unistd.h>
//	#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>

void	a002()
{
//		printf("Thread id %d \n", syscall(SYS_gettid));
	//	could also pass __NR_gettid
}

//	chapter 1, page 5
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	a001()
{
	pid_t	pid;
	uid_t	uid;
	uid_t	euid;
	gid_t	gid;
	gid_t	egid;

	pid = getpid();
	uid = getuid();
	euid = geteuid();
	gid = getgid();
	egid = getegid();

	printf("I am the process with process-id %d \n", pid);
	printf("I am the process with user-id %d \n", uid);
	printf("I am the process with effective-user-id %d \n", euid);
	printf("I am the process with grouop-id %d \n", gid);
	printf("I am the process with effective-group-id %d \n", egid);

	char	*command = getenv("_");

	printf("Current command is [%s] \n", command);
}

//	chapter 1, page 3
#include <stdio.h>

void	a000()
{
	int	c;

	while ((c = getchar()) != EOF)
		putchar(c);
}

int	main()
{
	EXECUTE();
	return (0);
}
