#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*gen_struct(t_list *next, int data)
{
	t_list	*st;
	
	st = (t_list *)malloc(sizeof(t_list));
	printf("addr: %p\n", st);
	st->next = next;
	st->data = data;
	return (st);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;
	t_list	*e;
	t_list	*pos;
	t_list	*tmp;

	int	a_data = 5;
	int	b_data = 4;
	int	c_data = 3;
	int	d_data = 2;
	int	e_data = 1;

	e = gen_struct(NULL, e_data);
	d = gen_struct(e, d_data);
	c = gen_struct(d, c_data);
	b = gen_struct(c, b_data);
	a = gen_struct(b, a_data);

	t_list	*res = sort_list(a, ascending);

	pos = res;
	while (pos)
	{
		tmp = pos;
		pos = pos->next;
		printf("data: %d\n", pos->data);
		printf("free addr: %p\n", tmp);
		free(tmp);
	}
	return (0);
}
