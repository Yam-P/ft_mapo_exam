#include "ft_list.h"

int	g_cnt;

void	count_list(t_list *begin_list)
{
	if (begin_list)
		return ;
		
	++g_cnt;
	count_list(begin_list->next);
}

int	ft_list_size(t_list *begin_list)
{
	g_cnt = 0;
	
	count_list(begin_list);
	return (g_cnt);
}
