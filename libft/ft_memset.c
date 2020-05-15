/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:45:49 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/12 02:50:19 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/08 14:40:47 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*pos;

<<<<<<< HEAD
=======
	if (!s)
		return (NULL);
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	pos = s;
	while (n-- > 0)
		*((unsigned char *)(pos++)) = (unsigned char)c;
	return (s);
}
