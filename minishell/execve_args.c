/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:53 by wildboarg         #+#    #+#             */
/*   Updated: 2021/02/13 20:43:32 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char **execve_args(t_shell *obj)
{
	char	**res;
	int 	size;
	int 	i;

	//obj->bin = ft_split(obj->pipe_block[indx], ' ');
	size = -1;
	while (obj->pipe_block[++size])
		;
	res = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	res[0] = obj->argv[0];
	while (++i < size)
		res[i] = ft_strdup(obj->pipe_block[i]);
	res[i] = NULL;
	if (obj->pipe_block[0])
		obj->bin_search = ft_strdup(obj->pipe_block[0]);
	alloc_free_2((void **)obj->pipe_block);
	return (res);
}
