/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 12:09:40 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/17 20:34:37 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*carr;
	char	*carl;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	carl = (char *)s1;
	while (ft_strchr(set, *carl) && *carl)
		++carl;
	carr = (char *)(s1 + ft_strlen(s1));
	while (ft_strrchr(set, *carr) && carr != carl)
		--carr;
	dst = ft_substr(s1, carl - s1, carr - carl + 1);
	return (dst);
}
