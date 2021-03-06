#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*gen_struct(t_list *next, int *data)
{
	t_list	*st;
	
	st = (t_list *)malloc(sizeof(t_list));
	printf("addr: %p\n", st);
	st->next = next;
	st->data = data;
	return (st);
}

int cmp(void *data1, void *data2)
{
	printf("cmp %d with %d\n", *(int *)data1, *(int *)data2);	
	if (*(int *)data1 == *(int *)data2)
		return (0);
	return (1);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*pos;
	t_list	*tmp;
	void	*cmp_data;

	int	a_data = 3;
	int	b_data = 4;
	int	c_data = 5;

	c = gen_struct(NULL, &c_data);
	b = gen_struct(c, &b_data);
	a = gen_struct(b, &a_data);

	cmp_data = &b_data;
	ft_list_remove_if(&a, cmp_data, cmp);

	pos = a;
	while (pos)
	{
		tmp = pos;
		pos = pos->next;
		printf("free addr: %p\n", tmp);
		free(tmp);
	}
	return (0);
}
