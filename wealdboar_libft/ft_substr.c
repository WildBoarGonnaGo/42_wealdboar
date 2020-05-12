/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 05:06:53 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/06 15:06:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pos;
	size_t	i;

	i = 0;
	if (!(pos = (char *)malloc(len)) || start > ft_strlen(s))
		return (NULL);
	while (len-- > 0)
		*(pos + i++) = *(s + start++);
	return (pos);
}
