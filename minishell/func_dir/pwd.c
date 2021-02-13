/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:05:30 by lcreola           #+#    #+#             */
/*   Updated: 2021/02/13 20:29:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_minishell_pwd(t_shell *obj)
{
	char	cwd[BUFFER_SIZE];

	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
	{
		dup2(obj->fd_pipe[1], 1);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		if (/*!obj->pipe_block[indx + 1]*/!(obj->cmd_flag & HANPIPE))
			dup2(obj->fd_recover[1], 1);
		getcwd(cwd, BUFFER_SIZE);
		ft_putstr_fd(cwd, 1);
		write(1, "\n", 1);
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
	return (0);
}
