/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_set_arr2_strbound.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:36:32 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 04:59:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**set_arr2_strbound(char **arr, int *pos,
		char *str, t_shell *obj)
{
	char	**res;
	int		info[3];

	*pos = (*pos != -1) * *pos - (*pos == -1);
	info[0] = *pos;
	while (arr[++*pos])
	{
		if (!ft_strncmp(str, arr[*pos], ft_strlen(str)))
			break ;
	}
	info[1] = *pos - info[0] * (info[0] != -1);
	res = (char **)malloc(sizeof(char *) * (info[1] + 1));
	info[2] = -1;
	while (++info[0] < *pos)
	{
		if (!sh_redirects(obj, &info[0]))
			res[++info[2]] = ft_strdup(arr[info[0]]);
		if (obj->err_fd[0])
			break ;
	}
	res[++info[2]] = 0x0;
	return (res);
}
