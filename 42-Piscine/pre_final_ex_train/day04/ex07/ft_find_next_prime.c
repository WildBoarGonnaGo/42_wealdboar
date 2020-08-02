int	ft_find_next_prime(int nb)
{
	int index;

	index = 2;
	if (nb < 2)
		return (0);
	while (index < nb + 1)
	{
		if ((nb + 1) % index == 0)
			return(ft_find_next_prime(nb + 1));
		index++;
	}
	return (nb + 1);
}
