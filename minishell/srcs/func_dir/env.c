/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:53:12 by lcreola           #+#    #+#             */
/*   Updated: 2021/03/14 05:01:22 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sh_minishell_core_body(t_shell *obj, int i)
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

void	ft_minishell_env(t_shell *obj)
{
	int	i;

	i = -1;
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
		sh_minishell_core_body(obj, i);
	else
		sh_close_pipes_common(obj);
	if (WIFEXITED(obj->status[0]))
		sh_kill_proc(obj);
}
