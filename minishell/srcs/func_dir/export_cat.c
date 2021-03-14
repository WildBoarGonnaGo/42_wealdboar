/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:58:08 by dalonso           #+#    #+#             */
/*   Updated: 2021/03/14 05:01:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cat_ft_m_export_check(int *pos, char *eq_char, t_shell *obj)
{
	pos[1] = -1;
	while (obj->envp[++pos[1]])
	{
		eq_char = ft_strchr(obj->envp[pos[1]], '=');
		(eq_char) ? obj->len = eq_char - obj->envp[pos[1]] :
		ft_strlen(obj->envp[pos[1]]);
		if (!ft_strncmp(obj->envp[pos[1]], obj->cmd[pos[0]], obj->len))
		{
			if (ft_strchr(obj->cmd[pos[0]], '='))
			{
				obj->clean = obj->envp[pos[1]];
				obj->envp[pos[1]] = ft_strdup(obj->cmd[pos[0]]);
				free(obj->clean);
			}
			break ;
		}
	}
	if (pos[1] == pos[2])
	{
		obj->envp = (char **)memrealloc((void *)obj->envp,
		(++pos[1]) * sizeof(char*), sizeof(char *));
		obj->envp[pos[1] - 1] = ft_strdup(obj->cmd[pos[0]]);
		obj->envp[pos[1]] = NULL;
	}
}
