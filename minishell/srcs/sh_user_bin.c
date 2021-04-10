/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_user_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:54:10 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/16 20:39:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_general_bin_search(t_shell *obj, char *line, int st)
{
	errno = 0;
	if (!obj->fd_redir[1])
		dup2(obj->fd_pipe[1], 1);
	else
		dup2(1, obj->fd_pipe[1]);
	close(obj->fd_pipe[0]);
	close(obj->fd_pipe[1]);
	if (!(obj->cmd_flag & HANPIPE) && !obj->fd_redir[1])
		dup2(obj->fd_recover[1], 1);
	st += execve(line, obj->bin_args, obj->envp);
	if (st <= 0)
	{
		if (st == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(obj->bin_search, 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
		else if (!st && (*line == '.' || *line == '/' || *line == '~'))
			sh_cmd_err_output(obj);
	}
	if (errno == 13)
		exit(126);
	exit(errno);
}

void	sh_user_bin_exec(t_shell *obj, char **line, int st)
{
	sh_bin_line_check(obj, line, st);
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
		sh_general_bin_search(obj, *line, st);
	else
		sh_close_pipes_general(obj);
	obj->if_child = 0;
	if (WIFEXITED(obj->status[0]))
		sh_kill_proc(obj);
	sh_free_str(line);
	sh_free_str(&obj->bin_search);
	alloc_free_2((void ***)&obj->bin_args);
	alloc_free_2((void ***)&obj->bin);
}

void	sh_user_bin_init(t_shell *obj, char **line, int *st)
{
	*st = 1;
	obj->len = 1;
	*line = 0x0;
	obj->bin_args = 0x0;
	obj->bin_args = execve_args(obj);
}

int		sh_user_bin(t_shell *obj)
{
	int		i;
	int		st;
	char	*line;

	sh_user_bin_init(obj, &line, &st);
	if (*obj->bin_search != '.' && *obj->bin_search != '/' \
	&& *obj->bin_search != '~')
	{
		st = 0;
		i = -1;
		while (obj->envp[++i])
			if (!(ft_strncmp(obj->envp[i], "PATH", 4)))
				break ;
		if (obj->envp[i])
			sh_search_bin(obj, -1, &line, i);
		else
			return (sh_no_bin_found(obj, &line));
	}
	sh_user_bin_exec(obj, &line, st);
	return (obj->status[0]);
}
