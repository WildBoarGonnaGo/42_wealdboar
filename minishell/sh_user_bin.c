/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_user_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:54:10 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/17 18:45:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int 	sh_user_bin(t_shell *obj)
{
	int 	i;            
	int 	st;
	char	*line;

	i = -1;
	st = 1;
	obj->len = 1;
	line = NULL;
	obj->bin_args = execve_args(obj);
	obj->cmd = obj->pipe_block;
	if (*obj->bin_search != '.' && *obj->bin_search != '/' \
	&& *obj->bin_search != '~')
	{
		st = 0;
		while (ft_strncmp(obj->envp[++i], "PATH", 4))
			;
		obj->bin = ft_split(obj->envp[i] + 5, ':');
		i = -1;
		while (obj->bin[++i])
		{
			if (!(obj->sh_dir = opendir(obj->bin[i])))
				break ;
			while ((obj->binary = readdir(obj->sh_dir)))
			{
				obj->len = ft_strlen(obj->bin_search) + 1;
				if (!(obj->len = ft_strncmp(obj->bin_search,
				(char *)obj->binary->d_name, obj->len)))
				{
					line = ft_strdup(obj->bin[i]);
					obj->len = ft_strlen(line);
					if (line[obj->len - 1] != '/')
						line = addchar(line, '/');
					obj->clean = line;
					line = ft_strjoin(line, obj->binary->d_name);
					obj->len = 0;
					free(obj->clean);	
					break ;
				}
			}
			closedir(obj->sh_dir);
			if (!obj->len)
				break ;
		}
	}
	if (!st)
	{
		if (!line)
			line = ft_strdup(obj->pipe_block[0]);
		alloc_free_2((void **)obj->bin);
	}
	else 		
		line = ft_strdup(obj->pipe_block[0]);
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
	{
		errno = 0;
		dup2(obj->fd_pipe[1], 1);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		if (/*!obj->pipe_block[indx + 1]*/!(obj->cmd_flag & HANPIPE))
			dup2(obj->fd_recover[1], 1);
		st += execve(line, obj->bin_args, obj->envp);
		if (st <= 0)
		{
			if (st == -1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(obj->bin_search, 2);
				ft_putstr_fd(": command not found\n", 2);
				//write(2, "command not found\n", ft_strlen("command not found\n"));
				exit (127);
			}
			else if (!st && (*obj->line == '.'
			|| *obj->line == '/' || *obj->line == '~'))
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(obj->bin_search, 2);
				write(2, ": ", 2);
				ft_putstr_fd(strerror(errno), 2);
				write(2, "\n", 1);
				exit (1);
			}	
		}
		exit (errno);
	}
	else
	{
		obj->if_child = 1;
		dup2(obj->fd_pipe[0], 0);	
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		wait(&obj->status[0]);
	}
	obj->if_child = 0;
	if (WIFEXITED(obj->status[0]))
	{
		obj->status[0] = WEXITSTATUS(obj->status[0]);
		kill(obj->child, SIGTERM);
	}
	free(line);
	return (obj->status[0]);
}
