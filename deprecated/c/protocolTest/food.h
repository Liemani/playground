#ifndef FOOD_H
#define FOOD_H

#include "object.h"



typedef struct	s_food
{
	void		*ingredient;
}				t_food;

t_Class	*Food;

t_food	*newFood(void *ingredient);
void	freeFood(t_food *food);
void	descriptionFood(t_food *food);



#endif
