/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:57:25 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 21:42:09 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/05 11:53:51 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size[2];

<<<<<<< HEAD
	if (!s1 || !s2)
		return (NULL);
=======
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
	size[0] = ft_strlen(s1) + 1;
	size[1] = ft_strlen(s2) + 1;
	if (!(str = (char *)malloc(size[0] + size[1])))
		return (NULL);
	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	ft_strlcpy(str, s1, size[0]);
	ft_strlcat(str, s2, size[1] + size[0]);
	return (str);
}
