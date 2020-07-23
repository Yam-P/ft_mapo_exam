#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str);

int	main(void)
{
	char **split = ft_split("abcd efg hij, 421	52");
	for (int i = 0; i < 5; ++i)
	{
		printf("split[%d]: %s\n", i, split[i]);
	} 
	for (int i = 0; i < 5; ++i)
	{
		free(split[i]);
	}
	free(split);
	return (0);
}
