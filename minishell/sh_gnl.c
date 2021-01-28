/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:02:14 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/28 20:12:44 by lchantel         ###   ########.fr       */
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
	sig_state = sig;
}


int 	sh_gnl(int fd, char **line)
{
	t_gnl obj;
	obj.st = 0;
	obj.i = 0;
	obj.orig_stdout = dup(STDOUT_FILENO);
	if (!*line)
		*line = ft_strdup("");
	pipe(obj.fd_pipe);
	signal(SIGINT, sh_read_escape);
	if (!(obj.gnl_fork = fork()))
	{
		dup2(obj.fd_pipe[0], 0);
		close(obj.fd_pipe[0]);
		close(obj.fd_pipe[1]);
		while ((obj.byte = read(fd, &obj.buf[obj.i], 1)) > 0)
		{	
			if (sig_state)
			{
				obj.st = 1;
				break ;
			}
			if (obj.buf[obj.i] == '\n')
			{
				obj.st = 10;
				obj.buf[obj.i] = 0;
			}
			//*line = addchar(*line, obj.buf[obj.i]);
			if (!obj.buf[obj.i])
				break ;
		}
		exit (0);
	}
	else
	{
		dup2(obj.fd_pipe[1], 1);
		close(obj.fd_pipe[0]);
		close(obj.fd_pipe[1]);
		wait(&obj.wstatus);	
	}
	if (WIFEXITED(obj.wstatus))
	{
		write(1, obj.buf, 2048);
		dup2(obj.orig_stdout, 1);
		*line = ft_strdup(obj.buf);
		obj.byte = ft_strlen(obj.buf);
		obj.st = obj.byte;;
		kill(obj.gnl_fork, SIGTERM);
	}
	else if (sig_state == 2)
		return (1);
	if (obj.byte <= 0 && !sig_state)
		return (-1);
	return (obj.st);
}
