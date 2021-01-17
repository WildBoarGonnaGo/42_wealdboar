/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:55:02 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/06 21:00:27 by lcreola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**ft_minishell_export_add(char *str, char ***envp);

static int	ft_minishell_export_set();

static int	ft_minishell_export_output(char **envp)
{
	char	**tmp;
	int		i;
	int		len;

	tmp = ft_minishell_export_sort(envp);
	len = ft_minishell_export_envplen(envp);
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

static int	ft_minishell_export_check(char **argv, char **envp)
{
	char	*var;
	int		i;
	int		j;

	j = 0;
	if (var = ft_minishell_getvar(*argv))
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

void	ft_minishell_export(char **argv, char **envp)
{
	if (*argv)
		ft_minishell_export_check(argv, envp);
	else
		ft_minishell_export_output(envp);
	return (0);
}
