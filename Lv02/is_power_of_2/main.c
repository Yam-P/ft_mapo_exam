#include <stdio.h>

extern	int	is_power_of_2(unsigned int n);

int	main(void)
{
	printf("4?: %d\n", is_power_of_2(4));
	printf("25?: %d\n", is_power_of_2(25));
	printf("361?: %d\n", is_power_of_2(361));
	printf("256?: %d\n", is_power_of_2(256));
	printf("1024?: %d\n", is_power_of_2(1024));
	return 0;
}
