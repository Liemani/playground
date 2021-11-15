#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#include <termios.h>
#include <fcntl.h>
#include <ncurses.h>

#include "libft.h"
// #include "ft_printf.h"
#include "lmt.h"

#define EXECUTE a085
//	#define EXECUTE a078	//	print key character value



int	a085(void)
{
	const char	*str = "\033A";
	const char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		printf("[%c] == [%d] \n", *ptr, *ptr);
		++ptr;
	}
	return (0);
}



int	a084(void)
{
	void	*ptr;

	ptr = NULL;
	++ptr;
	return (0);
}



int	a083(void)
{
	unsigned int	x = 0xFFFFFFFF;
	int				*y;

	y = (int *)&x;
	printf("y: [%p] as %%d\n", y);
	return (0);
}



int	a082()
{
    int ch;

	ch = 0;
//	    initscr(); cbreak(); noecho();
//	    while (1)
//	    {
//	        ch = getch();
//	        printf("%c\n", ch);
//	    }
	while ((ch = getchar()) != EOF)
		printf("ch: [%c] [%d] \n", ch, ch);
	return (0);
}



void	a081_inner()
{
	int	i;

	printf("Address of i in a001_inner: [%p]\n", &i);
}

int	a081()
{
	int	i;

	printf("Address of i in a081: [%p]\n", &i);
	a081_inner();
	return (0);
}



//	struct termios {
//	    tcflag_t        c_iflag;        // input flags
//	    tcflag_t        c_oflag;        // output flags
//	    tcflag_t        c_cflag;        // control flags
//	    tcflag_t        c_lflag;        // local flags
//	    cc_t            c_cc[NCCS];     // control chars
//	    speed_t         c_ispeed;       // input speed
//	    speed_t         c_ospeed;       // output speed
//	};

const char	*has_flag(tcflag_t c_flag, tcflag_t flag)
{
	if ((c_flag & flag) != 0)
		return ("\033[32mtrue\033[0m");
	else
		return ("\033[31mfalse\033[0m");
}

void	termios_describe_input_flag(tcflag_t c_iflag)
{
	printf("IGNBRK:	[%s]\n", has_flag(c_iflag, IGNBRK));
	printf("BRKINT:	[%s]\n", has_flag(c_iflag, BRKINT));
	printf("IGNPAR:	[%s]\n", has_flag(c_iflag, IGNPAR));
	printf("PARMRK:	[%s]\n", has_flag(c_iflag, PARMRK));
	printf("INPCK:	[%s]\n", has_flag(c_iflag, INPCK));
	printf("ISTRIP:	[%s]\n", has_flag(c_iflag, ISTRIP));
	printf("INLCR:	[%s]\n", has_flag(c_iflag, INLCR));
	printf("IGNCR:	[%s]\n", has_flag(c_iflag, IGNCR));
	printf("ICRNL:	[%s]\n", has_flag(c_iflag, ICRNL));
	printf("IXON:	[%s]\n", has_flag(c_iflag, IXON));
	printf("IXOFF:	[%s]\n", has_flag(c_iflag, IXOFF));
	printf("IXANY:	[%s]\n", has_flag(c_iflag, IXANY));
	printf("IMAXBEL:[%s]\n", has_flag(c_iflag, IMAXBEL));
	printf("IUTF8:	[%s]\n", has_flag(c_iflag, IUTF8));
}

void	termios_describe_output_flag(tcflag_t c_oflag)
{
	printf("OPOST:	[%s]\n", has_flag(c_oflag, OPOST));
	printf("ONLCR:	[%s]\n", has_flag(c_oflag, ONLCR));
	printf("OXTABS:	[%s]\n", has_flag(c_oflag, OXTABS));
	printf("ONOEOT:	[%s]\n", has_flag(c_oflag, ONOEOT));
	printf("OCRNL:	[%s]\n", has_flag(c_oflag, OCRNL));
	printf("ONOCR:	[%s]\n", has_flag(c_oflag, ONOCR));
	printf("ONLRET:	[%s]\n", has_flag(c_oflag, ONLRET));
	printf("OFILL:	[%s]\n", has_flag(c_oflag, OFILL));
	printf("NLDLY:	[%s]\n", has_flag(c_oflag, NLDLY));
	printf("TABDLY:	[%s]\n", has_flag(c_oflag, TABDLY));
	printf("CRDLY:	[%s]\n", has_flag(c_oflag, CRDLY));
	printf("FFDLY:	[%s]\n", has_flag(c_oflag, FFDLY));
	printf("BSDLY:	[%s]\n", has_flag(c_oflag, BSDLY));
	printf("VTDLY:	[%s]\n", has_flag(c_oflag, VTDLY));
	printf("OFDEL:	[%s]\n", has_flag(c_oflag, OFDEL));
}

