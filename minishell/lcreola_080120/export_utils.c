/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:00:49 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/06 21:05:13 by lcreola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_minishell_getvar(char *str)
{
	char	*var;
	int		equal;

	equal = 0;
	while (str[equal] != '=')
		++equal;
	var = ft_substr(str, 0, equal);
	return (var);
}

void	ft_minishell_export_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = ft_strdup(*str2);
	free(*str2);
	*str2 = ft_strdup(*str1);
	free(*str1);
	*str1 = ft_strdup(tmp);
	free(tmp);
}

int		ft_minishell_export_envplen(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		++i;
	return (i);
}

char	**ft_minishell_export_sort(char **envp)
{
	char	**res;
	int		len;
	int		i;

	len = ft_minishell_export_envplen(envp);
	i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (len + 1))))
		ft_errors(1);
	while (i < len)
	{
		res[i] = malloc(ft_strlen(envp[i] + 1));
		res[i] = ft_strcpy(res[i], envp[i]);
		++i;
	}
	res[len] = NULL;
	i = 0;
	while (res[i])
	{
		len = i;
		while (res[len + 1])
		{
			if (ft_strcmp(res[i], res[len + 1]) > 0)
				ft_minishell_export_swap(&res[i], &res[len + 1]);
			++len;
		}
		++i;
	}
	return (res);
}
