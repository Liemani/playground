#include <stdio.h>
#include <stdlib.h>
#include "food.h"
#include "object.h"



static void	setFood()
{
	if (Food == NULL)
	{
		Food = newClass();
		Food->free = (generic)freeFood;
		Food->description = (generic)descriptionFood;
		addClass(Food);
	}
}

t_food	*newFood(void *ingredient)
{
	setFood();
	t_food	*food;

	lmtMalloc(food);
	food->ingredient = ingredient;
	addElement(Food->listInstance, food);

	return (food);
}

void	freeFood(t_food *food)
{
	t_Class	*classIngredient;

	classIngredient = classOf(food->ingredient);
	classOf(food->ingredient)->free(food->ingredient);
	free(food);
}

void	descriptionFood(t_food *food)
{
	printf("This food is made of ");
	classOf(food->ingredient)->description(food->ingredient);
}
