/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:26:43 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/12 04:02:41 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/07 07:22:28 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		status;
	char		*pos;
	size_t		carr;

	carr = 0;
<<<<<<< HEAD
	if (!len && !big)
=======
	if (!len)
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (carr < len)
	{
		if (*(big + carr) == *little)
		{
			pos = (char *)(big + carr);
			status = ft_memcmp(pos, little, ft_strlen(little));
			if (!status && (carr + ft_strlen(little) <= len))
				return (pos);
		}
		++carr;
	}
	return (NULL);
}
