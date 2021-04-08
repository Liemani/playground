#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "object.h"
#include "food.h"
#include "carrot.h"
#include "cucumber.h"



int	main()
{
	t_carrot	*carrot = newCarrot(10);
	t_cucumber	*cucumber = newCucumber(2);

	t_food		*carrotFood = newFood(carrot);
	t_food		*cucumberFood = newFood(cucumber);

	classOf(carrot)->description(carrot);
	putchar('\n');
	classOf(carrotFood)->description(carrotFood);
	putchar('\n');
	putchar('\n');
	classOf(cucumber)->description(cucumber);
	putchar('\n');
	classOf(cucumberFood)->description(cucumberFood);
	putchar('\n');

	freeFood(carrotFood);
	freeFood(cucumberFood);

	return (0);
}
