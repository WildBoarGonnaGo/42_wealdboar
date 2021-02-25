/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:43:41 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/25 20:22:22 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sh_redirects(t_shell *obj, int *index)
{
	int	state;

	state = 0;
	if (!ft_strncmp(obj->cmd[0], "echo", 5))
		return (0);
	if ((state = (!(ft_strncmp(">", obj->cmd[*index], 2)))))
	{
		if (obj->fd_redir[1])
			close(obj->fd_redir[1]);
		obj->fd_redir[1] = open(obj->cmd[*index + 1], 
		O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		dup2(obj->fd_redir[1], 1);
	}
	else if ((state = (!(ft_strncmp("<", obj->cmd[*index], 2)))))
	{
		if (obj->fd_redir[0])
			close(obj->fd_redir[0]);
		obj->fd_redir[0] = open(obj->cmd[*index + 1], O_RDONLY);
		dup2(obj->fd_redir[0], 0);
	}
	else if ((state = (!(ft_strncmp(">>", obj->cmd[*index], 3)))))
	{
		if (obj->fd_redir[1])
			close(obj->fd_redir[1]);
		obj->fd_redir[1] = open(obj->cmd[*index + 1], O_RDWR | O_APPEND | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		dup2(obj->fd_redir[1], 1);
	}
	*index += (state != 0);
	return (state);

}
