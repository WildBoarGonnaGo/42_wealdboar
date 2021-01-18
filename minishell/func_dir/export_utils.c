/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:00:49 by lcreola           #+#    #+#             */
/*   Updated: 2021/01/18 15:21:28 by wildboarg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_getvar_input(char *str, int count)
{
	if (ft_isdigit(*str) && *str && !count)
		return (0);
	else if (ft_strchr("!@#%^&*)(", *str) && *str
	&&count)
		return (0);
	else if (*str)
		return (check_getvar_input(++str, ++count));
	return (1);
}

char	*ft_minishell_getvar(char *str)
{
	char	*var;
	int		equal;

	equal = 0;
	if (!(check_getvar_input(str, 0)))
	{
		write(2, "minishell: export: ",
		ft_strlen("minishell: export: "));
		write(2, str, ft_strlen(str));
		write(2. "\n", 1);
		return (NULL);
	}
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
	i = -1;
	if (!(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (++i < len)
		res[i] = ft_strdup(envp[i]);
	res[len] = NULL;
	i = 0;
	while (res[i])
	{
		len = i;
		while (res[len + 1])
		{
			if (ft_strncmp(res[i], res[len + 1], ft_strlen(res[i])) > 0)
				ft_minishell_export_swap(&res[i], &res[len + 1]);
			++len;
		}
		++i;
	}
	return (res);
}
