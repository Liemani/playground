#ifndef CARROT_H
#define CARROT_H

#include "object.h"



typedef struct	s_carrot
{
	int			weight;
}				t_carrot;

t_Class	*Carrot;

t_carrot	*newCarrot(int weight);
void		descriptionCarrot(t_carrot *carrot);



#endif
