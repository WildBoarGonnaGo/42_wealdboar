/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipe_block_fix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:55:58 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:26:11 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_pipe_block_fix_prep(t_shell *obj,
		int *pos, char ***res)
{
	*pos = -1;
	obj->clean2 = obj->pipe_block;
	while (obj->pipe_block[++*pos])
		;
	*res = (char **)malloc(sizeof(char *) * *pos + 1);
	*pos = -1;
}

char	**sh_pipe_block_fix(t_shell *obj)
{
	int		pos;
	char	**res;

	sh_pipe_block_fix_prep(obj, &pos, &res);
	while (obj->pipe_block[++pos])
	{
		obj->len = ft_strlen(obj->pipe_block[pos]);
		if (ft_strnstr(obj->pipe_block[pos], "\"|\"", obj->len))
			res[pos] = ft_strdup("|");
		else if (!ft_strncmp(obj->pipe_block[pos], "\">\"", 4))
			res[pos] = ft_strdup(">");
		else if (!ft_strncmp(obj->pipe_block[pos], "\"<\"", 4))
			res[pos] = ft_strdup("<");
		else if (!ft_strncmp(obj->pipe_block[pos], "\">>\"", 4))
			res[pos] = ft_strdup(">>");
		else
			res[pos] = ft_strdup(obj->pipe_block[pos]);
	}
	res[pos] = 0x0;
	alloc_free_2((void ***)&obj->clean2);
	return (res);
}
