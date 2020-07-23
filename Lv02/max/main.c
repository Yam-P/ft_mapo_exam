#include <stdio.h>

extern	int	max(int *tab, unsigned int len);

int main(void)
{
	int num[8] = {1, 2, 3, 4, 6, 2, 3, 5};

	printf("res: %d\n", max(num, 8));
	return(0);
}
