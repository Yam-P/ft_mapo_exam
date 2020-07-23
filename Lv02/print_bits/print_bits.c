#include <unistd.h>

// 비트 마스크 공부하기
void	print_bits(unsigned char octet)
{
	int		idx;
	char	bit;

	idx = 8;
	// 가장 높은 비트부터 출력돼야하므로 8부터 인덱스 주기
	while (idx--)
	{
		// 시프트 연산하며 idx번째 비트를 확인
		bit = ((octet >> idx) & 1) + '0';
		write(1, &bit, 1);
	}
}
