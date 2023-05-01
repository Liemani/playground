#include "object.h"

#include <stdio.h>
#include <stdlib.h>




void	_lmtMalloc(void **argument, size_t size)
{
	*argument = malloc(size);
	if (*argument == NULL)
	{
		printf("malloc error \n");
		exit(-1);
	}
}

t_list	*newList()
{
	t_list	*list;

	lmtMalloc(list);
	list->next = NULL;

	return (list);
}

int     addElement(t_list *list, void *content)
{
	t_list  *element;

	lmtMalloc(element);
	element->content = content;
	element->next = list->next;
	list->next = element;

    return (0);
}

void	removeElement(t_list *list, void *content)
{
	t_list	*elementPrevious;
	t_list	*elementCurrent;

	elementPrevious = list;
	while ((elementCurrent = elementPrevious->next))
	{
		if (elementCurrent->content == content)
		{
			elementPrevious->next = elementCurrent->next;
			classOf(elementCurrent->content)->free(elementCurrent->content);
			free(elementCurrent);
		}

		elementPrevious = elementCurrent;
	}
}

t_Class	*newClass()
{
	t_Class	*class;

	lmtMalloc(class);
	class->free = free;
	class->listInstance = newList();

	return (class);
}

static void	descriptionNull(void *null)
{
	printf("NULL");
}

void	newClassTable()
{
	t_list	*list;
	t_Class	*classNull;

	list = newList();
	addElement(list, NULL);

	lmtMalloc(classTable);
	classTable->next = NULL;

	classNull = newClass();
	classNull->description = descriptionNull;
	classNull->listInstance = list;
}

void	addClass(t_Class *class)
{
	if (classTable == NULL)
	{
		newClassTable();
	}
	t_list	*element;

	element = newList();
	element->content = class;
	element->next = classTable->next;
	classTable->next = element;
}

t_Class	*classOf(void *instance)
{
	t_list	*classElement;
	t_list	*instanceElement;

	classElement = classTable;
	while ((classElement = classElement->next))
	{
		const t_Class	*class = classElement->content;
		instanceElement = class->listInstance;
		while ((instanceElement = instanceElement->next))
		{
			if (instanceElement->content == instance)
				return (classElement->content);
		}
	}

	return (NULL);
}
