/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 05:06:53 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 21:41:36 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/06 15:06:57 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pos;
	size_t	i;

	i = 0;
<<<<<<< HEAD
	if (!s)
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!(pos = (char *)malloc(len + 1)) || start > ft_strlen(s))
		return (NULL);
	while (len-- > 0)
		*(pos + i++) = *(s + start++);
	*(pos + i) = '\0';
=======
	if (!(pos = (char *)malloc(len)) || start > ft_strlen(s))
		return (NULL);
	while (len-- > 0)
		*(pos + i++) = *(s + start++);
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	return (pos);
}
