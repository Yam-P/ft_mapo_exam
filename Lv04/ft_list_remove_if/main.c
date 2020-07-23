#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list	*gen_struct(t_list *next, int *data)
{
	t_list	*st;
	
	st = (t_list *)malloc(sizeof(t_list));
	printf("addr: %p\n", st);
	st->next = next;
	st->data = data;
	return (st);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*pos;

	int	a_data = 3;
	int	b_data = 4;
	int	c_data = 5;

	c = gen_struct(NULL, &c_data);
	b = gen_struct(c, &b_data);
	a = gen_struct(b, &a_data);

	pos = a;
	while (pos)
	{
		pos = pos->next;
	}
	free(a);
	free(b);
	free(c);
	//free(a);
	return (0);
}
