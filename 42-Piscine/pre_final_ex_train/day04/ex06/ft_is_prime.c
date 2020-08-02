int	ft_is_prime(int nb)
{
	int index;

	index = 2;
	if (nb < 2)
		return (0);
	while (index < nb)
	{
		if (nb % index == 0)
			return(0);
		index++;
	}
	return (1);
}
