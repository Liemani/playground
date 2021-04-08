#ifndef CUCUMBER_H
#define CUCUMBER_H

#include "object.h"



typedef struct	s_cucumber
{
	int			count;
}				t_cucumber;

t_Class	*Cucumber;

t_cucumber	*newCucumber(int count);
void		descriptionCucumber(t_cucumber *cucumber);



#endif
