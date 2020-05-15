/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:38:47 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 21:37:18 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/12 00:18:52 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

<<<<<<< HEAD
	if ((nmemb * size) < 0)
		return (NULL);
	if (!(dest = malloc(nmemb * size)))
		return (NULL);
	ft_memset(dest, 0, nmemb * size);
=======
	if (!(dest = malloc(nmemb * size)) || nmemb * size > UINT_MAX)
		return (NULL);
	ft_memset(dest, 0, nmemb);
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	return (dest);
}
