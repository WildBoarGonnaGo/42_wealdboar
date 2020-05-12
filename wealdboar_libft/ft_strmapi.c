/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:33:39 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/09 16:16:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*res;

	if (!f)
		return (NULL);
	size = ft_strlen(s);
	if (!(res = (char *)malloc(size)))
		return (NULL);
	i = -1;
	while (++i < size)
		*(res + i) = f(i, *(char *)(s + i));
	*(res + i) = '\0';
	return (res);
}
