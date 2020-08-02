int	ft_sqrt(int nb)
{
	int  num;
	
	num = 1;
	if (nb <= 0)
		return (0);
	while (num * num != nb)
	{
		num++;
		if (num * num > nb)
			return (0);
	}
	return (num);
}
