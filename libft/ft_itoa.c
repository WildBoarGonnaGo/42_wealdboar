/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:26:53 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 18:07:54 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/07 23:26:31 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_seek_size(int n)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
}

char			*ft_itoa(int n)
{
	size_t	size;
	int		sign;
	char	*res;

	sign = (n < 0) ? -1 : 1;
<<<<<<< HEAD
	size = ft_seek_size(n) + 1;
	if (!(res = (char *)malloc(size)))
		return (NULL);
	*(res + size--) = '\0';
=======
	if (!n)
	{
		res = (char *)malloc(1);
		*res = 48;
		return (res);
	}
	size = ft_seek_size(n);
	if (!(res = (char *)malloc(size)))
		return (NULL);
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	while (size--)
	{
		*(res + size) = n % 10 * sign + 48;
		n /= 10;
		if (!size && sign == -1)
			*res = '-';
	}
	return (res);
}