void	termios_describe_control_flag(tcflag_t c_cflag)
{
	printf("CIGNORE:	[%s]\n", has_flag(c_cflag, CIGNORE));
	printf("CSIZE:		[%s]\n", has_flag(c_cflag, CSIZE));
	printf("CS5:		[%s]\n", has_flag(c_cflag, CS5));
	printf("CS6:		[%s]\n", has_flag(c_cflag, CS6));
	printf("CS7:		[%s]\n", has_flag(c_cflag, CS7));
	printf("CS8:		[%s]\n", has_flag(c_cflag, CS8));
	printf("CSTOPB:		[%s]\n", has_flag(c_cflag, CSTOPB));
	printf("CREAD:		[%s]\n", has_flag(c_cflag, CREAD));
	printf("PARENB:		[%s]\n", has_flag(c_cflag, PARENB));
	printf("PARODD:		[%s]\n", has_flag(c_cflag, PARODD));
	printf("HUPCL:		[%s]\n", has_flag(c_cflag, HUPCL));
	printf("CLOCAL:		[%s]\n", has_flag(c_cflag, CLOCAL));
	printf("CCTS_OFLOW:	[%s]\n", has_flag(c_cflag, CCTS_OFLOW));
	printf("CRTS_IFLOW:	[%s]\n", has_flag(c_cflag, CRTS_IFLOW));
	printf("CDTR_IFLOW:	[%s]\n", has_flag(c_cflag, CDTR_IFLOW));
	printf("CDSR_OFLOW:	[%s]\n", has_flag(c_cflag, CDSR_OFLOW));
	printf("CCAR_OFLOW:	[%s]\n", has_flag(c_cflag, CCAR_OFLOW));
	printf("MDMBUF:		[%s]\n", has_flag(c_cflag, MDMBUF));
}

void	termios_describe_local_flag(tcflag_t c_lflag)
{
	printf("ECHOKE:		[%s]\n", has_flag(c_lflag, ECHOKE));
	printf("ECHOE:		[%s]\n", has_flag(c_lflag, ECHOE));
	printf("ECHOK:		[%s]\n", has_flag(c_lflag, ECHOK));
	printf("ECHO:		[%s]\n", has_flag(c_lflag, ECHO));
	printf("ECHONL:		[%s]\n", has_flag(c_lflag, ECHONL));
	printf("ECHOPRT:	[%s]\n", has_flag(c_lflag, ECHOPRT));
	printf("ECHOCTL:	[%s]\n", has_flag(c_lflag, ECHOCTL));
	printf("ISIG:		[%s]\n", has_flag(c_lflag, ISIG));
	printf("ICANON:		[%s]\n", has_flag(c_lflag, ICANON));
	printf("ALTWERASE:	[%s]\n", has_flag(c_lflag, ALTWERASE));
	printf("IEXTEN:		[%s]\n", has_flag(c_lflag, IEXTEN));
	printf("EXTPROC:	[%s]\n", has_flag(c_lflag, EXTPROC));
	printf("TOSTOP:		[%s]\n", has_flag(c_lflag, TOSTOP));
	printf("FLUSHO:		[%s]\n", has_flag(c_lflag, FLUSHO));
	printf("NOKERNINFO:	[%s]\n", has_flag(c_lflag, NOKERNINFO));
	printf("PENDIN:		[%s]\n", has_flag(c_lflag, PENDIN));
	printf("NOFLSH:		[%s]\n", has_flag(c_lflag, NOFLSH));
}

void	termios_describe_control_character(cc_t *c_cc)
{
	printf("VEOF:		[%d]\n", c_cc[VEOF]);
	printf("VEOL:		[%d]\n", c_cc[VEOL]);
	printf("VEOL2:		[%d]\n", c_cc[VEOL2]);
	printf("VERASE:		[%d]\n", c_cc[VERASE]);
	printf("VWERASE:	[%d]\n", c_cc[VWERASE]);
	printf("VKILL:		[%d]\n", c_cc[VKILL]);
	printf("VREPRINT:	[%d]\n", c_cc[VREPRINT]);
	printf("VINTR:		[%d]\n", c_cc[VINTR]);
	printf("VQUIT:		[%d]\n", c_cc[VQUIT]);
	printf("VSUSP:		[%d]\n", c_cc[VSUSP]);
	printf("VDSUSP:		[%d]\n", c_cc[VDSUSP]);
	printf("VSTART:		[%d]\n", c_cc[VSTART]);
	printf("VSTOP:		[%d]\n", c_cc[VSTOP]);
	printf("VLNEXT:		[%d]\n", c_cc[VLNEXT]);
	printf("VDISCARD:	[%d]\n", c_cc[VDISCARD]);
	printf("VMIN:		[%d]\n", c_cc[VMIN]);
	printf("VTIME:		[%d]\n", c_cc[VTIME]);
	printf("VSTATUS:	[%d]\n", c_cc[VSTATUS]);
	printf("NCCS:		[%d]\n", c_cc[NCCS]);
}

void	termios_describe(struct termios *termios)
{
	printf("	Input flag\n");
	termios_describe_input_flag(termios->c_iflag);
	printf("	Output flag\n");
	termios_describe_output_flag(termios->c_oflag);
	printf("	Control flag\n");
	termios_describe_control_flag(termios->c_cflag);
	printf("	Local flag\n");
	termios_describe_local_flag(termios->c_lflag);
	printf("	Control character\n");
	termios_describe_control_character(termios->c_cc);
}

int	a080()
{
	struct termios	termios;

	tcgetattr(0, &termios);
	termios_describe(&termios);
	return (0);
}



