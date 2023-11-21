#include "lmt.h"

#define hello	1
#define hello	2
//-Wmacro-redefined

int	main(void)
{
	PRINT(hello, d);  // 2
	return (0);
}
