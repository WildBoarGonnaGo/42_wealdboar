/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:06:30 by student           #+#    #+#             */
/*   Updated: 2020/08/02 23:08:21 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_glue(char *between, char *buff, int *flag)
{
	char	*out;
	int		i;
	int		l1;
	int		l2;

	l1 = ft_strlen(between);
	l2 = ft_strlen(buff);
	if (!(out = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
	{
		*flag = -1;
		return (NULL);
	}
	out[l1 + l2] = '\0';
	i = 0;
	while (between && *between)
		out[i++] = *between++;
	while (buff && *buff)
		out[i++] = *buff++;
	return (out);
}
