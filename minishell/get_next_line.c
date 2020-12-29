/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:02:14 by wildboarg         #+#    #+#             */
/*   Updated: 2020/12/29 15:44:50 by wildboarg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	ft_strlen(const char *s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int sh_gnl(int fd, char **line)
{
	t_gnl obj;

	obj.i = 0;
	while ((obj.byte = read(fd, &obj.buf, 1)) >= 0)
	{
		if (obj.buf[obj.i] == '\n' || !obj.buf[obj.i])
		{
			obj.st = obj.buf[obj.i];
			if (obj.buf[obj.i] == '\n')
				obj.buf[obj.i] = 0;
			*line = (char *)malloc(ft_strlen(obj.buf) + 1);
			break ;
		}
		++obj.i;
	}
	if (obj.byte < 0)
		return (-1);
	return (obj.st);
}
