/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:50:06 by lcreola           #+#    #+#             */
/*   Updated: 2021/02/06 18:45:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		spec_case(char **str, t_shell *obj, int indx)
{
	if ((!ft_strncmp("-n", *str, 3) 
	|| ft_strncmp("-n", *str, 3) == -32) 
	&& indx == 1)
	{
		obj->eol = 0;
		return (0);
	}
	if (**str == '$')
	{
		obj->clean = *str;
		if (!(ft_strncmp(*str, "$?", 2)))
		{
			if (obj->status[2])
				*str = ft_itoa(obj->status[2]);
			else
				*str = ft_itoa(obj->status[0]);
		}
		else
			*str = sh_envp_search(*str + 1, *obj);
		free(obj->clean);
		obj->clean = NULL;
	}
	return (1);
}

void	ft_minishell_echo(t_shell *obj, int indx)
{
	int		i;
	char	**tmp;
	int		word;
	int		st;
	i = 0;

	word = 0;
	obj->eol = '\n';
	tmp = ft_split(obj->pipe_block[indx], ' ');
	pipe(obj->fd_pipe);
	if (!(obj->child = fork()))
	{
		dup2(obj->fd_pipe[1], 1);
		close(obj->fd_pipe[0]);
		close(obj->fd_pipe[1]);
		if (!obj->pipe_block[indx + 1])
			dup2(obj->fd_recover[1], 1);
		while (tmp[++i])
		{
			if (word)
				write(1, " ", 1);
			if (!spec_case(&tmp[i], obj, i))
				continue ;
			obj->len = ft_strlen(tmp[i]);
			write(1, tmp[i], obj->len);
			word += obj->len;
		}
		write(1, &obj->eol, 1);
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
		st = (WEXITSTATUS(obj->status[0]) > 0);
		if (st)
			obj->status[0] = WEXITSTATUS(obj->status[0]);
		kill(obj->child, SIGTERM);
	}
	obj->status[2] = 0;
	alloc_free_2((void **)tmp);
}
