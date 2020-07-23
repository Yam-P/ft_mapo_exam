#include <stdlib.h>
#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b);

int	main(int argc, char **argv)
{
	(void)argc;
	printf("result: %d\n", lcm(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
