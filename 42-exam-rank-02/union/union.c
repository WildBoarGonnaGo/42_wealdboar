/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 00:02:52 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/07 00:02:55 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(char *src, char c)
{
	int	i;

	i = -1;
	if (!src)
		return (0);
	while (*(src + (++i)))
		if (*(src + i) == c)
			return (src + i);
	return (0);
}

void	stdpush_tostr(char *src, int *pos, char c)
{
	*(src + (*pos)++) = c;
	*(src + *pos) = 0;
	write(1, (src + *pos - 1), 1);
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
		if (!(ft_strchr(str, *(argv[1] + pos[0]))))
			stdpush_tostr(str, &pos[2], *(argv[1] + pos[0]));
	while (*(argv[2] + (++pos[1])))
			if (!(ft_strchr(str, *(argv[2] + pos[1]))))
				stdpush_tostr(str, &pos[2], *(argv[2] + pos[1]));
	write(1, "\n", 1);
	return (0);
}
