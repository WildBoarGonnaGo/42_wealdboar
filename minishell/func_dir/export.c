/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:55:02 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/18 15:51:53 by wildboarg        ###   ########.fr       */
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
	obj->len = ft_minishell_export_envplen(obj.envp);
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

static int	ft_minishell_export_check(t_shell *obj, int indx)
{
	char	*var;
	int		i;
	int		j;

	j = 0;
	if ((var = ft_minishell_getvar(obj->pipe_block[indx])))
	{
		i = ft_strlen(var);
		while ((*envp)[j] && (j < i))
		{
			if (ft_minishell_export_set())
				break ;
		}
		if (!(*envp)[j])
			(*envp) = ft_minishell_export_add(ft_strdup((*argv)), envp);
		if (argv[1])
			ft_minishell_export(&argv[1], envp);
	}
	else
	{
		ft_minishell_export_set(&argv[1], envp);
		return (0);
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
	if (size >= 2)
		ft_minishell_export_check(obj);
	else
		ft_minishell_export_output(*obj);
	return (0);
}
