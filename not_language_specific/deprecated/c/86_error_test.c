#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "lmt.h"

int main(void)
{
	perror("hi"); // hi: Undefined error: 0

	char *const message = strerror(0);
	PRINT(message, s); // message [as %s] -> [Undefined error: 0]

	return (0);
}
