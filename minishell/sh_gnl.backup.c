/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_gnl.backup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:02:14 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/28 22:12:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char	*sh_strchr(const char *s, int c, size_t size)
{
	size_t		bound;
	size_t		i;

	bound = ft_strlen(s);
	i = -1;
	while (i <= bound && i < size)
		if (*(s + ++i) == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}

void		sh_read_escape(int sig)
{
	write(1, "\b\b  \nminishell$ ", ft_strlen("\b\b  \nminishell$ ") + 1);
	sig_state = sig;
}


int 	sh_gnl(int fd, char **line)
{
	t_gnl obj;
	obj.st = 0;
	obj.i = 0;
	if (!*line)
		*line = ft_strdup("");
	while ((obj.byte = read(fd, &obj.buf[obj.i], 1)) > 0)
	{
		if (obj.buf[obj.i] == '\n')
		{
			obj.st = 10;
			obj.buf[obj.i] = 0;
		}
		*line = addchar(*line, obj.buf[obj.i]);
		if (!obj.buf[obj.i])
			break ;
	}
	if (obj.byte <= 0)
		return (-1);
	return (obj.st);
}
