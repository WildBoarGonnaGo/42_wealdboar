/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ignore_colon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:02:20 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:23:45 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*sh_ignore_colon(char *str)
{
	int		info[3];
	char	*res;

	info[0] = -1;
	res = ft_strdup("");
	info[1] = 0;
	while (str[++info[0]])
	{
		if (str[info[0]] == '\"' && !info[1])
			continue ;
		res = addchar(res, str[info[0]]);
	}
	return (res);
}
