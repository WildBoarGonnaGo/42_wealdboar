/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:05:30 by lcreola           #+#    #+#             */
/*   Updated: 2021/02/25 18:21:24 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_minishell_pwd(t_shell *obj)
{
	char	cwd[BUFFER_SIZE];

	pipe(obj->fd_pipe);
	obj->backup = sh_envp_search("PWD", obj);
	if (!(obj->child = fork()))
	{
		if (!obj->fd_redir[1])
			dup2(obj->fd_pipe[1], 1);
		else
			dup2(1, obj->fd_pipe[1]);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		if (!(obj->cmd_flag & HANPIPE) && !obj->fd_redir[1])
			dup2(obj->fd_recover[1], 1);
		if (!getcwd(cwd, BUFFER_SIZE))
		{
			ft_putstr_fd(obj->backup, 1);
			write(1, "\n", 1);
			exit (1);
		}
		ft_putstr_fd(cwd, 1);
		write(1, "\n", 1);
		exit (0);
	}
	else
	{
		dup2(obj->fd_pipe[0], 0);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		wait(&obj->status[0]);
	}
	if (WIFEXITED(obj->status[0]))
	{
		obj->status[0] = (WEXITSTATUS(obj->status[0]) > 0);
		kill(obj->child, SIGTERM);
	}
	if (!getcwd(NULL, 0))
		obj->envp = change_pwd(obj, "PWD", obj->backup);
	if (obj->backup)
	{
		free(obj->backup);
		obj->backup = NULL;
	}
	return (0);
}
