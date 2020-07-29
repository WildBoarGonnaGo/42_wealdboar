/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:39:13 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 16:39:45 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

char		*ft_str_toupper(char *str)
{
	int		size;
	char	*str_to_upper;
	int		count;

	count = -1;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(str_to_upper = (char *)malloc(size + 1)))
		return (NULL);
	while (++count < size)
		*(str_to_upper + count) = ft_toupper(*(str + count));
	*(str_to_upper + count) = 0;
	return (str_to_upper);
}
