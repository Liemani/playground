#include <stdio.h>	// printf()
#include <stddef.h>	// NULL
#include <sys/time.h>	// struct time

#ifndef EXECUTION
# define EXECUTION	a005
#endif



// What about pointer type? and struct type?
typedef struct
{
	char	char1;
	int		int1;
}	t_a0051;

typedef struct s_a0050
{
	struct s_a0050	*a0050;
	t_a0051			a0051;
}	t_a0050;

void	a005(void)
{
//		const t_a0050	var = {NULL, '0', 1};	// error: suggest braces around initialization of subobject
//		t_a0050	var = {&var, {'0', 1}};
//		const t_a0050	var = {0};
	const t_a0050	var = {NULL, {'0', 1}};

	printf("a0050 -> [%p], char1 -> [%d], int1 -> [%d] \n", var.a0050, var.a0051.char1, var.a0051.int1);
	printf("sizeof(t_a0050) -> [%zu] \n", sizeof(t_a0050));
}

// Now test custom struct with members of variety type
// struct memory fill empty to align 8 byte
//  sizeof(int1) + sizeof(int2) = 8
//  sizeof(int3) + empty = 8
//  sizeof(long1) = 8
//  8 bytes of char1 = 8
//  8 bytes of char1 = 8
//  1 byte of char1 + 7 empty bytes = 8
//  total 48 bytes
typedef struct
{
	int		int1;
	int		int2;
	int		int3;
	long	long1;
	char	char1[17];
}	t_a004;

void	a004(void)
{
//		const t_a004	custom = {0};	// Initialize all allocated memory to 0
//		const t_a004	custom = {1, 2, 3, 4, 'a', 'b'};	// error: suggest braces around initialization of subobject
	const t_a004	custom = {1, 2, 3, 4, {'a', 'b'}};

	printf("int1 -> [%d], int2 -> [%d], int3 -> [%d], long1 -> [%ld] \n", custom.int1, custom.int2, custom.int3, custom.long1);
	printf("char1 -> [%s] \n", custom.char1);
	printf("sizeof(t_a004) -> [%zu] \n", sizeof(t_a004));
	printf("&int1  -> [%p] \n", &custom.int1);
	printf("&int2  -> [%p] \n", &custom.int2);
	printf("&int3  -> [%p] \n", &custom.int3);
	printf("&long1 -> [%p] \n", &custom.long1);
	printf("&char1 -> [%p] \n", &custom.char1);
}

// What about initializing more argument than expect?
//	void	a003(void)
//	{
//		const struct timeval	time = {-1, 2, -3};	// error: excess elements in struct initializer
//	
//		printf("tv_sec -> [%ld], tv_usec -> [%d]\n", time.tv_sec, time.tv_usec);
//	}

// What about initializing unmatching values?
//	void	a002(void)
//	{
//		const struct timeval	time = {-1};	// error: missing field 'tv_usec' initializer
//	
//		printf("tv_sec -> [%ld], tv_usec -> [%d]\n", time.tv_sec, time.tv_usec);
//	}

// Second, print the value of time which is initialized when declared
void	a001(void)
{
	const struct timeval	time = {-1, 2};

	printf("tv_sec -> [%ld], tv_usec -> [%d]\n", time.tv_sec, time.tv_usec);
	printf("sizeof(struct timeval) -> [%zu] \n", sizeof(struct timeval));	// 16
}

// First, just print the value of 'struct timeval'
void	a000(void)
{
	struct timeval	time;

	time.tv_sec = -1;
	time.tv_usec = 2;
	printf("tv_sec -> [%ld], tv_usec -> [%d]\n", time.tv_sec, time.tv_usec);
	printf("sizeof(struct timeval) -> [%zu] \n", sizeof(struct timeval));	// 16
}

int	main(void)
{
	EXECUTION();
	return (0);
}
