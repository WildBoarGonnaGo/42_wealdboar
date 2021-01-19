/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:55:02 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/19 21:05:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_minishell_export_output(t_shell obj)
{
	char	**tmp;
	int		i;

	tmp = ft_minishell_export_sort(obj.envp);
	obj.len = ft_minishell_export_envplen(obj.envp);
	i = 0;
	while (i < obj.len)
	{
		write(1, "declare -x ", 11);
		write(1, tmp[i], ft_strlen(tmp[i]));
		write(1, "\n", 1);
		free(tmp[i]);
		++i;
	}
	alloc_free_2((void **)tmp);
	return (0);
}

int		ft_minishell_export_check(t_shell *obj)
{
	//char	*var;
	char	*eq_char;
	int		pos[3];

	pos[0] = 0;
	while (obj->cmd[++pos[0]])
	{
		if (check_export_input(obj->cmd[pos[0]], 0, obj->cmd[0]))
		{
			pos[2] = 0;
			pos[1] = -1;
			while (obj->envp_secure[++pos[1]])
			{
				eq_char = ft_strchr(obj->envp_secure[pos[1]], '=');
				(eq_char) ? obj->len = eq_char - obj->envp_secure[1] :
				ft_strlen(obj->envp_secure[1]);
				if (ft_strncmp(obj->envp_secure[pos[1]], obj->cmd[pos[0]], obj->len))
				{
					obj->clean = obj->envp_secure[pos[1]];
					obj->envp_secure[pos[1]] = ft_strdup(obj->cmd[0]);
					free(obj->clean);
					++pos[2];
					break ;
				}
			}
			if (pos[2])
			{
				pos[1] = -1;
				while (obj->envp_secure[++pos[1]])
					;
				obj->envp_secure = (char **)memrealloc((void *)obj->envp_secure, 
				(++pos[1]) * sizeof(char*), sizeof(char *));
				obj->envp_secure[pos[1] - 1] = ft_strdup(obj->cmd[pos[0]]);
				obj->envp_secure[pos[1]] = NULL;
			}
		}
	}
	return (0);
}

void	ft_minishell_export(t_shell *obj, int indx)
{
	int	size;

	size = -1;
	obj->cmd = ft_split(obj->pipe_block[indx], ' ');
	while (obj->cmd[++size])
		;
	if (size > 1)
		ft_minishell_export_check(obj);
	else
		ft_minishell_export_output(*obj);
}
