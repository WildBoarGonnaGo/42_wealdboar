/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:02:14 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/31 20:02:36 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include "srcs/libft/libft.h"

int		check_line(char *line)
{
	int	len;

	if (!line)
		return (1);
	len = ft_strlen(line);
	if (!len || !*line)
		return (0);
	return (1);
}

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
	obj.len = 0;
	if (!*line)
		*line = ft_strdup("");
	while ((obj.byte = read(fd, &obj.buf[obj.i], 1)) > 0 || obj.len)
	{
		if (!obj.buf[obj.i - 1] && check_line(*line) && !obj.byte)
		{
			write(1, "  \b\b", 4);
				continue ;
		}
		if (obj.buf[obj.i] == '\n')
		{
			obj.st = 10;
			obj.buf[obj.i] = 0;
		}
		*line = addchar(*line, obj.buf[obj.i]);
		obj.len = ft_strlen(*line);
		if (!obj.buf[obj.i])
			break ;
	}
	if (obj.byte < 0)
		return (-1);
	if (!obj.st)
		write(1, "exit\n", ft_strlen("exit\n"));
	return (obj.st);
}
