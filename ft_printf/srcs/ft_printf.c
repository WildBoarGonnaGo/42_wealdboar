/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:14:03 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/27 22:29:36 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_printf_init(int *printf_info)
{
	printf_info[0] = 0;
	printf_info[1] = 0;
	printf_info[2] = 0;
	printf_info[3] = -1;
}

int		ft_printf(const char *strArg, ...)
{
	va_list	char_frwrd;
	int		printf_info[4];

	ft_printf_init(printf_info);
	if (!strArg)
		return (0);
	va_start(char_frwrd, strArg);
	while (*(strArg + (++printf_info[3])))
	{
		if (*(strArg + printf_info[3]) != '%')
			ft_putchar_fd_len(*(strArg + printf_info[3]), 1, &printf_info[0]);
		else
		{
			++printf_info[3];
			if ((printf_info[2] = ft_printf_manager((char *)strArg + printf_info[3], 
			char_frwrd, &printf_info[1])) < 0)
				return (-1);
			printf_info[3] += printf_info[2];
			printf_info[0] += printf_info[1];
		}
	}
	va_end(char_frwrd);
	return (printf_info[0]);
}
