/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:52:36 by lchantel          #+#    #+#             */
/*   Updated: 2020/06/27 14:01:25 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int		ft_check_fd(int fd, int read_byte, char *buff_str_rest)
{
	if (fd < 0 || read_byte < 0)
		return (-1);
	else if (!read_byte && !buff_str_rest)
		return (0);
	else
		return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buff_str_rest;
	char		buff_str[BUFFER_SIZE + 1];
	int			read_byte;
	int			nl_stat;

	read_byte = 0;
	if (!(ft_gnl_read_rest(line, &buff_str_rest)))
	{
		while ((read_byte = read(fd, buff_str, BUFFER_SIZE)) > 0)
		{
			buff_str[read_byte] = 0;
			if ((nl_stat = ft_gnl_seekchar(buff_str, '\n'))
			|| buff_str[nl_stat] == '\n')
				buff_str[nl_stat] = 0;
			*line = ft_gnl_strjoin(*line, buff_str);
			if (nl_stat || !buff_str[nl_stat])
				buff_str_rest = ft_gnl_strjoin(buff_str_rest, buff_str +
				ft_gnl_seekchar(buff_str, 0) + 1);
			if (nl_stat || !buff_str[nl_stat])
				break ;
		}
	}
	return (ft_check_fd(fd, read_byte, buff_str_rest));
}
