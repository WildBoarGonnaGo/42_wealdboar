/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:52:36 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 12:50:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

int		ft_check_fd(int fd, int read_byte[2], char *buff_str_rest, char **line)
{
	if (fd < 0 || read_byte[0] < 0 || BUFFER_SIZE <= 0 || read_byte[1] < 0)
	{
		ft_mem_reset(line);
		return (-1);
	}
	else if (!read_byte[0] && !buff_str_rest)
		return (0);
	else
		return (1);
}

int		ft_gnl_read_rest_init(char **line, char **purge_info, char *rest)
{
	if (!(*line = ft_gnl_strdup("", 0)))
		return (-1);
	if (!(*purge_info = rest))
		return (0);
	else
	{
		free(*line);
		return (1);
	}
}

int		ft_next_to_new_buff(char **line, char **rest)
{
	if (!(*line = ft_gnl_strdup(*rest, ft_gnl_strlen(*rest))))
		return (-1);
	if (*rest)
		free(*rest);
	*rest = NULL;
	return (0);
}

void	ft_mem_reset(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char	*buff_str_rest[1024];
	char		buff_str[BUFFER_SIZE + 1];
	int			read_byte[2];
	int			nl_stat;

	read_byte[0] = 0;
	if (!(read_byte[1] = ft_gnl_read_rest(line, buff_str_rest + fd)))
	{
		while ((read_byte[0] = read(fd, buff_str, BUFFER_SIZE)) > 0)
		{
			buff_str[read_byte[0]] = 0;
			if ((nl_stat = ft_gnl_seekchar(buff_str, '\n'))
			|| buff_str[nl_stat] == '\n')
				buff_str[nl_stat] = 0;
			if (!(*line = ft_gnl_strjoin(*line, buff_str)))
				return (-1);
			if (nl_stat || !buff_str[nl_stat])
				if (!(*(buff_str_rest + fd) = ft_gnl_strjoin(*(buff_str_rest
				+ fd), buff_str + ft_gnl_seekchar(buff_str, 0) + 1)))
					return (-1);
			if (nl_stat || !buff_str[nl_stat])
				break ;
		}
	}
	return (ft_check_fd(fd, read_byte, *(buff_str_rest + fd), line));
}
