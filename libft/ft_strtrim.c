/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 12:09:40 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 21:43:17 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/08 14:26:12 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*carr;
	char	*carl;
	char	*dst;

<<<<<<< HEAD
	if (!s1 || !set)
		return (NULL);
=======
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	carl = (char *)s1;
	while (ft_strchr(set, *carl) && *carl)
		++carl;
	carr = (char *)(s1 + ft_strlen(s1));
	while (ft_strrchr(set, *carr) && carr != carl)
		--carr;
	if (!(dst = malloc(carr - carl + 1)))
		return (NULL);
	if (carr == carl)
		ft_bzero(dst, 1);
	else
		dst = ft_substr(s1, carl - s1, carr - carl + 1);
	return (dst);
}
