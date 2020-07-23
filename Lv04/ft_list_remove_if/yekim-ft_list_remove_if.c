#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	// 들어온 리스트의 선두 부분이 data의 값을 갖는다면 모두 잘라내기
	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		printf("free in func: %p\n", begin_list);
		free(tmp);
	}
	printf("DEBUG============================================\n");
	// 앞부분에서 data_ref와 같아서 잘라진 부분 이후로는 리스트의
	// 가운데 값을 갱신해야하므로 이전 값과 같이 봐야함
	prev = *begin_list;
	// 다음 값이 NULL일 때 진행하면 seg fault
	while (prev && prev->next)
	{
		next = prev->next;
		if (cmp(next->data, data_ref))
		{
			tmp = next;
			prev->next = next->next;
			printf("free in func: %p\n", tmp);
			free(tmp);	
		}
		else
			prev = next;
	}
	return ;
}
