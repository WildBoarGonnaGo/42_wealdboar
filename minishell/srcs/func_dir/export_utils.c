/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:00:49 by lcreola           #+#    #+#             */
/*   Updated: 2021/03/14 05:01:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	err_identifier_output(char *str, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int		check_export_input(char *str, int count, char *cmd, int bit_eq)
{
	if (!count && !ft_strncmp("", str, 1))
	{
		err_identifier_output(str, cmd);
		return (0);
	}
	if (ft_isdigit(*(str + count)) && *(str + count) && !count)
	{
		err_identifier_output(str, cmd);
		return (0);
	}
	else if (((ft_strchr("!@#%^&*)(+-", *(str + count)) && !bit_eq) ||
	(!ft_strncmp("unset", cmd, ft_strlen(cmd) - 1) && *(str + count) == '='))
	&& *(str + count))
	{
		err_identifier_output(str, cmd);
		return (0);
	}
	else if (*(str + count))
	{
		if (*(str + count) == '=')
			++bit_eq;
		return (check_export_input(str, ++count, cmd, bit_eq));
	}
	return (1);
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
