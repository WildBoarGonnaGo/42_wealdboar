/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_ansys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:43 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/08 22:07:39 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void sh_line_ansys(t_shell *obj)
{
	int		i;

	i = -1;	
	obj->tmp = ft_split(obj->line, ';');
	while (obj->tmp[++i])
	{
		obj->len = ft_strlen(obj->tmp[i]) + 1;
		if (!ft_strncmp("pwd", obj->tmp[i], obj->len) ||
		ft_strncmp("pwd", obj->tmp[i], 5) == -32)
			ft_minishell_pwd();
		else if (!ft_strncmp("echo", obj->tmp[i], 5) ||
		ft_strncmp("echo", obj->tmp[i], 5) == -32)
			ft_minishell_echo(obj, i);
		else if (!ft_strncmp("env", obj->tmp[i], obj->len) ||
		ft_strncmp("env", obj->tmp[i], 5) == -32)
			ft_minishell_env(*obj);
	}
	alloc_free_2((void **)obj->tmp);
}
