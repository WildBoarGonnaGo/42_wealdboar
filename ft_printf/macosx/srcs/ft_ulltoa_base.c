/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:07:11 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/28 01:17:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/libft_expand.h"

unsigned long long	ft_ull_get_size_base(unsigned long long num,
					unsigned long long base)
{
	unsigned long long	size;

	size = 0;
	while ((num /= base) > 0)
		++size;
	return (++size);
}

char				ull_remind_to_base(unsigned long long val_to_write)
{
	if (val_to_write < 10)
		return (val_to_write + '0');
	else
		return (val_to_write + 'a' - 10);
}

char				*ft_ulltoa_base(unsigned long long num,
					unsigned long long base)
{
	char					*result;
	unsigned long long		func_info[3];

	func_info[1] = 1;
	if (!num)
		return (ft_strdup("0"));
	func_info[0] = ft_ull_get_size_base(num, base);
	if (!(result = (char *)malloc(func_info[0] + 1)))
		return (NULL);
	*(result + func_info[0]) = 0;
	num *= func_info[1];
	while (func_info[0]-- > 0)
	{
		func_info[2] = num % base;
		num /= base;
		*(result + func_info[0]) = ull_remind_to_base(func_info[2]);
	}
	return (result);
}
