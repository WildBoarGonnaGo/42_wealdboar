/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:12:33 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/07 19:09:58 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		ft_mem_reset(&str);
		return (NULL);
	}
	while (++i < len)
		*(res + i) = *(str + i);
	*(res + i) = 0;
	return (res);
}

char	*ft_gnl_strjoin(char *dst, char *src)
{
	int		cur_func_info[4];
	char	*join_res;

	cur_func_info[0] = -1;
	cur_func_info[1] = 0;
	if (!src)
		return (dst);
	cur_func_info[2] = ft_gnl_strlen(dst);
	cur_func_info[3] = ft_gnl_strlen(src);
	if (!(join_res = (char *)malloc(cur_func_info[2]
	+ cur_func_info[3] + 1)))
	{
		ft_mem_reset(&dst);
		ft_mem_reset(&src);
		return (NULL);
	}
	while (++cur_func_info[0] < cur_func_info[2])
		*(join_res + cur_func_info[0]) = *(dst + cur_func_info[0]);
	ft_mem_reset(&dst);
	while (cur_func_info[1] < cur_func_info[3])
		*(join_res + cur_func_info[0]++) = *(src + cur_func_info[1]++);
	*(join_res + cur_func_info[0]) = 0;
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
	if (!(*line))
		return (-1);
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
