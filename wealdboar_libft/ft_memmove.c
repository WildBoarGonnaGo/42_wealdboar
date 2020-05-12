/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 09:31:27 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/12 01:52:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*func_dest;
	unsigned char	*func_orig;
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
}
