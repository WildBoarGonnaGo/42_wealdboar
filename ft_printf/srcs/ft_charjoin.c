/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 23:28:25 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 23:30:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

char		*ft_charjoin(char *str, char c)
{
	char	*new_str;
	int		pos;
	int		move;

	move = -1;
	if (!str)
		return (NULL);
	pos = ft_strlen(str);
	if (!(new_str = (char *)malloc(pos + 2)))
		return (NULL);
	while (++move < pos)
		*(new_str + move) = *(str + move);
	*(new_str + move++) = c;
	*(new_str + move) = 0;
	return (new_str);
}
