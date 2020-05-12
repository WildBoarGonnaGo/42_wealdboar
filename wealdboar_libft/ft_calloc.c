/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:38:47 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/12 00:18:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (!(dest = malloc(nmemb * size)) || nmemb * size > UINT_MAX)
		return (NULL);
	ft_memset(dest, 0, nmemb);
	return (dest);
}
