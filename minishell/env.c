/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:53:12 by lcreola           #+#    #+#             */
/*   Updated: 2021/02/22 16:30:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_minishell_env(t_shell *obj)
{
	int	i;

	i = -1;
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
		cat_ft_minishel_env(obj, i);
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
}

void	cat_ft_minishel_env(t_shell *obj, int i)
{
	dup2(obj->fd_pipe[1], 1);
	close(obj->fd_pipe[0]);
	close(obj->fd_pipe[1]);
	if (!(obj->cmd_flag & HANPIPE) && !obj->fd_redir[1])
		dup2(obj->fd_recover[1], 1);
	while (obj->envp[++i])
	{
		if (ft_strchr(obj->envp[i], '='))
		{
			write(1, obj->envp[i], ft_strlen(obj->envp[i]));
			write(1, "\n", 1);
		}
	}
	exit(0);
}
