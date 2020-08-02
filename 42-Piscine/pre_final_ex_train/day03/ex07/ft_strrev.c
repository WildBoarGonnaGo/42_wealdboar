int		ft_strlen(char *str);

char	*ft_strrev(char *str)
{
	int		length;
	int		index;
	char	c;

	length = ft_strlen(str) - 1;
	index = 0;
	while (index <= length / 2 + length % 2)
	{
		c = str[index];
		str[index] = str[length - index];
		str[length - index] = c;
		index++;
	}
	return (str);
	char	new_str[ft_strlen(str)];

	length = ft_strlen(str) - 1;
	index = 0;
	while (index <= length)
	{
		new_str[length] = str[index];
		index++;
		length--;
	}
	return (new_str);
}
