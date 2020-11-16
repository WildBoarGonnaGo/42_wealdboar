int		ft_strlen(char *str);

int		is_base_valid(char *base)
{
	int	pos[2];
	int	len;

	pos[0] = -1;
	pos[1] = -1;
	if (!base)
		return (0);
	len = ft_strlen(base);
	if (len < 2)
		return (0);
	while (++pos[0] < len - 1)
	{
		pos[1] = pos[0] + 1;
		while (++pos[1] < len)
		{
			if (base[pos[0]] == base[pos[1]] || 
			base[pos[0]] == '+' || base[pos[0]] == '-')
				return (0);
		}
	}
	return (1);
}

int		is_str_valid(char *str, char *base)
{
	int	pos[2];
	int	len[2];
	int	state;

	len[0] = ft_strlen(str);
	len[1] = ft_strlen(base);
	pos[0] = -1;
	pos[1] = -1;
	if (!str)
		return (0);
	if (!*str)
		return (0);
	while (++pos[0] < len[0])
	{
		state = 0;
		while (++pos[1] < len[1])
			state += (str[pos[0]] != base[pos[1]]) ? 0 : 1;	
		if (!state)
			return (0);
		pos[1] = -1;
	}
	return (1);
}

int		seek_pos(char *str, char *base)
{
	int	i;

	i = -1;
	while (*base)
	{
		++i;
		if (*base == *str)
			return (i);
		++base;
	}
	return (-1);
}

int 	ft_atoi_base(char *str, char *base)
{
	int	number;
	int	num_base;
	int	sign;

	number = 0;
	sign = 1;
	number |= (is_base_valid(base));
	number |= ((is_str_valid(str, base)) << 1);
	if (number != 3)
		return (0);
	while (*str > 8 && *str < 14)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	number = 0;
	num_base = ft_strlen(base);
	while (*str)
	{
		number *= num_base;
		number += seek_pos(*str, base);
		++str;
	}
	return (number * sign);
}
