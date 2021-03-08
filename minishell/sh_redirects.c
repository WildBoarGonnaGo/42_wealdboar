/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:43:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/08 15:09:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"
#include <string.h>

void	sh_redir_err_output(t_shell *obj, int index)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(obj->cmd[index], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

int		sh_redirects(t_shell *obj, int *index)
{
	int	state;

	state = 0;
	obj->err_fd[1] = 0;
	/*if (!ft_strncmp(obj->cmd[0], "echo", 5))
		return (0);*/
	if ((state = (!(ft_strncmp(">", obj->cmd[*index], 2)))))
	{
		if (obj->fd_redir[1])
			close(obj->fd_redir[1]);
		obj->fd_redir[1] = open(obj->cmd[*index + 1], 
		O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		dup2(obj->fd_redir[1], 1);
		if (obj->fd_redir[1] < 0)
			obj->err_fd[1] = *index + 1;
	}
	else if ((state = (!(ft_strncmp("<", obj->cmd[*index], 2)))))
	{
		if (obj->fd_redir[0])
			close(obj->fd_redir[0]);
		obj->fd_redir[0] = open(obj->cmd[*index + 1], O_RDONLY);
		dup2(obj->fd_redir[0], 0);
		if (obj->fd_redir[0] < 0)
			obj->err_fd[1] = *index + 1;
	}
	else if ((state = (!(ft_strncmp(">>", obj->cmd[*index], 3)))))
	{
		if (obj->fd_redir[1])
			close(obj->fd_redir[1]);
		obj->fd_redir[1] = open(obj->cmd[*index + 1], O_RDWR | O_APPEND | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		dup2(obj->fd_redir[1], 1);
		if (obj->fd_redir[1] < 0)
			obj->err_fd[1] = *index + 1;
	}
	*index += (state > 0);
	obj->err_fd[0] |= ((obj->fd_redir[0] < 0) |
	((obj->fd_redir[1] < 0) << 1));
	if (obj->err_fd[1])
		sh_redir_err_output(obj, obj->err_fd[1]);
	return (state);
}
