/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:55:02 by lcreola           #+#    #+#             */
/*   Updated: 2021/02/13 19:55:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_no_arg_format(char *str)
{
	char	*pos_eq;
	int		len;

	len = ft_strlen(str);
	if ((pos_eq = ft_strchr(str, '=')))
	{
		write(1, "declare -x ", 11);
		write(1, str, pos_eq - str + 1);
		write(1, "\"", 1);
		write(1, str + (pos_eq - str + 1), len - (pos_eq - str));
		write(1, "\"\n", 2);
	}
	else
	{
		write(1, "declare -x ", 11);
		write(1, str, len);
		write(1, "\n", 1);
	}
}

int		ft_minishell_export_output(t_shell *obj)
{
	char	**tmp;
	int		i;

	tmp = ft_minishell_export_sort(obj->envp);
	obj->len = ft_minishell_export_envplen(obj->envp);
	i = 0;
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
	{
		dup2(obj->fd_pipe[1], 1);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		if (!(obj->cmd_flag & HANPIPE))
			dup2(obj->fd_recover[1], 1);
		while (i < obj->len)
			export_no_arg_format(tmp[i++]);
		exit (0);
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
	alloc_free_2((void **)tmp);
	return (0);
}

int		ft_minishell_export_check(t_shell *obj)
{
	char	*eq_char;
	int		pos[4];

	pos[0] = 0;
	while (obj->cmd[++pos[0]])
	{
		pos[2] = -1;
		pos[3] = 0;
		while (obj->envp[++pos[2]])
			;
		if (check_export_input(obj->cmd[pos[0]], 0, obj->cmd[0], 0))
		{
			pos[1] = -1;
			while (obj->envp[++pos[1]])
			{
				eq_char = ft_strchr(obj->envp[pos[1]], '=');
				(eq_char) ? obj->len = eq_char - obj->envp[pos[1]] :
				ft_strlen(obj->envp[pos[1]]);
				if (!ft_strncmp(obj->envp[pos[1]], obj->cmd[pos[0]], obj->len))
				{
					if (ft_strchr(obj->cmd[pos[0]], '='))
					{
						obj->clean = obj->envp[pos[1]];
						obj->envp[pos[1]] = ft_strdup(obj->cmd[pos[0]]);
						free(obj->clean);
					}
					break ;
				}
			}
			if (pos[1] == pos[2])
			{
				obj->envp = (char **)memrealloc((void *)obj->envp, 
				(++pos[1]) * sizeof(char*), sizeof(char *));
				obj->envp[pos[1] - 1] = ft_strdup(obj->cmd[pos[0]]);
				obj->envp[pos[1]] = NULL;
			}
		}
		else
			obj->status[0] = 1;
	}
	return (0);
}

void	ft_minishell_export(t_shell *obj)
{
	int	size;

	size = -1;
	obj->status[0] = 0;
	obj->cmd = obj->pipe_block;
	while (obj->cmd[++size])
		;
	if (size > 1)
		ft_minishell_export_check(obj);
	else
		ft_minishell_export_output(obj);
}
