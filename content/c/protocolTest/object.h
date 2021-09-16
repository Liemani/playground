#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#define lmtMalloc(argument) _lmtMalloc((void **)&argument, sizeof(*argument))



typedef void	(*generic)(void *);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_Class
{
	void			(*free)(void *instance);
	void			(*description)(void *instance);
	struct s_list	*listInstance;
}					t_Class;

t_list			*classTable;

void	_lmtMalloc(void **argument, size_t size);

t_list	*newList();
int		addElement(t_list *list, void *content);
void	removeElement(t_list *list, void *content);

t_Class	*newClass();

void	newClassTable();
void	addClass(t_Class *class);
t_Class	*classOf(void *instance);



#endif
