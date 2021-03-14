/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bin_pipes_over.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:40:00 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:21:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_close_pipes_general(t_shell *obj)
{
	obj->if_child = 1;
	dup2(obj->fd_pipe[0], 0);
	close(obj->fd_pipe[0]);
	close(obj->fd_pipe[1]);
	wait(&obj->status[0]);
}

void	sh_kill_proc(t_shell *obj)
{
	obj->status[0] = WEXITSTATUS(obj->status[0]);
	kill(obj->child, SIGTERM);
}

void	sh_close_pipes_common(t_shell *obj)
{
	dup2(obj->fd_pipe[0], 0);
	close(obj->fd_pipe[0]);
	close(obj->fd_pipe[1]);
	wait(&obj->status[0]);
}
