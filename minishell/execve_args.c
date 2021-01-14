/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:53 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/14 23:15:51 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char **execve_args(t_shell *obj, int indx)
{
	char	**res;
	int 	size;
	int 	i;

	obj->bin = ft_split(obj->tmp[indx], ' ');
	size = -1;
	while (obj->bin[++size])
		;
	res = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	res[0] = obj->argv[0];
	while (i++ < size)
		res[i] = ft_strdup(obj->bin[i]);
	alloc_free_2((void **)obj->bin);
	return (res);
}
