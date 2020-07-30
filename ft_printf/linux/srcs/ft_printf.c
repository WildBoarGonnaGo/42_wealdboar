/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:14:03 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/31 00:24:19 by lchantel         ###   ########.fr       */
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

int		ft_printf(const char *str_arg, ...)
{
	va_list	char_frwrd;
	int		printf_info[4];

	if (!(ft_err_handle(str_arg)))
		return (-1);
	ft_printf_init(printf_info);
	if (!str_arg)
		return (0);
	va_start(char_frwrd, str_arg);
	while (*(str_arg + (++printf_info[3])))
	{
		if (*(str_arg + printf_info[3]) != '%')
			ft_putchar_fd_len(*(str_arg + printf_info[3]), 1, &printf_info[0]);
		else
		{
			++printf_info[3];
			if ((printf_info[2] = ft_printf_manager((char *)str_arg
			+ printf_info[3], char_frwrd, &printf_info[1])) < 0)
				return (-1);
			printf_info[3] += printf_info[2];
			printf_info[0] += printf_info[1];
		}
	}
	va_end(char_frwrd);
	return (printf_info[0]);
}
