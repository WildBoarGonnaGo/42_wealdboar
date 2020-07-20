/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:03:30 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 16:08:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

static int	ft_getnumsize(long n)
{
	int size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++size;
	}
	while (n /= 10)
		++size;
	return (++size);
}

char		*ft_utoa(unsigned int n)
{
	long	val;
	int		size;
	char	*res;

	val = n;
	size = ft_getnumsize(val);
	if (!(res = (char *)malloc(size + 1)))
		return (0);
	*(res + size--) = '\0';
	while (size >= 0)
	{
		*(res + size) = val % 10 + 48;
		val /= 10;
		--size;
	}
	return (res);
}