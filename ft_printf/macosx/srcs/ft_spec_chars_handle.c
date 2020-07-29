/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_chars_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:08:49 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/28 01:14:58 by lchantel         ###   ########.fr       */
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
		if (*(str_handle + *pos) == '-' && !spec_chars[1])
			spec_chars[1] = '-';
		if (*(str_handle + *pos) == '0' && spec_chars[2] == ' ')
			spec_chars[2] = '0';
		++*pos;
	}
}

int		ft_starfield(char **str, va_list list)
{
	char	*str_to_purge;
	int		field_range;
	int		status;

	status = 0;
	if ((field_range = va_arg(list, int)) < 0)
	{
		field_range *= -1;
		status = 1;
	}
	str_to_purge = *str;
	if (!(*str = ft_itoa(field_range)))
		return (-1);
	ft_mem_reset((void **)&str_to_purge);
	return (status);
}

int		ft_str_zerofic(char ***space, int num)
{
	*(*space + 1) = *(*space + num);
	if (!(*(*space + num) = ft_charjoin(*(*space + num), '0')))
		return (-1);
	ft_mem_reset((void **)(*space + 1));
	return (0);
}
