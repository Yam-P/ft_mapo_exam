#include <stdio.h>

int hcf(int a, int b)
{
	int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int result;

	if (a > b)
		result = hcf(a, b);
	else
		result = hcf(b, a);
	return ((a * b) / result);
}

int main()
{
	printf("%d\n", lcm(90,30));
}
