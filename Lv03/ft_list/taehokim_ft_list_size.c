#include <stdio.h>


/*
* 만들어야 하는 파일 ft_list.h
*/
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

/*
* 만들어야 하는 파일 : ft_list_size.c
* 본 문제에 제출해야 하는 함수
*/
int	ft_list_size(t_list *begin_list){
	t_list	*finding;
	int		count;

	count = 0;
	finding = begin_list;
	while (finding)
	{
		count ++;
		finding = finding->next;
	}
	return (count);
}

/*
*	int main(void)
*	테스트용 main 함수
*/
int main(void)
{
	t_list t1;
	t_list t2;
	t_list t3;
	t_list t4;
	t1.data = "hi";
	t2.data = "ho";
	t3.data = "man";
	t4.data = "god";
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	printf("count: %d\n", ft_list_size(&t1));
}
