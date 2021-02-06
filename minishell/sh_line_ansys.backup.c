/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_ansys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/26 17:54:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void sh_line_ansys(t_shell *obj)
{
	int		i;
	int 	j;
	char	rbuf[4096] = {0};

	i = -1;	
	obj->tmp = ft_split(obj->line, ';');
	obj->fd_recover[0] = dup(STDIN_FILENO);
	obj->fd_recover[1] = dup(STDOUT_FILENO);
	while (obj->tmp[++i])
	{
		j = -1;
		while (++j < 4096)
			rbuf[j] = 0;
		j = 0;
		obj->pipe_block = ft_split(obj->tmp[i], '|');
		while (obj->pipe_block[j++])
		{
			obj->clean = obj->pipe_block[j - 1];
			obj->pipe_block[j - 1] = ft_strtrim(obj->pipe_block[j - 1], " ");
			free(obj->clean);
			obj->clean = NULL;
			obj->len = ft_strlen(obj->pipe_block[j - 1]) + 1;
			if (!ft_strncmp("cd", obj->pipe_block[j - 1], obj->len) ||
			ft_strncmp("cd", obj->pipe_block[j - 1], 3) == -32)
				change_dir(obj, j - 1);
			else if (!ft_strncmp("export", obj->pipe_block[j - 1], obj->len) ||
			ft_strncmp("export", obj->pipe_block[j - 1], 7) == -32)
				ft_minishell_export(obj, j - 1);
			else if (!ft_strncmp("unset", obj->pipe_block[j - 1], obj->len) ||
			ft_strncmp("unset", obj->pipe_block[j - 1], 6) == -32)
				unset_envp(obj, j - 1);
			else if (!ft_strncmp("echo", obj->pipe_block[j - 1], 5) ||
			ft_strncmp("echo", obj->pipe_block[j - 1], 5) == -32)
				ft_minishell_echo(obj, j - 1);
			else if (!ft_strncmp("env", obj->pipe_block[j - 1], obj->len) ||
			ft_strncmp("env", obj->pipe_block[j - 1], 4) == -32)
				ft_minishell_env(obj, j - 1);
			else if (!ft_strncmp("exit", obj->pipe_block[j - 1], obj->len) ||
			ft_strncmp("exit", obj->pipe_block[j - 1], 5) == -32)
				obj->status[1] = sh_exit(obj, j - 1);
			else
				sh_user_bin(obj, j - 1);
		}
		dup2(obj->fd_recover[0], STDIN_FILENO);
	}
	alloc_free_2((void **)obj->tmp);	
}
