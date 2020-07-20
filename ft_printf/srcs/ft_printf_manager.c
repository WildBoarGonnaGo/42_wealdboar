/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:11:59 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/20 21:40:36 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

int 	ft_precis_chars(char *str_handle, char ***space, int *pos, va_list list)
{	
	while (ft_isdigit(*(str_handle + *pos)) || *(str_handle + *pos) == '*')
	{
		if (*(str_handle + *pos) == '*')
		{
			if (ft_starfield(*space + 2, list) < 0)
				return (-1);
			++*pos;
			break ;
		}
		*(*space + 1) = *(*space + 2);
		if (!(*(*space + 2) = ft_charjoin(*(*space + 2), *(str_handle + *pos))))
			return (-1);
		ft_mem_reset((void **)(*space + 1));
		++*pos;
	}
	if (!**(*space + 2))
	{
		*(*space + 1) = *(*space + 2);
		if (!(*(*space + 2) = ft_charjoin(*(*space + 2), '0')))
			return (-1);
		ft_mem_reset((void **)(*space + 1)); 
	}
	return (1);
}

int		ft_width_chars(char *str_handle, char ***space, int *pos, va_list list)
{
	while (ft_isdigit(*(str_handle + *pos)) || *(str_handle + *pos) == '*')
	{
		if (*(str_handle + *pos) == '*')
		{
			if (ft_starfield(*space, list) < 0)
				return (-1);
			++*pos;
			break ;
		}
		*(*space + 1) = **space;
		if (!(**space = ft_charjoin(**space, *(str_handle + *pos))))
			return (-1);
		ft_mem_reset((void **)(*space + 1));
		++*pos;
	}
	if (!***space)
	{
		*(*space + 1) = **space;
		if (!(**space = ft_charjoin(**space, '0')))
			return (-1);
		ft_mem_reset((void **)(*space + 1));
	}
	return (1);
}

int		ft_data_process(char **space, va_list list, char space_char[3])
{
	int status;

	status = 1;
	if (*space[1] == 'd' || *space[1] == 'i' || *space[1] == 'u')
		status = ft_integer_handle(space, va_arg(list, int), space_char);
	else if (*space[1] == 's')
		status = ft_string_handle(space, va_arg(list, char *), space_char);
	else if (*space[1] == 'c')
		status = ft_char_handle(space, va_arg(list, int), space_char);
	else if (*space[1] == 'p' || *space[1] == 'x' || *space[1] == 'X')
		status = ft_hexadec_handle(space, va_arg(list, int), space_char);
	else if (*space[1] == '%')
		ft_putchar_fd('%', 1);
	return (status);
}

int		ft_printf_manager(char *str_handle, va_list list)
{
	int		pos;
	char	space_char[3];
	char	**space;

	if (!str_handle || !(space = (char **)malloc(sizeof(char *) * 3)))
		return (-1);
	if (!(space[0] = ft_strdup("")) || !(space[2] = ft_strdup("")))
		return (-1);
	ft_special_chars_1(str_handle, &space_char[0], &space_char[1], &pos);
	ft_special_chars_2(str_handle, &space_char[2], &pos);
	if (ft_width_chars(str_handle, &space, &pos, list) < 0)
		return (-1);
	if (*(str_handle + pos) == '.')
	{
		++pos;
		space_char[2] = ' ';
		if (ft_precis_chars(str_handle, &space, &pos, list) < 0)
			return (-1);
	}
	space[1] = str_handle + pos;
	if (ft_data_process(space, list, space_char) < 0)
		return (-1);
	ft_mem_reset_arg(3, (void **)&space[0], (void **)&space[2], (void **)space);
	return (pos);
}
