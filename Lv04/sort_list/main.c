#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*gen_struct(t_list *next, int data)
{
	t_list	*st;
	
	st = (t_list *)malloc(sizeof(t_list));
	st->next = next;
	st->data = data;
	printf("addr: %p, data: %d\n", st, st->data);
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
//	t_list	*tmp;

	e = gen_struct(NULL, 1);
	d = gen_struct(e, 2);
	c = gen_struct(d, 3);
	b = gen_struct(c, 4);
	a = gen_struct(b, 5);

	printf("before sort==================\n");
	pos = a;
	while (pos)
	{
		printf("addr: %p, data: %d\n", pos, pos->data);
		pos = pos->next;
	}
	pos = sort_list(a, ascending);

	printf("after sort===================\n");
	while (pos)
	{
		//tmp = pos;
		printf("data: %d\n", pos->data);
		pos = pos->next;
		//printf("free addr: %p\n", tmp);
	//	free(tmp);
	}
	return (0);
}
