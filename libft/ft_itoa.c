/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:26:53 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/14 18:07:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_seek_size(int n)
{
	size_t		res;
	long int	buf;

	res = 0;
	buf = n;
	if (buf < 0)
	{
		++res;
		buf *= -1;
	}
	while (buf >= 10)
	{
		buf /= 10;
		++res;
	}
	return (++res);
}

char			*ft_itoa(int n)
{
	size_t	size;
	int		sign;
	char	*res;

	sign = (n < 0) ? -1 : 1;
	size = ft_seek_size(n) + 1;
	if (!(res = (char *)malloc(size)))
		return (NULL);
	*(res + size--) = '\0';
	while (size--)
	{
		*(res + size) = n % 10 * sign + 48;
		n /= 10;
		if (!size && sign == -1)
			*res = '-';
	}
	return (res);
}
