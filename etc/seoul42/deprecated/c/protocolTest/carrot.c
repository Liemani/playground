#include <stdio.h>
#include <stdlib.h>
#include "carrot.h"
#include "object.h"



static void	setCarrot()
{
	if (Carrot == NULL)
	{
		Carrot = newClass();
		Carrot->description = (generic)descriptionCarrot;
		addClass(Carrot);
	}
}

t_carrot	*newCarrot(int weight)
{
	setCarrot();
	t_carrot	*carrot;

	lmtMalloc(carrot);
	carrot->weight = weight;
	addElement(Carrot->listInstance, carrot);

	return (carrot);
}

void	descriptionCarrot(t_carrot *carrot)
{
	printf("%d grams of carrot", (carrot)->weight);
}
