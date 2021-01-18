/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:55:02 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/18 23:28:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_minishell_export_add(char *str, char ***envp);

//int	ft_minishell_export_set();

int		ft_minishell_export_output(t_shell obj)
{
	char	**tmp;
	int		i;
	int		len;

	tmp = ft_minishell_export_sort(obj.envp);
	obj.len = ft_minishell_export_envplen(obj.envp);
	i = 0;
	while (i < len)
	{
		write(1, "declare -x ", 11);
		write(1, tmp[i], ft_strlen(tmp[i]));
		write(1, "\n", 1);
		free(tmp[i]);
		++i;
	}
	free(tmp);
	return (0);
}

static int	ft_minishell_export_check(t_shell *obj)
{
	char	*var;
	char	*eq_char;
	int		pos[2];

	pos[0] = 0;
	while (obj->cmd[++pos[0]])
	{
		if (check_export_input(obj->cmd[pos[0]], 0))
		{
			pos[1] = -1;
			while (++pos[1])
			{
				eq_char = ft_strchr(obj->envp_secure[pos[1]], '=');
				if (ft_strncmp())
				obj->envp_secure[i] = ft_minishell_getvar(char *str) 
			}
			
		}
	}
}

void	ft_minishell_export(t_shell *obj, int indx)
{
	int	size;

	size = -1;
	obj->cmd = ft_split(obj->pipe_block[indx], ' ');
	while (obj->cmd[++size])
		;
	if (size >= 2)
		ft_minishell_export_check(obj);
	else
		ft_minishell_export_output(*obj);
}
