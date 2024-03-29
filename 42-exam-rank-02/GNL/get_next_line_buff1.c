/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 03:37:36 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/09 23:29:16 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memreset(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

int		ft_strlen(char *str)
{
	int	size;

	size = -1;
	if (!str)
		return (0);
	while (*(str + ++size))
		;
	return (size);
}

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

char	*ft_strdup(char *str)
{
	char	*res;
	int		size;
	int		pos;

	pos = -1;
	res = NULL;
	if (!str)
		return (0);
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	while (*(str + ++pos))
		*(res + pos) = *(str + pos);
	*(res + pos) = 0;
	return (res);
}

char 	*ft_strjoin(char *src, char *dst)
{
	int		size[2];
	int		pos[2];
	char	*mem_to_purge;
	char	*res;

	pos[0] = -1;
	pos[1] = -1;
	if (!src)
		return (NULL);
	if (!dst)
		return (src);
	size[0] = ft_strlen(src);
	size[1] = ft_strlen(dst);
	mem_to_purge = src;
	if (!(res = (char *)malloc(size[0] + size[1] + 1)))
	{
		ft_memreset((void **)&mem_to_purge);
		return (0);
	}
	while (*(src + ++pos[0]))
		*(res + pos[0]) = *(src + pos[0]);
	ft_memreset((void **)&mem_to_purge);
	while (*(dst + ++pos[1]))
		*(res + pos[0]++) = *(dst + pos[1]);
	*(res + pos[0]) = 0;
	return (res);
}

int		check_state(int nl_pos)
{
	if (nl_pos >= 0)
		return (1);
	else
		return (0);
}

int		get_next_line(char **line)
{
	char		buff[BUFF + 1];
	int			rpos;
	int			nlpos;;

	nlpos = -1;
	if (!(*line = ft_strdup("")))
		return (-1);
	while ((rpos = read(0, buff, BUFF)) > 0)
	{
		buff[rpos] = 0;
		nlpos = (!(ft_strchr(buff, '\n'))) ? 0 : ft_strchr(buff, '\n') - buff + 1;
		if (!nlpos && rpos < BUFF)
			nlpos = -1;
		if (nlpos > 0)
			buff[nlpos - 1] = 0;
		if (buff[nlpos])
		if (!(*line = ft_strjoin(*line, buff)))
			return (-1);
		if (nlpos)
			break ;
	}
	return (check_state(nlpos));
}
