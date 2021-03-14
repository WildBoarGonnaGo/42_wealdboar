/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:43:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:26:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_redir_err_output(t_shell *obj, int index)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(obj->cmd[index], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	sh_redir_case_handle(t_shell *obj, int num,
		int param_1, int param_2)
{
	if (obj->fd_redir[num])
		close(obj->fd_redir[num]);
	obj->fd_redir[num] = open(obj->cmd[obj->fd_trick + 1]
	, param_1, param_2);
	dup2(obj->fd_redir[num], num);
	if (obj->fd_redir[num] < 0)
		obj->err_fd[1] = obj->fd_trick + 1;
}

int		sh_redirects(t_shell *obj, int *index)
{
	int	state;

	state = 0;
	obj->err_fd[1] = 0;
	obj->fd_trick = *index;
	if ((state = (!(ft_strncmp(">", obj->cmd[*index], 2)))))
		sh_redir_case_handle(obj, 1, O_RDWR | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if ((state = (!(ft_strncmp("<", obj->cmd[*index], 2)))))
		sh_redir_case_handle(obj, 0, O_RDONLY, 0);
	else if ((state = (!(ft_strncmp(">>", obj->cmd[*index], 3)))))
		sh_redir_case_handle(obj, 1, O_RDWR | O_APPEND | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	*index += (state > 0);
	obj->err_fd[0] |= ((obj->fd_redir[0] < 0) |
	((obj->fd_redir[1] < 0) << 1));
	if (obj->err_fd[1])
		sh_redir_err_output(obj, obj->err_fd[1]);
	return (state);
}
