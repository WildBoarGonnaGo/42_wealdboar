/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:03:43 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/29 21:10:33 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

int	ft_prcnt_case(const char *src, int *pos)
{
	++*pos;
	while (ft_strchr("-+0", *(src + *pos)) && *(src + *pos))
		++*pos;
	while (ft_strchr("1234567890*", *(src + *pos)) && *(src + *pos))
		++*pos;
	if (*(src + *pos) == '.')
	{
		++*pos;
		while (ft_strchr("1234567890*", *(src + *pos)) && *(src + *pos))
			++*pos;
	}
	if (!ft_strchr("cspdiuxX%", *(src + *pos)) || !*(src + *pos))
		return (0);
	++*pos;
	return (1);
}

int	ft_err_handle(const char *src)
{
	int	pos;

	pos = 0;
	while (*(src + pos))
	{
		if (*(src + pos) != '%')
			++pos;
		else
		{
			if (!(ft_prcnt_case(src, &pos)))
				return (0);
		}
	}
	return (1);
}
