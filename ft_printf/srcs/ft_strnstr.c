/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:26:43 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/11 21:26:35 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		status;
	char		*pos;
	size_t		carr;

	carr = 0;
	if (!len && !big)
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
