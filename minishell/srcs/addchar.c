/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:36:42 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:19:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*addchar(char *s, char c)
{
	char	*res;
	int		len[2];

	if (!s)
		return (NULL);
	len[0] = ft_strlen(s) + 2;
	res = (char *)malloc(len[0]);
	len[1] = -1;
	while (s[++len[1]])
		res[len[1]] = s[len[1]];
	res[len[1]++] = c;
	res[len[1]] = 0;
	free(s);
	s = NULL;
	return (res);
}
