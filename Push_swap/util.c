#include <stdlib.h>
#include "util.h"

void	*lmt_alloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		exit(ALLOCATION_ERROR);
	return (result);
}
