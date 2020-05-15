/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 09:31:27 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 16:00:39 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
=======
/*   Updated: 2020/05/12 01:52:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*func_dest;
	unsigned char	*func_orig;
<<<<<<< HEAD
	size_t			i;

	func_dest = (unsigned char *)s1;
	func_orig = (unsigned char *)s2;
	if (!s1 && !s2 && n)
		return (NULL);
	if (s1 > s2)
	{
		i = 0;
		while (++i <= n)
			*(func_dest + n - i) = *(func_orig + n - i);
	}
	else
	{
		i = -1;
		while (++i < n)
			*(func_dest + i) = *(func_orig + i);
	}
	return (func_dest);
=======
	unsigned char	buffer[n];
	size_t			i;

	func_orig = (unsigned char *)s2;
	func_dest = (unsigned char *)s1;
	i = -1;
	if (!n || s1 == s2)
		return (s1);
	while (++i < n)
		*(buffer + i) = *(func_orig + i);
	i = -1;
	while (++i < n)
		*(func_dest + i) = *(buffer + i);
	return (s1);
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
}