int	a079()
{
	struct termios	termios;

	tcgetattr(0, &termios);
	PRINT(cfgetispeed(&termios), lu);
	PRINT(cfgetospeed(&termios), lu);
	cfsetspeed(&termios, B50);
	tcsetattr(0, TCSADRAIN, &termios);
	PRINT(cfgetispeed(&termios), lu);
	PRINT(cfgetospeed(&termios), lu);
	return (0);
}



int	a078()
{
	struct termios	buf, save;
	int				ch;
//		int				flag;

	tcgetattr(0, &save);
	termios_describe(&save);
	cfmakeraw(&buf);
//		termios_describe(&buf);
	buf = save;

	buf.c_lflag &= ~(ICANON|ECHO);

	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
//		termios_describe(&buf);

	tcsetattr(0, TCSAFLUSH, &buf);
//		flag = fcntl(0, F_GETFL);
//		fcntl(0, F_SETFL, (flag | O_APPEND));
	while (1)
	{
		ch = getchar();
		if (ch != EOF)
			printf("ch: [%c] == [%d]\n", ch, ch);
	}
	tcsetattr(0, TCSAFLUSH, &save);
	printf("Last ch: [%c] == [%d]\n", ch, ch);
	perror(NULL);
	return (0);
}



int	a077()
{
	PRINT(-123 / 10, d);
	return (0);
}



int	a076()
{
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
	PRINT(sizeof(int *), lu);
	return (0);
}



static void	print_string(char *str)
{
	printf("%s\n", str);
}

int	a075()
{
	print_string("hi");
	return (0);
}



int	a074()
{
	return (300);
}



void	a073()
{
	int	a;
	int	*b;

	b = &a;
	--b;
	*b = 0;
	return ;
}



void	a072()
{
	char	*err_str;

	perror("hi");
	err_str = strerror(errno);
	printf("%s: %s\n", "hi", err_str);
}



//	typedef void	*(*t_prev)(void *);
//	typedef void	*(*t_next)(void *);
//	
//	typedef struct s_protocol_iterable
//	{
//		void	*first;
//		void	*terminator;
//		t_prev	prev;
//		t_next	next;
//	}	t_protocol_iterable;
//	
//	char	*string_prev(char *p_ch)
//	{
//		return (p_ch - 1);
//	}
//	
//	char	*string_next(char *p_ch)
//	{
//		return (p_ch + 1);
//	}
//	
//	void	a071()
//	{
//		char		*string = "Hello, World!\n";
//		t_iterable	string_iterator;
//		char		*iterator;
//	
//		string_iterator.first = string;
//		string_iterator.terminator = string + 14;
//		string_iterator.prev = (t_prev)string_prev;
//		string_iterator.next = (t_next)string_next;
//	
//		iterator = string_iterator.first;
//		while (iterator != string_iterator.terminator)
//		{
//			printf("%c \n", *iterator);
//			iterator = string_iterator.next(iterator);
//		}
//	}



//	dereferencing null pointer test
void	a070()
{
	int	*null_pointer = NULL;

	printf("null_pointer -> [%d] as %%d \n", *null_pointer);
}

#ifndef STRING
#define STRING "\a \n"
#endif

#define BUFFER_SIZE	5

void	a069()
{
	const char	*sentence = "hi there";
	printf("sentence -> [%s] as %%s \n", sentence);
	*(char *)sentence = 'a';	// bus error occur
	printf("sentence -> [%s] as %%s \n", sentence);
}

void	a068()
{
	pid_t	pid;
	int	stat_loc;

	pid = fork();
	if (pid == 0)
		exit(1);
	PRINT(pid, d);
	pid = wait(&stat_loc);
	PRINT(pid, d);
	PRINT((*(int *)&stat_loc >> 8) & 0x000000ff, d);
	pid = wait(&stat_loc);
	PRINT(pid, d);
	PRINT((*(int *)&stat_loc >> 8) & 0x000000ff, d);
	PRINT(errno, d);
	perror("errno");
}

void	*a067(void *_)
{
	(void)_;
	sleep(1000000);
	return (NULL);
}

void	a066()
{
	pthread_t	tid;
	int			count;
	int			ret;

	count = 0;
	while ((ret = pthread_create(&tid, NULL, a067, NULL)) == 0)
		++count;
	PRINT(count, d);
	PRINT(ret, d);
	PRINT(strerror(ret), s);
}

void	*a065(void *mutexes)
{
	sleep(1);
	while (1)
	{
		if (pthread_mutex_lock(mutexes) != 0)
			printf("Deadlock occured! \n");
	}
	return (NULL);
}

void	*a064(void *mutexes)
{
	int	ret;
	while (1)
	{
		ret = pthread_mutex_lock(mutexes);
		if (ret != 0)
			PRINT(ret, d);
		pthread_mutex_lock(mutexes + sizeof(pthread_mutex_t));
		printf("In the air lock of thread2 \n");
		pthread_mutex_unlock(mutexes + sizeof(pthread_mutex_t));
		pthread_mutex_unlock(mutexes);
	}
	return (NULL);
}

void	*a063(void *mutexes)
{
	while (1)
	{
		pthread_mutex_lock(mutexes);
		pthread_mutex_lock(mutexes + sizeof(pthread_mutex_t));
		printf("In the air lock of thread1 \n");
		pthread_mutex_unlock(mutexes);
		pthread_mutex_unlock(mutexes + sizeof(pthread_mutex_t));
	}
	return (NULL);
}

