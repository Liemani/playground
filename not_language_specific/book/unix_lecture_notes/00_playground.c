//	http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/?C=M;O=D


#define EXECUTE	a008

//	lmt_exit()
#include <stdio.h>
#include <stdlib.h>

static void	lmt_exit(const char *string)
{
	fprintf(stderr, "%s", string);
	exit(1);
}

//	chapter 2, page 44
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef NEW_FILE_MODE
#define NEW_FILE_MODE	0644
#endif

void	a008(int argc, char **argv)
{
	int		source_fd;
	int		target_fd;
	off_t	file_size;
	char	null_byte;
	void	*source_addr;
	void	*target_addr;

	if (argc != 3)
		lmt_exit("usage: ./a.out <source> <target> \n");

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
		lmt_exit("Failed open source file. \n");
	target_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, NEW_FILE_MODE);
	if (target_fd == -1)
		lmt_exit("Failed open target file. \n");

	file_size = lseek(source_fd, 0, SEEK_END);
	if (file_size == -1)
		lmt_exit("Failed lseek source fd. \n");
	lseek(target_fd, file_size - 1, SEEK_SET);
	null_byte = '\0';
	write(target_fd, &null_byte, 1);

	source_addr = mmap(NULL, file_size, PROT_READ, MAP_SHARED, source_fd, 0);
	if (source_addr == MAP_FAILED)
		lmt_exit("Failed mmap source file. \n");
	target_addr = mmap(NULL, file_size, PROT_WRITE, MAP_SHARED, target_fd, 0);
	if (target_addr == MAP_FAILED)
		lmt_exit("Failed mmap target file. \n");

	memcpy(target_addr, source_addr, file_size);

	if (munmap(source_addr, file_size) == -1)
		lmt_exit("Failed munmap source file. \n");
	if (munmap(target_addr, file_size) == -1)
		lmt_exit("Failed munmap target file. \n");

	if (close(source_fd) == -1)
		lmt_exit("Failed close source file. \n");
	if (close(target_fd) == -1)
		lmt_exit("Failed close target file. \n");
}

//	chapter 2, page 39
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE		512
#endif

#ifndef NEW_FILE_MODE
#define NEW_FILE_MODE	0644
#endif

void	a007(int argc, char **argv)
{
	size_t	buffer_size = atoi(argv[3]) > 0 ? atoi(argv[3]) : BUFFER_SIZE;
	int		source_fd;
	int		target_fd;
	char	buffer[buffer_size];
	int		number_of_read_bytes;

	if (argc != 4)
	{
		fprintf(stderr, "usage: %s <source> <target> <buffer_size> \n", argv[0]);
		exit(1);
	}

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		fprintf(stderr, "Failed to open file %s. \n", argv[1]);
		exit(1);
	}
	target_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, NEW_FILE_MODE);
	if (target_fd == -1)
	{
		fprintf(stderr, "Failed to open file %s. \n", argv[2]);
		exit(1);
	}

	while ((number_of_read_bytes = read(source_fd, buffer, buffer_size)) > 0)
	{
		if (write(target_fd, buffer, number_of_read_bytes) != number_of_read_bytes)
		{
			fprintf(stderr, "Failed writing target_fd \n");
			exit(1);
		}
	}
	if (number_of_read_bytes == -1)
	{
		fprintf(stderr, "Failed reading source_fd. \n");
		exit(1);
	}
	printf("Copy finished. \n");
	if (close(source_fd) == -1)
	{
		fprintf(stderr, "Failed closing source_fd. \n");
		exit(1);
	}
	if (close(target_fd) == -1)
	{
		fprintf(stderr, "Failed closing target_fd. \n");
		exit(1);
	}
}

//	chapter 1, page 41
#include <stdio.h>

void	a006(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

void	a005(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

void	a004(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

void	a003(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

void	a002(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//		printf("Thread id %d \n", syscall(SYS_gettid));
	//	could also pass __NR_gettid
}

//	chapter 1, page 5
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	a001(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

void	a000(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	c;

	while ((c = getchar()) != EOF)
		putchar(c);
}

int	main(int argc, char **argv)
{
	EXECUTE(argc, argv);
	return (0);
}
