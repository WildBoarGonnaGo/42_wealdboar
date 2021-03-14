/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envp_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:47:49 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:22:24 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*sh_envp_search(const char *str, t_shell *obj)
{
	char	*res;
	char	*alloc_free;
	int		i;

	i = -1;
	res = ft_strdup("");
	obj->len = ft_strlen(str) + 1;
	obj->env_is_home = (!(ft_strncmp("HOME", str, 5)));
	while (obj->envp[++i])
	{
		if (!ft_strncmp(str, obj->envp[i], obj->len) ||
		ft_strncmp(str, obj->envp[i], obj->len) == -61)
		{
			alloc_free = res;
			res = ft_strdup(obj->envp[i] + obj->len);
			free(alloc_free);
			alloc_free = NULL;
			break ;
		}
	}
	return (res);
}
