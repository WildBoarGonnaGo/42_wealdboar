/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:53 by wildboarg         #+#    #+#             */
/*   Updated: 2021/03/14 03:20:28 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**execve_args(t_shell *obj)
{
	char	**res;
	int		size;
	int		i;

	size = -1;
	while (obj->pipe_block[++size])
		;
	res = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	res[0] = ft_strdup(obj->argv[0]);
	while (++i < size)
		res[i] = ft_strdup(obj->pipe_block[i]);
	res[i] = NULL;
	if (obj->pipe_block[0])
		obj->bin_search = ft_strdup(obj->pipe_block[0]);
	return (res);
}
