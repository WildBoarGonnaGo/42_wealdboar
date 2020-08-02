void	ft_putchar(char c);

int		ft_atoi(char *str)
{
	int	index;
	int result;
	int sign;

	sign = 1;
	index = 0;
	result = 0;
	while (str[index] == ' ' || (str[index] >= 9 && 
				str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = (-1);
		index++;
	}
	while (str[index] == '0')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result *= 10;
		result += (str[index] - 48);
		index++;	
	}
	return (result * sign);
}