void	a062()
{
	pthread_t		thread1;
	pthread_t		thread2;
//	pthread_t		thread3;
	pthread_mutex_t	mutexes[2];

	pthread_mutex_init(&mutexes[0], NULL);
	pthread_mutex_init(&mutexes[1], NULL);
	if (pthread_create(&thread1, NULL, a063, mutexes) != 0)
		return ;
	if (pthread_create(&thread2, NULL, a064, mutexes) != 0)
		return ;
//	if (pthread_create(&thread3, NULL, a065, mutexes) != 0)
//		return ;
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
//	pthread_join(thread3, NULL);
}

void	a057(int signal);

void	a061(int signal)
{
	struct sigaction	sa;
	sa.sa_handler = a057;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		printf("Failed \n");
		return ;
	}
	while (1)
	{
		PRINT(signal, d);
		sleep(5);
	}
}

void	a057(int signal);

void	a060()
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					ret;

	sa1.sa_handler = a057;
	sa2.sa_handler = a061;
	sigemptyset(&sa1.sa_mask);
	sigaddset(&sa1.sa_mask, SIGUSR1);
	sigemptyset(&sa2.sa_mask);
	sigaddset(&sa2.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
		return ;
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
		return ;
	while (1)
	{
		ret = usleep(5000000);
		PRINT(ret, d);
	}
}

void	a059()
{
	PRINT(sizeof(long), lu);
	PRINT(sizeof(long int), lu);
	PRINT(sizeof(long long), lu);
	PRINT(sizeof(long long int), lu);
}

void	a058()
{
	struct timeval	time_value;
	struct timezone	time_zone;
	int				return_value;

	return_value = gettimeofday(&time_value, &time_zone);

	PRINT(return_value, d);
	PRINT(time_value.tv_sec, ld);
	PRINT(time_value.tv_usec, d);

	PRINT(return_value, d);
	PRINT(time_zone.tz_minuteswest, d);
	PRINT(time_zone.tz_dsttime, d);
}

void	a057(int signal)
{
	while (1)
	{
		PRINT(signal, d);
		sleep(5);
	}
}

void	a056()
{
	struct	sigaction	sa;
	int					result;

	sa.sa_handler = a057;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return ;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return ;

	result = sleep(1000);
	PRINT(result, d);
	result = sleep(1);
	PRINT(result, d);
}

typedef enum e_test000 {first, second, third} t_test000;

void	a055()
{
	int my_int;

	my_int = third;
	PRINT(my_int, d);
}

void	a054()
{
	int	a = -10;
	int b;

	while (a < 10)
	{
		PRINT(a, d);
		b = a % 4;
		PRINT(b, d);
		++a;
	}
}

void	a053()
{
	int	value;

	value = INT_MIN;
	PRINT(value, d);
	value = -value;
	PRINT(value, d);
	value = ~value + 1;
	PRINT(value, d);
}

void	a052()
{
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
}

void	a051()
{
	PRINT("a051", s);
}

void	a050()
{
	typedef void	(*t_function)(void);
	typedef void	t_function2(void);

	t_function	my_function = a051;
	t_function2	*p_my_function = a051;

	void	(*p_function)(void) = a051;

	my_function();
	p_my_function();
	p_function();
}

