/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:33:39 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 21:38:08 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/09 16:16:29 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*res;

<<<<<<< HEAD
	if (!f || !s)
		return (NULL);
	size = ft_strlen(s);
	if (!(res = (char *)malloc(size + 1)))
=======
	if (!f)
		return (NULL);
	size = ft_strlen(s);
	if (!(res = (char *)malloc(size)))
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
		return (NULL);
	i = -1;
	while (++i < size)
		*(res + i) = f(i, *(char *)(s + i));
	*(res + i) = '\0';
	return (res);
}
