/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 06:44:09 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 21:39:36 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/07 12:37:16 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;
	const char	*src_start;

	src_start = src;
	len = size;
<<<<<<< HEAD
	if (!dst || !src)
		return (NULL);
=======
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	if (len)
		while (--len)
			if ((*(dst++) = *(src++)) == '\0')
				break ;
	if (!len)
	{
		if (size)
			*dst = '\0';
		while (*(src++) != '\0')
			;
	}
	return (src - src_start - 1);
}
