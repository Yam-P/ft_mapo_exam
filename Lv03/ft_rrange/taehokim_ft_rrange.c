// 문제요약: start 부터 end 까지 차례로 1씩 int가 들어있는 배열을 만들기.
// start가 end보다 크다면 거꾸로 작아져야 함.
// 예: ft_range(1, 3) >> [1, 2, 3]
// 예: ft_range(4, 2) >> [4, 3, 2]

#include <stdio.h>
#include <stdlib.h>

// 만들어야 하는 함수.
int		*ft_rrange(int start, int end)
{
	// 생성해야 하는 배열(리턴값)
	int		*range;

	// 값을 넣어줄 때 쓸 인덱스 변수
	int		i;

	// 계속 변화시켜주어야 하는 값을 의미함. 1이라면 1씩 증가, -1이라면 1씩 감소.
	int		step;

	// 실제로 넣어줄 값을 의미함. start부터 출발함.
	int		value_to_push;

	// start와 end의 자리를 바꿈.
	i = start;
	start = end;
	end = i;

	// step과 range의 초기 세팅
	if (start > end)
	{
		step = -1;
		range = (int *)malloc(sizeof(int) * (start - end) + 1);
	}
	else
	{
		step = 1;
		range = (int *)malloc(sizeof(int) * (end - start) + 1);
	}

	// 순회하면서 range에 값을 넣어줌.
	i = 0;
	value_to_push = start;
	while (value_to_push != end)
	{
		range[i] = value_to_push;
		value_to_push += step;
		i++;
	}

	// range 마무리
	range[i] = value_to_push;
	return (range);
}

void test_print_int_array(int* array, int len)
{
	for(int i = 0; i<len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void)
{
	test_print_int_array(ft_rrange(2, 5), 4);
	test_print_int_array(ft_rrange(-2, 2), 5);
	test_print_int_array(ft_rrange(4, -2), 7);
	test_print_int_array(ft_rrange(5, 1), 5);
}
