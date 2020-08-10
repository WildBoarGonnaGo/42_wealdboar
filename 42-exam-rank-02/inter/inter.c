/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 00:02:41 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/07 03:28:12 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (*(str + ++i))
		if (*(str + i) == c)
			return (str + i);
	return (0);
}

void	strpush_tostr(char *str, int *pos, int c)
{
	*(str + (*pos)++) = c;
	*(str + *pos) = 0;
	write(1, str + *pos - 1, 1);
}

int		main(int argc, char *argv[])
{
	char	str[255];
	int		pos[3];

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	pos[0] = -1;
	pos[1] = -1;
	pos[2] = 0;
	while (*(argv[1] + (++pos[0])))
	{
		while (*(argv[2] + (++pos[1])))
		{
			if (*(argv[1] + pos[0]) == *(argv[2] + pos[1]) &&
			!ft_strchr(str, *(argv[1] + pos[0])))
				strpush_tostr(str, &pos[2], *(argv[1] + pos[0]));
		}
		pos[1] = -1;
	}
	write(1, "\n", 1);
	return (0);
}
