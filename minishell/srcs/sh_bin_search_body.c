/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bin_search_body.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:17:37 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/16 20:41:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_bin_line_check(t_shell *obj, char **line, int st)
{
	if (!st)
	{
		if (!*line)
			*line = ft_strdup(obj->pipe_block[0]);
		alloc_free_2((void ***)&obj->bin);
	}
	else
		*line = ft_strdup(obj->pipe_block[0]);
}

void	sh_cmd_err_output(t_shell *obj)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(obj->bin_search, 2);
	write(2, ": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 1);
}

int		sh_no_bin_found(t_shell *obj, char **line)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(obj->bin_search, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	obj->status[0] = 127;
	sh_free_str(line);
	sh_free_str(&obj->bin_search);
	alloc_free_2((void ***)&obj->bin_args);
	alloc_free_2((void ***)&obj->bin);
	return (obj->status[0]);
}

void	sh_search_bin(t_shell *obj, int i, char **line,
		int pos)
{
	obj->bin = ft_split(obj->envp[pos] + 5, ':');
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
				*line = ft_strdup(obj->bin[i]);
				obj->len = ft_strlen(*line);
				if (*(*line + obj->len - 1) != '/')
					*line = addchar(*line, '/');
				obj->clean = *line;
				*line = ft_strjoin(*line, obj->binary->d_name);
				obj->len = 0;
				free(obj->clean);
				break ;
			}
		}
	}
}
