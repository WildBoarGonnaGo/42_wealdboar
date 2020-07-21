/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_chars_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:08:49 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/20 23:22:08 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_special_chars(char *str_handle, char *spec_chars, int *pos)
{
	spec_chars[0] = 0;
	spec_chars[1] = 0;
	spec_chars[2] = ' ';
	*pos = 0;

	while (*(str_handle + *pos) == '+' || 
	*(str_handle + *pos) == '-' || *(str_handle + *pos) == '0')
	{
		if (*(str_handle + *pos) == '+' && !spec_chars[0]) 
			spec_chars[0] = '+';
		if (*(str_handle  + *pos) == '-' && !spec_chars[1]) 
			spec_chars[1] = '-';
		if (*(str_handle + *pos) == '0' && spec_chars[2] == ' ') 
			spec_chars[2] = '0';
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
