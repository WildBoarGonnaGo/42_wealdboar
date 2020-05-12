/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:26:53 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/07 23:26:31 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_seek_size(int n)
{
	size_t res;

	res = 0;
	if (n < 0)
		++res;
	while (n != 0)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	size_t	size;
	int		sign;
	char	*res;

	sign = (n < 0) ? -1 : 1;
	if (!n)
	{
		res = (char *)malloc(1);
		*res = 48;
		return (res);
	}
	size = ft_seek_size(n);
	if (!(res = (char *)malloc(size)))
		return (NULL);
	while (size--)
	{
		*(res + size) = n % 10 * sign + 48;
		n /= 10;
		if (!size && sign == -1)
			*res = '-';
	}
	return (res);
}
