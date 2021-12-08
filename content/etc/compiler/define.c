// define 이든지 enum 안에 정의된 constant 든지, constant 를 정의하기 전에 사용하면 compile step 에서 undeclared identifier error 가 발생하면서 진행되지 않는다.
#include <stdio.h>

#define TEST000	1

enum
{
	TEST001 = TEST000
};

int	main(void)
{
	printf("TEST001: [%d] \n", TEST001);
	return (0);
}
