/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envp_dupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:28:30 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:22:16 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**sh_envp_dupl(t_shell obj)
{
	int		size;
	char	**res;

	size = -1;
	while (obj.envp[++size])
		;
	res = (char **)malloc(sizeof(char *) * size + 1);
	size = -1;
	while (obj.envp[++size])
		res[size] = ft_strdup(obj.envp[size]);
	res[size] = NULL;
	return (res);
}
