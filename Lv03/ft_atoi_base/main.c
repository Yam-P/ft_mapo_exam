#include <stdio.h>

extern	int	ft_atoi_base(const char *str, int str_base);

int main(void)
{
	printf("12fdb3->%d\n", ft_atoi_base("12fdb3", 16));
	printf("12FDB3->%d\n", ft_atoi_base("12FDB3", 16));
	printf("-10010->%d\n", ft_atoi_base("-10010", 2));

	return (0);
}
