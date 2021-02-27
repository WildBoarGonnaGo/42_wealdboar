/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ignore_colon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:02:20 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/27 20:21:01 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char	*sh_ignore_colon(char *str, char *colon_pos)
{
	int		info[3]
	char	*res;

	info[0] = -1;
	res = ft_strdup("");
	st = 0;
	while (str[++info[0]])
	{
		if (str[info[0]] == '\'' && !st)
			continue ;
		if (str[info[0]] == ' ')
			st = (st == DQUOTE) ? st | DQUOTE : st & ~DQUOTE;
		res = addchar(res, str[i]);
	}
	return (res);
}

