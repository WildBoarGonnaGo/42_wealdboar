/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 00:10:52 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/28 00:53:32 by wealdboar        ###   ########.fr       */
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

int		ft_strlen(const char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	while (*(s + size))
		++size;
	return (size);
}

int		ft_seek_char(const char *s, char c)
{
	int	indx;

	indx = -1;
	if (!s)
		return (0);
	while (*(s + ++indx))
		if (*(s + indx) == c)
			return (indx);
	return (0);
}

char	*ft_calloc(unsigned int typel, unsigned int rng)
{
	char	*addr;
	int		indx;
	int		size;

	size = typel * rng;
	indx = 0;
	if (!(addr = malloc(size)))
		return (NULL);
	while (indx < size)
		*(addr + indx++) = 0;
	return (addr);
}

char 	*ft_char_add(const char *src, char c)
{
	char	*res;
	int 	indx;
	int		size;

	if (!src)
		return (NULL);
	indx = -1;
	size = ft_strlen(src);
	res = ft_calloc(1, size + 2);
	while (*(src + ++indx))
		*(res + indx) = *(src + indx);
	*(res + indx++) = c;
	if (src)
		free((void *)src);
	return (res);
}

char	*ft_substr(const char *src, int strt, int byte)
{
	int		indx;
	char	*res;

	indx = 0;
	if (!(res = ft_calloc(1, byte + 1)))
		return (NULL);
	while (indx < byte && *(src + indx))
		*(res + indx++) = *(src + strt++);
	return (res);
}

int		get_next_line(char **line)
{
	static char *s;
	char		buff[1];
	char		*tmp;
	int			pos;

	if (!line || (!(s) && !(s = ft_calloc(1, 1))))
		return (-1);
	while (read(0, buff, 1) > 0)
	{
		s = ft_char_add(s, *buff);
		if (*buff == '\n')
			break ;
	}
	if ((pos = ft_seek_char(s, '\n')))
	{
		*line = ft_substr(s, 0, pos);
		tmp = s;
		s = ft_substr(s, pos + 1, ft_seek_char(s, 0));
		free(tmp);
		return (1);
	}
	*line = ft_substr(s, 0, 0);
	free(s);
	return (0);
}
