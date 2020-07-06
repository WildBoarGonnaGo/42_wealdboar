/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:52:36 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/06 05:13:28 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_check_fd(int fd, int read_byte, char **buff_str_rest, char **line,
		int rest_alloc_info)
{
	if (fd < 0 || read_byte < 0 || BUFFER_SIZE <= 0 || rest_alloc_info < 0)
	{
		if (*line)
			free(*line);
		return (-1);
	}
	else if (!read_byte && !*(buff_str_rest + fd))
		return (0);
	else
		return (1);
}

int		ft_gnl_read_rest_init(char **line, char **purge_info, char *rest)
{
	*line = ft_gnl_strdup("", 0);
	if (!(*purge_info = rest))
		return (0);
	else
	{
		free(*line);
		return (1);
	}
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
				if (!(*(buff_str_rest + fd) = ft_gnl_strjoin(*(buff_str_rest + fd),
				buff_str + ft_gnl_seekchar(buff_str, 0) + 1)))
					return (-1);
			if (nl_stat || !buff_str[nl_stat])
				break ;
		}
	}
	return (ft_check_fd(fd, read_byte[0], buff_str_rest, line, read_byte[1]));
}
