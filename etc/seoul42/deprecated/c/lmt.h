#ifndef LMT_H
# define LMT_H

#include <stdio.h>

#define PRINT(identifier, format_specifier) \
	printf(#identifier "\t-> [%" #format_specifier "] as %%" #format_specifier " \n", identifier)

#endif
