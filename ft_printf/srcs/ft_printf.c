/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:14:03 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/20 23:26:41 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf_out.h"

int		ft_printf(const char *strArg, ...)
{
	va_list	char_frwrd;
	int		count;
	int		unit;

	unit = 0;
	count = -1;
	if (!strArg)
		return (0);
	va_start(char_frwrd, strArg);
	while (*(strArg + (++count)))
	{
		if (*(strArg + count) != '%')
			ft_putchar_fd(*(strArg + count), 1);
		else
		{
			++count;
			if ((unit = ft_printf_manager((char *)strArg + count, char_frwrd)) < 0)
				return (-1);
			count += unit;
		}
	}
	va_end(char_frwrd);
	return (0);
}
