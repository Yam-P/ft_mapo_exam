#include <unistd.h>

int	word_len_check(char *str1, char *str2)
{
	// 2. 두 매개변수 모두 두번째 인덱스가 '\0'이면
	//	  한글자라는 의미이므로 return 1
	// 	  이를 만족하지 않으면 while문에 들어가지 않음.
	if (str1[1] == '\0' || str2[1] == '\0')
		return (1);
	return (0);	
}

int main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	// 1. 매개변수가 3개이므로 argc는 4일때만 수행
	while (argc == 4 && argv[1][idx] != '\0' 
			&& word_len_check(argv[2], argv[3]))
	{
		// 3. 첫 번째 매개변수 모든 글자를 방문하되,
		// 	  두 번째 매개변수의 첫 번째 글자와 같으면
		//	  세 번째 매개변수의 첫 번째 글자와 바꾸기 
		if (argv[1][idx] == argv[2][0])
			write(1, &argv[3][0], 1);
		// 4. 위 조건이 아니라면, 그냥 지금 인덱스 값 출력
		else
			write(1, &argv[1][idx], 1);
		++idx;
	}

	write(1, "\n", 1);
	return (0);
}
