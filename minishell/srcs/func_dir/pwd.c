/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:05:30 by lcreola           #+#    #+#             */
/*   Updated: 2021/03/14 05:02:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void		cat_ft_minishell_pwd(t_shell *obj, char *cwd)
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
		exit(1);
	}
	ft_putstr_fd(cwd, 1);
	write(1, "\n", 1);
	exit(0);
}

int			ft_minishell_pwd(t_shell *obj)
{
	char	cwd[BUFFER_SIZE];

	pipe(obj->fd_pipe);
	obj->backup = sh_envp_search("PWD", obj);
	if (!(obj->child = fork()))
		cat_ft_minishell_pwd(obj, cwd);
	else
		sh_close_pipes_common(obj);
	if (WIFEXITED(obj->status[0]))
		sh_kill_proc(obj);
	if (!getcwd(NULL, 0))
		obj->envp = change_pwd(obj, "PWD", obj->backup);
	if (obj->backup)
	{
		free(obj->backup);
		obj->backup = NULL;
	}
	return (0);
}
