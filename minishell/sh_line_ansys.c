/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_ansys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/16 21:44:51 by lchantel         ###   ########.fr       */
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
			pipe(obj->fd_pipe);
			//obj->sh_pid[0] = fork();
			if (!fork())
			{
				errno = 0;
				dup2(obj->fd_pipe[1], 1);
				close(obj->fd_pipe[0]);
				close(obj->fd_pipe[1]);
				if (!ft_strncmp("pwd", obj->pipe_block[j - 1], obj->len) ||
				ft_strncmp("pwd", obj->pipe_block[j - 1], 5) == -32)
					ft_minishell_pwd(*obj);
				else if (!ft_strncmp("echo", obj->pipe_block[j - 1], 5) ||
				ft_strncmp("echo", obj->pipe_block[j - 1], 5) == -32)
					ft_minishell_echo(obj, j - 1);
				else if (!ft_strncmp("env", obj->pipe_block[j - 1], obj->len) ||
				ft_strncmp("env", obj->pipe_block[j - 1], 5) == -32)
					ft_minishell_env(*obj);
				else
					sh_user_bin(obj, j - 1);
				exit (0);
			}
			else
			{
				dup2(obj->fd_pipe[0], 0);
				close(obj->fd_pipe[0]);
				close(obj->fd_pipe[1]);
				wait(&obj->status[0]);
				//waitpid(obj->sh_pid[0], &obj->status[0], /*WIFEXITED(obj->status[0])*/0);
			}
		}
		read(0, rbuf, 4096);
		write(1, rbuf, 4096);
		dup2(obj->fd_recover[0], STDIN_FILENO);
	}
	alloc_free_2((void **)obj->tmp);	
}
