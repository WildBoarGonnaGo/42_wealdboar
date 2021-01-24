/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:53:12 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/24 17:51:07 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_minishell_env(t_shell *obj, int indx)
{
	int	i;

	i = -1;
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
	{
		dup2(obj->fd_pipe[1], 1);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		if (!obj->pipe_block[indx + 1])
			dup2(obj->fd_recover[1], 1);
		while (obj->envp[++i])
		{
			if (ft_strchr(obj->envp[i], '='))
			{
				write(1, obj->envp[i], ft_strlen(obj->envp[i]));
				write(1, "\n", 1);
			}
		}
	}
	else
	{
		dup2(obj->fd_pipe[0], 0);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		wait(&obj->status[0]);
	}
}
