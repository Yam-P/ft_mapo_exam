#include <stdio.h>

extern	unsigned char	reverse_bits(unsigned char octet);

int main(void)
{
	printf("res: %d\n", reverse_bits(65));
	return (0);
}
