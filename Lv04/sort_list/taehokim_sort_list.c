#include <unistd.h>
#include <stdio.h>


typedef struct    s_list
{
	struct s_list	*next;
	int				data;
}                 t_list;

int ascending(int a, int b)
{
	return (a <= b);
}

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list*	found;
	t_list*	first;
	t_list*	temp_next;
	t_list* smallest_node;
	int temp;

	// 시작지점을 기억해두기.
	first = lst;

	// 예외처리.
	if (!lst || !cmp)
		return (0);

	// 처음부터 끝까지 순회한다. (while 문 내부 최하단 lst = lst->next와 함께 쓰임.)
	while (lst)
	{
		// 최솟값을 찾기 위한 작은 지점을 설정해둔다.
		smallest_node = lst;

		// 현재 위치(lst)로부터 끝까지 순회한다. (while문 내부 아래쪽 found = found->next와 함께 쓰임.)
		found = lst;
		while (found)
		{
			// 만약 smallest_node->data가 더 작다면 (순서에 알맞다면)
			if (cmp(smallest_node->data, found->data) == 0)
				// 최솟값을 갱신.
				smallest_node = found;

			found = found->next;
		}
		printf("found smallist:%d\n", smallest_node->data);
		// 이 시점에서는 lst(현재 위치)에서부터 끝까지 순회하며 가장 작은 값을 가진 노드 검색 완료.
		// 그 노드의 값을 현재 위치의 값과 교환.
		temp = smallest_node->data;
		smallest_node->data = lst->data;
		lst->data = temp;

		//다음 루프로.
		lst = lst->next;
	}

	// 시작지점을 다시 반환.
	return (first);
}

int main(void)
{
	t_list s[5];
	t_list *p;

	s[0].data = 4;
	s[1].data = 1;
	s[2].data = 6;
	s[3].data = 3;
	s[4].data = 2;

	s[0].next = &s[1];
	s[1].next = &s[2];
	s[2].next = &s[3];
	s[3].next = &s[4];
	s[4].next = 0;

	p = sort_list(s, ascending);
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
