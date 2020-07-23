#if 1
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*beg;
	t_list	*cur;
	int			

	beg = lst;
	cur = lst;
	while (cur->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			
		}
		cur = cur->next;	
	}
}
#endif 

#if 0
#include "list.h"
#include <unistd.h>

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		overflow;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			overflow = lst->data;
			lst->data = lst->next->data;
			lst->next->data = overflow;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
#endif
