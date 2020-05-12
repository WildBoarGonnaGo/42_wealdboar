/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:45:49 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/08 14:40:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*pos;

	if (!s)
		return (NULL);
	pos = s;
	while (n-- > 0)
		*((unsigned char *)(pos++)) = (unsigned char)c;
	return (s);
}
