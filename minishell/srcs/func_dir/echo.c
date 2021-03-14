/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:50:06 by lcreola           #+#    #+#             */
/*   Updated: 2021/03/14 05:01:15 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int			echo_nownl_check(char *str, int count)
{
	if (str[count] == '-' && !count)
		return (echo_nownl_check(str, ++count));
	else if (str[count] != 0 && str[0] == '-' && str[count] == 'n')
		return (echo_nownl_check(str, ++count));
	else if (!str[count])
		return (1);
	return (0);
}

int			spec_case(char **str, t_shell *obj, int word)
{
	if (echo_nownl_check(*str, 0) && !word)
	{
		if (ft_strncmp(*str, "", 1))
		{
			obj->eol = 0;
			return (0);
		}
	}
	else if (!(ft_strncmp(*str, "$?", 2)))
	{
		if (obj->status[2])
			*str = ft_itoa(obj->status[2]);
		else
			*str = ft_itoa(obj->status[0]);
	}
	return (1);
}

void		cat_ft_minishell_echo(t_shell *obj, int word, int i)
{
	if (!obj->fd_redir[1])
		dup2(obj->fd_pipe[1], 1);
	else
		dup2(1, obj->fd_pipe[1]);
	close(obj->fd_pipe[0]);
	close(obj->fd_pipe[1]);
	if (!(obj->cmd_flag & HANPIPE) && !obj->fd_redir[1])
		dup2(obj->fd_recover[1], 1);
	while (obj->pipe_block[++i])
	{
		if (word)
			write(1, " ", 1);
		if (!spec_case(&obj->pipe_block[i], obj, word) &&
		ft_strncmp(obj->pipe_block[i], "", 1))
			continue ;
		ft_putstr_fd(obj->pipe_block[i], 1);
		++word;
	}
	write(1, &obj->eol, 1);
	exit(0);
}

void		ft_minishell_echo(t_shell *obj)
{
	int		i;
	int		word;
	int		st;

	i = 0;
	word = 0;
	obj->eol = '\n';
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
		cat_ft_minishell_echo(obj, word, i);
	else
		sh_close_pipes_common(obj);
	if (WIFEXITED(obj->status[0]))
	{
		st = (WEXITSTATUS(obj->status[0]) > 0);
		if (st)
			obj->status[0] = WEXITSTATUS(obj->status[0]);
		kill(obj->child, SIGTERM);
	}
	obj->status[2] = 0;
}
