/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:12:33 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/06 21:44:31 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (*(str + (++i)))
		;
	return (i);
}

char	*ft_gnl_strdup(char *str, int nbytes)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (ft_gnl_strlen(str) > nbytes) ? nbytes :
	ft_gnl_strlen(str);
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	while (++i < len)
		*(res + i) = *(str + i);
	*(res + i) = 0;
	return (res);
}

char	*ft_gnl_strjoin(char *dst, char *src)
{
	int		dst_len;
	int		src_len;
	char	*join_res;
	int		cur;
	int		pos;

	cur = -1;
	pos = 0;
	if (!src)
		return (dst);
	dst_len = ft_gnl_strlen(dst);
	src_len = ft_gnl_strlen(src);
	if (!(join_res = (char *)malloc(dst_len + src_len + 1)))
		return (NULL);
	while (++cur < dst_len)
		*(join_res + cur) = *(dst + cur);
	if (dst)
		free(dst);
	while (pos < src_len)
		*(join_res + cur++) = *(src + pos++);
	*(join_res + cur) = 0;
	return (join_res);
}

int		ft_gnl_seekchar(char *str, char c)
{
	int	pos;

	pos = -1;
	if (!str)
		return (0);
	while (*(str + ++pos))
		if (*(str + pos) == c)
			return (pos);
	if (!c)
		return (pos);
	return (0);
}

int		ft_gnl_read_rest(char **line, char **rest)
{
	int		pos;
	char	*purge_info;

	if (!(ft_gnl_read_rest_init(line, &purge_info, *rest)))
		return (0);
	if ((pos = ft_gnl_seekchar(*rest, '\n')) || (*(*rest + pos) == '\n'))
	{
		*line = ft_gnl_strdup(*rest, pos++);
		*rest = ft_gnl_strdup(*rest + pos, ft_gnl_strlen(*rest + pos));
		if (!*line || !*rest)
			return (-1);
		if (purge_info)
			free(purge_info);
		return (1);
	}
	else
		return (ft_next_to_new_buff(line, rest));
}
