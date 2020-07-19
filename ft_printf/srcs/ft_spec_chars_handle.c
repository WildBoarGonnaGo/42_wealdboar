/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_chars_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:08:49 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 22:32:35 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_special_chars_1(char *str_handle, char *sign_plus, char *sign_minus, int *pos)
{
	*sign_plus = 0;
	*sign_minus = 0;
	*pos = 0;

	while (*(str_handle + *pos) == '+' || 
	*(str_handle + *pos) == '-')
	{
		if (*(str_handle + *pos) == '+' && !*sign_plus) 
			*sign_plus = '+';
		if (*(str_handle  + *pos) == '-' && !*sign_minus) 
			*sign_minus = '-';
		++*pos;
	}
}

void	ft_special_chars_2(char *str_handle, char *sign_zero, int *pos)
{
	*sign_zero = ' ';

	while (*(str_handle + *pos) == '0')
	{
		if (*(str_handle + *pos) == '0' && *sign_zero == ' ') 
			*sign_zero = '0';
		++*pos;
	}	
}

int 	ft_starfield(char **str, va_list list)
{
	char	*str_to_purge;

	str_to_purge = *str;
	if (!(*str = ft_itoa(va_arg(list, int))))
		return (-1);
	ft_mem_reset((void **)&str_to_purge);
	return (0);
}
