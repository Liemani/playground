#include <stdio.h>	// printf()
#include <stdlib.h>	// atoi()
#include <sys/time.h>	// struct timeval

#define SEC_IN_USEC	1000000

void	timeval_divide(const struct timeval *time,
		int divisor, struct timeval *result)
{
	result->tv_sec = time->tv_sec / divisor;
	result->tv_usec = (time->tv_sec % divisor * SEC_IN_USEC + time->tv_usec)
		/ divisor;
	if (result->tv_usec < 0)
	{
		--result->tv_sec;
		result->tv_usec += SEC_IN_USEC;
	}
}

int	main(int argc, char **argv)
{
	struct timeval	time_curr;
	int				divisor;
	struct timeval	time_divided;

	if (argc != 4)
	{
		printf("usage: %s <time_sec> <time_usec> <divisor> \n", argv[0]);
		return (0);
	}

	time_curr.tv_sec = atoi(argv[1]);
	time_curr.tv_usec = atoi(argv[2]);
	divisor = atoi(argv[3]);
	timeval_divide(&time_curr, divisor, &time_divided);
	printf("timeval: %ld %d \n", time_curr.tv_sec, time_curr.tv_usec);
	printf("divisor: %d \n", divisor);
	printf("time_divided: %ld %d \n", time_divided.tv_sec, time_divided.tv_usec);
	return (0);
}
