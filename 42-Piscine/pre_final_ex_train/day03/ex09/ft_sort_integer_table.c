void		ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < size - 1)
	{	
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				k = tab[i];
				tab[i] = tab[j];
				tab[j] = k;
			}
			j++;	
		}
		i++;
	}
}
