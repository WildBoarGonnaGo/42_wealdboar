/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:28:01 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/04 03:30:32 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res[2];

	res[0] = 0;
	res[1] = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		++nptr;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			res[1] = -1;
		++nptr;
	}
	while (*nptr == '0')
		++nptr;
	while (ft_isdigit(*nptr))
	{
		res[0] *= 10;
		res[0] += *nptr - '0';
		++nptr;
	}
	return (res[0] * res[1]);
}
