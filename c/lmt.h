#ifndef LMT_H
# define LMT_H

#include <stdio.h>

#define PRINT(identifier, format_specifier) \
	printf(#identifier " [as %%" #format_specifier "] -> [%" #format_specifier "] \n", identifier)

#endif
