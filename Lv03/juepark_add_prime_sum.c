#include <unistd.h>

void	ft_itoa(int num)
{
	char  c_num;
	int tmp;
	int i;

	i = 1;
	if (num < 10)
	{
		c_num = num + '0';
		write(1, &c_num, 1);
	}
	else
	{
		tmp = num;
		while ((tmp /= 10) >= 1)
			i *= 10;	
		while (i >= 1)
		{
			c_num = (num / i) + '0';
			write(1, &c_num, 1);
			num %= i;
			i /= 10;
		}
	}
}

int	ft_is_prime(int a)
{
	int i;

	if (a == 2)
		return 1;
	if (a <= 1 || a % 2 == 0)
		return 0; 
	i = 3;
	while (i < a)
	{
		if (a % i == 0)
			return 0;
		else
			i += 2;
	} 
	return 1;
}

void ft_add_prime(int a)
{
	int sum;

	sum = 0;
	while (a > 0)
	{
		if (ft_is_prime(a))
			sum += a; 
		a--;
	}
	ft_itoa(sum);	
}

int		atoi(char *str)
{
	int i = 0;
	int num = 0;
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

int main(int argc, char **argv)
{
	int num = 0;

	if(argc != 2 || argv[1] < 0)
	{
		write(1, "0", 1);
	}
	else
	{
		num = atoi(argv[1]);
		ft_add_prime(num);
	}
	write(1, "\n", 1);
	return 0;
}
