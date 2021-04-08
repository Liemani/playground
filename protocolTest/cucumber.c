#include <stdio.h>
#include <stdlib.h>
#include "cucumber.h"
#include "object.h"



static void	setCucumber()
{
	if (Cucumber == NULL)
	{
		Cucumber = newClass();
		Cucumber->description = (generic)descriptionCucumber;
		addClass(Cucumber);
	}
}

t_cucumber	*newCucumber(int count)
{
	setCucumber();
	t_cucumber	*cucumber;

	lmtMalloc(cucumber);
	cucumber->count = count;
	addElement(Cucumber->listInstance, cucumber);

	return (cucumber);
}

void	descriptionCucumber(t_cucumber *cucumber)
{
	printf("%d cucumbers", (cucumber)->count);
}