void	a049()
{
	int		number_of_bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*p_ch;

	while ((number_of_bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		PRINT(number_of_bytes_read, d);
		printf("[");
		p_ch = buffer;
		for (int i = 0; i < number_of_bytes_read; ++i)
			printf("%c", *p_ch++);
		printf("] \n");
	}
	PRINT(number_of_bytes_read, d);
	printf("[");
	p_ch = buffer;
	for (int i = 0; i < number_of_bytes_read; ++i)
		printf("%c", *p_ch++);
	printf("] \n");
//
//	number_of_bytes_read = read(0, buffer, BUFFER_SIZE);
//	PRINT(number_of_bytes_read, d);
//	printf("[");
//	p_ch = buffer;
//	for (int i = 0; i < number_of_bytes_read; ++i)
//		printf("%c", *p_ch++);
//	printf("] \n");
}

void	a048()
{
	int a = 12 % 11;
	int b = -1 % 11;
	int c = -12 % 11;

	PRINT(a, d);
	PRINT(b, d);
	PRINT(c, d);
}

void	a047()
{
	int i = INT_MAX;
	int j = INT_MAX;
	long l;

	PRINT(i * 10 > j, d);
	l = i * 10;
	PRINT(l > j, d);
	l = (long)i * 10;
	PRINT(l > j, d);
}

void	a046()
{
	PRINT(sizeof(void *), lu);
}

void	a045()
{
	float	f = 123456.78;
	PRINT(f, f);
	float	f2 = 123.45678;
	PRINT(f2, .10f);
}

void	a044()
{
	printf("[%x] \n", 0);
	printf("[%.x] \n", 0);
}

void	a043()
{
	printf("%-12345678901234567890d \n", 0);
	printf("%12345678901234567890d \n", 0);
	printf("%-1234567890123456789d \n", 0);
	printf("%1234567890123456789d \n", 0);
	printf("%d \n", 0);
	printf("%0d \n", 0);
	printf("%-1d \n", 0);
	printf("\n");

	printf("[%-12345678901234567890.d] \n", 0);
	printf("[%12345678901234567890.d] \n", 0);
	printf("[%-1234567890123456789.d] \n", 0);
	printf("[%1234567890123456789.d] \n", 0);
	printf("[%.d] \n", 0);
	printf("[%0.d] \n", 0);
	printf("[%-1.d] \n", 0);
}

void	a042()
{
	int		d = 12;
	char	*s = "hi";

	PRINT(d, 5.3d);
	PRINT(s, 5.3s);
	PRINT(d, 5.8d);
	PRINT(s, 5.8s);
}

void	a041()
{
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
	PRINT(sizeof(long long), lu);
	PRINT(sizeof(void *), lu);
}

void	a040()
{
	int		result;

	result = strcmp(NULL, "hi");    // segmentation fault
	printf("result: %d \n", result);
}

void	a039()
{
	char	*string;

	string = strdup(NULL);    // segmentation fault
	printf("string: %p \n", string);
}

void	a038()
{
	if ('\0' == '\x0')
		printf("'\\0' is equal to '\\x' \n");
}

// void	a037()
// {
// 	int	i;
// 	int	*n;
// 
// 	n = &i;
// 	printf("n [as %%n] -> [as %n] \n", n);
// 	printf("n [as %%n] -> [as %5n] \n", n);
// 	printf("n [as %%n] -> [as %.n] \n", n);
// 	printf("n [as %%n] -> [as %05n] \n", n);
// 	printf("n [as %%n] -> [as %-05n] \n", n);
// 	printf("n [as %%n] -> [as %-5n] \n", n);
// 	printf("n [as %%n] -> [as %.5n] \n", n);
// }

void	a036()
{
	int	i;
	int	*n;
	int	return_value;

	n = &i;
	return_value = printf("n [as %%n] -> [as %n] \n", n);
	printf("*n [as %%d] -> [%d] \n", *n);
	printf("return_value [as %%d] -> [%d] \n", return_value);
}

void	a035()
{
	int				i;
	unsigned int	u;

	i = -1;
	u = 1;
	printf("i as [%%o] -> [%o] \n", i);
	printf("u as [%%o] -> [%o] \n", u);
}

void	a034()
{
	int	i;
	int	return_value;

	i = 0;
	return_value = printf("%*i", INT_MAX -1, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
	return_value = printf("%*i", INT_MAX, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
	return_value = printf("%*i \n", INT_MAX -1, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
	return_value = printf("%*i \n", INT_MAX, i);
	dprintf(2, "return_value [as %%d] -> [%d] \n", return_value);
}

// void	a033()
// {
// 	char	c;
// 	int		a;
// 	int		i;
// 
// 	c = 10;
// 	printf("c as [%%-00-i] -> [%-00-i]", c);
// 	a = 12;
// 	i = 18;
// 	MPRIN("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i);
// }

void	a032()
{
	char	c;

	c = 0;
	while (c < 127)
	{
		printf("c as [%%d] -> [%d] \n", c);
		printf("c as [%%c] -> [%c] \n", c);
		printf("c as [%%.c] -> [%.c] \n", c);
		++c;
	}
}

void	a031()
{
	int	i;
	int	j;
	int k;

	printf("\ntest start \n");
	i = -1;
	while (i < 2)
	{
		printf("i: [%d] \n", i);
		printf("i [as %%d] -> [%d] \n", i);
		printf("i [as %%.d] -> [%.d] \n", i);
		printf("i [as %%.0d] -> [%.0d] \n", i);
		printf("i [as %%u] -> [%u] \n", i);
		printf("i [as %%.u] -> [%.u] \n", i);
		printf("i [as %%.0u] -> [%.0u] \n", i);
		printf("i [as %%x] -> [%x] \n", i);
		printf("i [as %%.x] -> [%.x] \n", i);
		printf("i [as %%.0x] -> [%.0x] \n", i);
		++i;
	}

	printf("\ntest  start \n");
	i = -1;
	while (i < 2)
	{
		j = -1;
		printf("i: [%d] \n", i);
		while (j < 2)
		{
			printf("j: [%d] \n", j);
			printf("j, i [as %%.*d] -> [%.*d] \n",j , i);
			printf("j, i [as %%.*u] -> [%.*u] \n",j , i);
			printf("j, i [as %%.*x] -> [%.*x] \n",j , i);
			++j;
		}
		++i;
	}

	printf("\ntest  start \n");
	k = -1;
	while (k < 2)
	{
		i = -1;
		while (i < 2)
		{
			j = -1;
			while (j < 2)
			{
				printf("k: [%d] \n", k);
				printf("i: [%d] \n", i);
				printf("j: [%d] \n", j);
				printf("k, j, i [as %%*.*d] -> [%*.*d] \n", k, j, i);
				printf("k, j, i [as %%*.*u] -> [%*.*u] \n", k, j, i);
				printf("k, j, i [as %%*.*x] -> [%*.*x] \n", k, j, i);
				++j;
			}
			++i;
		}
		++k;
	}
}

void	a030()
{
	printf("'a' [as %%.c] -> [%.c] \n", 'a');
	printf("\"a\" [as %%.s] -> [%.s] \n", "a");
	printf("(void *)1 [as %%.p] -> [%.p] \n", (void *)1);
	printf("[as %%.%%] -> [%.%] \n");
	printf("'a' [as %%.c] -> [%.c] \n", 'a');
	printf("\"a\" [as %%.0s] -> [%.0s] \n", "a");
	printf("(void *)1 [as %%.p] -> [%.p] \n", (void *)1);
	printf("[as %%.0%%] -> [%.0%] \n");
}

void	a029()
{
	printf("%d", -0);
}

void	a028()
{
	printf("[%-7.*s$] \n", -3, "yolo");
	printf("[%*.*s$] \n",-7,-3, "yolo");
}

// void	a027()
// {
// 	ft_printf("(void *)0 [as %%.p] -> [%.p] \n", (void *)0);
// 	ft_printf("(void *)0 [as %%5p] -> [%5p] \n", (void *)0);
// 	ft_printf("(void *)0 [as %%5.p] -> [%5.p] \n", (void *)0);
// 	printf("(void *)0 [as %%.p] -> [%.p] \n", (void *)0);
// 	printf("(void *)0 [as %%5p] -> [%5p] \n", (void *)0);
// 	printf("(void *)0 [as %%5.p] -> [%5.p] \n", (void *)0);
// }

// void	a026()
// {
// 	int i;
// 
// 	i = -1;
// 	ft_printf("i [as %%i] -> [%i] \n", i);
// 	ft_printf("i [as %%5i] -> [%5i] \n", i);
// 	ft_printf("i [as %%-5i] -> [%-5i] \n", i);
// 	ft_printf("i [as %%05i] -> [%05i] \n", i);
// 	ft_printf("i [as %%.5i] -> [%.5i] \n", i);
// 	ft_printf("i [as %%3.5i] -> [%3.5i] \n", i);
// 	ft_printf("i [as %%-3.5i] -> [%-3.5i] \n", i);
// 	ft_printf("i [as %%5.3i] -> [%5.3i] \n", i);
// 	ft_printf("i [as %%-5.3i] -> [%-5.3i] \n", i);
// 	ft_printf("i [as %%0.5i] -> [%0.5i] \n", i);
// 	ft_printf("i [as %%03.5i] -> [%03.5i] \n", i);
// 	ft_printf("i [as %%05.3i] -> [%05.3i] \n", i);
// 	ft_printf("i [as %%05.2i] -> [%05.2i] \n", i);
// 	ft_printf("i [as %%05.1i] -> [%05.1i] \n", i);
// 	ft_printf("i [as %%05.0i] -> [%05.0i] \n", i);
// 	ft_printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
// 	ft_printf("i [as %%05.i] -> [%05.i] \n", i);
// }

void	a025()
{
	int i;

	printf("ft_printf: \n");
// 	a026();
	putchar('\n');
	printf("printf: \n");
	i = -1;
	printf("i [as %%i] -> [%i] \n", i);
	printf("i [as %%5i] -> [%5i] \n", i);
	printf("i [as %%-5i] -> [%-5i] \n", i);
	printf("i [as %%05i] -> [%05i] \n", i);
	printf("i [as %%.5i] -> [%.5i] \n", i);
	printf("i [as %%3.5i] -> [%3.5i] \n", i);
	printf("i [as %%-3.5i] -> [%-3.5i] \n", i);
	printf("i [as %%5.3i] -> [%5.3i] \n", i);
	printf("i [as %%-5.3i] -> [%-5.3i] \n", i);
	printf("i [as %%0.5i] -> [%0.5i] \n", i);
	printf("i [as %%03.5i] -> [%03.5i] \n", i);
	printf("i [as %%05.3i] -> [%05.3i] \n", i);
	printf("i [as %%05.2i] -> [%05.2i] \n", i);
	printf("i [as %%05.1i] -> [%05.1i] \n", i);
	printf("i [as %%05.0i] -> [%05.0i] \n", i);
	printf("i [as %%05.*i] -> [%05.*i] \n", i, i);
	printf("i [as %%05.i] -> [%05.i] \n", i);
}

void	a024()
{
	printf("[as %%%%] -> [%%] \n");
	printf("[as %%5%%] -> [%5%] \n");
	printf("[as %%-5%%] -> [%-5%] \n");
	printf("[as %%05%%] -> [%05%] \n");
	printf("[as %%.5%%] -> [%.5%] \n");
	printf("[as %%3.5%%] -> [%3.5%] \n");
	printf("[as %%-3.5%%] -> [%-3.5%] \n");
	printf("[as %%5.3%%] -> [%5.3%] \n");
	printf("[as %%-5.3%%] -> [%-5.3%] \n");
}

void	a023()
{
	PRINT(sizeof(ssize_t), lu);
	PRINT(sizeof(size_t), lu);
	PRINT(sizeof(int), lu);
	PRINT(sizeof(long), lu);
}

void	a022()
{
	unsigned int x;

	x = 0x1;
	printf("x [as %%x] -> [%x] \n", x);
	printf("x [as %%5x] -> [%5x] \n", x);
	printf("x [as %%-5x] -> [%-5x] \n", x);
	printf("x [as %%05x] -> [%05x] \n", x);
	printf("x [as %%.5x] -> [%.5x] \n", x);
	printf("x [as %%3.5x] -> [%3.5x] \n", x);
	printf("x [as %%-3.5x] -> [%-3.5x] \n", x);
	printf("x [as %%5.3x] -> [%5.3x] \n", x);
	printf("x [as %%-5.3x] -> [%-5.3x] \n", x);
}

void	a021()
{
	unsigned int u;

	u = 1;
	printf("u [as %%u] -> [%u] \n", u);
	printf("u [as %%5u] -> [%5u] \n", u);
	printf("u [as %%-5u] -> [%-5u] \n", u);
	printf("u [as %%05u] -> [%05u] \n", u);
	printf("u [as %%.5u] -> [%.5u] \n", u);
	printf("u [as %%3.5u] -> [%3.5u] \n", u);
	printf("u [as %%-3.5u] -> [%-3.5u] \n", u);
	printf("u [as %%5.3u] -> [%5.3u] \n", u);
	printf("u [as %%-5.3u] -> [%-5.3u] \n", u);
	printf("u [as %%0.5u] -> [%0.5u] \n", u);
	printf("u [as %%03.5u] -> [%03.5u] \n", u);
	printf("u [as %%05.3u] -> [%05.3u] \n", u);
}

void	a020()
{
	int	i;
	int	*p;

	p = &i;
	printf("p [as %%p] -> [%p] \n", p);
	printf("p [as %%15p] -> [%15p] \n", p);
	printf("p [as %%-15p] -> [%-15p] \n", p);
//	printf("p [as %%015p] -> [%015p] \n", p);
//	printf("p [as %%.15p] -> [%.15p] \n", p);
//	printf("p [as %%15.20p] -> [%15.20p] \n", p);
//	printf("p [as %%-15.20p] -> [%-15.20p] \n", p);
//	printf("p [as %%20.15p] -> [%20.15p] \n", p);
//	printf("p [as %%-20.15p] -> [%-20.15p] \n", p);
}

void	a019()
{
	char	*s1;

	s1 = "s";
	printf("s1 [as %%s] -> [%s] \n", s1);
	printf("s1 [as %%5s] -> [%5s] \n", s1);
	printf("s1 [as %%-5s] -> [%-5s] \n", s1);
//	printf("s1 [as %%05s] -> [%05s] \n", s1);
	printf("s1 [as %%.5s] -> [%.5s] \n", s1);
	printf("s1 [as %%3.5s] -> [%3.5s] \n", s1);
	printf("s1 [as %%-3.5s] -> [%-3.5s] \n", s1);
	printf("s1 [as %%5.3s] -> [%5.3s] \n", s1);
	printf("s1 [as %%-5.3s] -> [%-5.3s] \n", s1);
}

void	a018()
{
	char c1;

	c1 = 'c';
	printf("c1 [as %%c] -> [%c] \n", c1);
	printf("c1 [as %%5c] -> [%5c] \n", c1);
//	printf("c1 [as %%05c] -> %05c \n", c1);
//	printf("c1 [as %%.5c] -> %.5c \n", c1);
//	printf("c1 [as %%3.5c] -> %3.5c \n", c1);
//	printf("c1 [as %%5.3c] -> %5.3c \n", c1);
	printf("c1 [as %%-5c] -> [%-5c] \n", c1);
//	printf("c1 [as %%-5.3c] -> %-5.3c \n", c1);
//	printf("c1 [as %%-3.5c] -> %-3.5c \n", c1);
}

void	a017()
{
	int		i1;
	int		i2;
	int		x3;
	int 	i4;
	double	d5;
	int		i6;

	i1 = 20;
	i2 = 30;
	x3 = 0x10;
	i4 = 2;
	d5 = 12.34567;
	i6 = -x3;
	PRINT(i1, d);
	PRINT(i2, d);
	PRINT(x3, i);
	PRINT(i4, d);
	PRINT(d5, f);
	PRINT(i6, d);
	printf("start: [%d, %d, %n] \n", i1, i2, &x3);
	printf("second: [%1$d, %2$d, %3$d, %3$d, %2$d, %1$d] \n", i1, i2, x3);
//	printf("(unsigned int) &i1 [as %%#x] -> [%#x] \n", (unsigned int) &i1);
//	printf("(unsigned int) &i1 [as %%x] -> [%x] \n", (unsigned int) &i1);
	printf("i1, &i2 [as %%*p] -> [%*p] \n", i1, &i2);
	printf("i1, &i2 [as %%2$*1$p] -> [%2$*1$p] \n", i1, &i2);
	printf("&i2, i1 [as %%1$*2$p] -> [%1$*2$p] \n", &i2, i1);
	printf("x3, i4, d5 [as %%3$*1$.*2$f] -> [%3$*1$.*2$f] \n", x3, i4, d5);
	printf("x3, i4, d5 [as %%*.*f] -> [%*.*f] \n", x3, i4, d5);
	printf("x3, i4, d5 [as %%-*.*f] -> [%-*.*f] \n", x3, i4, d5);
	printf("i6, i4, d5 [as %%*.*f] -> [%*.*f] \n", i6, i4, d5);
	printf("i6, i4, d5 [as %%-*.*f] -> [%-*.*f] \n", i6, i4, d5);
	printf("i6, i4, d5 [as %%--*.*f] -> [%--*.*f] \n", i6, i4, d5);
	printf("i6, i4, d5 [as %%0000*.*f] -> [%0000*.*f] \n", i6, i4, d5);
	printf("i4, d5 [as %%*f] -> [%*f] \n", i4, d5);
	printf("i4, d5 [as %%*.f] -> [%*.f] \n", i4, d5);
	printf("i4, i6, d5 [as %%*.*f] -> [%*.*f] \n", i4, i6, d5);
	printf("i1 [as %%.3d] -> [%.3d] \n", i1);
	printf("d5 [as %%a] -> [%a] \n", d5);
	printf("d5 [as %%A] -> [%A] \n", d5);
	PRINT(i1, 4d);
	PRINT(i1, -4d);
	PRINT(i1, 04d);
	PRINT(i1, 3.4d);
	PRINT(i1, .4d);
	PRINT(i1, 03.4d);
	PRINT(i1, 0.4d);
//	printf("100, i1 [as %%0*d] -> [%0*d] \n", 100, i1);
	printf("\"\" [as %%-*s] -> [%-*s] \n", 0, "");
	printf("-5, i4 [as %%.*d] -> [%.*d] \n", -5, i4);
	printf("5, i4 [as %%.*d] -> [%.*d] \n", 5, i4);
	printf("i4 [as %%.5d] -> [%.5d] \n", i4);
	printf("i4 [as %%10.5d] -> [%10.5d] \n", i4);
	printf("i4 [as %%010.5d] -> [%010.5d] \n", i4);
	printf("i4 [as %%010d] -> [%010d] \n", i4);
	printf("i4 [as %%5.10d] -> [%5.10d] \n", i4);
	printf("i4 [as %%-10.5d] -> [%-10.5d] \n", i4);
	printf("\"a\" [as %%10.5s] -> [%10.5s] \n", "a");
//	printf("\"a\" [as %%#10.5s] -> [%#10.5s] \n", "a");
}

void	a016()
{
	const char	*str = STRING;
	
	printf(STRING);
	PRINT(*str, x);
	PRINT(*(str + 1), x);
}

void	a015()
{
	int				d;
	unsigned char	*c;

	d = 0x12345678;
	c = (unsigned char *)&d;
	for (int i = 0; i < 4; ++i)
	{
		PRINT(*c, x);
		++c;
	}
}

void	a014()
{
	PRINT(sizeof(size_t), lu);
	PRINT(sizeof(ssize_t), lu);
}

int		ft_wordcount(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c || i == 0) && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

void	a013()
{
	int count = ft_wordcount("a", 'c');

	PRINT(count, d);
}

/*
static int  word_count(char const *str, char c)
{
    int count;

    if (!str)
        return (0);
    if (!c)
        return (*str ? 1 : 0); 
    count = (*str == c ? -1 : 0); 
    while (*str)
    {   
        ++count;
        while (*str != c)
            ++str;
        while (*str == c)
            ++str;
    }   
    return (count);
}

void	a012()
{
	char	**result;
	int		count = word_count("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');

	PRINT(count, d);
	putchar('\n');

	result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	PRINT(result, p);
	if (result)
	{
		while (*result)
		{
			PRINT(*result, p);
			PRINT(*result++, s);
		}
		PRINT(*result, p);
	}
}

void	a011()
{
	char	s[1] = {0};
	char	**result = ft_split(s, 65);
	if (result)
	{
		PRINT(result, p);
		PRINT(*result, p);
	}
	else
		printf("result is empty \n");
}
*/

void	a010()
{
	PRINT('\t', d);
	PRINT('\n', d);
	PRINT('\v', d);
	PRINT('\f', d);
	PRINT('\r', d);
	printf("\' \': %d \n", ' ');
}

void	a009(void (*f)(void))
{
	if (f)
		printf("f is not NULL \n");
	else
		printf("f is NULL \n");
	f();
}

void	a008(void)
{
	a009(NULL);
}

size_t	a007(void)
{
	return (5);
}

void	a006(void)
{
	int i = 2;
	int j = 3;
	int k[i + j];
	int l = 4;
	int m[a007()];

	PRINT(&i, p);
	PRINT(&j, p);
	PRINT(k, p);
	PRINT(&l, p);
	PRINT(m, p);
	PRINT(sizeof(k), lu);
	PRINT(sizeof(m), lu);
}

void	a005(void)
{
	char	string[10];

	PRINT(string, p);
	PRINT(1 + string, p);
}

void	a004(void)
{
	int	test;

	test = -15 % 10;
	PRINT(test, d);
}

void	a003(void)
{
	char	*p_c;

	p_c = malloc(4000000000000000000);
	PRINT(p_c, p);
	PRINT(errno, d);
}

void	a002(void)
{
	char	*p_c;

	p_c = calloc(2, 1);
	free(p_c);
	free(p_c + 1);
}

void	a001(void)
{
	char	c0;
	char	array[1];
	char	c1;

	PRINT(&c0, p);
	PRINT(array, p);
	PRINT(&c1, p);
	PRINT(c0, d);
	PRINT(*array, d);
	PRINT(c1, d);
}

void	a000(void)
{
	if (1) // (1, 0)
		PRINT(1, d);
	else
		PRINT(0, d);
}

int main(void)
{
	return (EXECUTE());
}
