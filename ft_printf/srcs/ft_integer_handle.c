/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:04:29 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 23:35:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_stdout_int(char space_char[3], char **space_info, int value, 
		int sp_total_info[4])
{
	if (space_char[0] == '+' && space_char[2] == '0' && value > 0)
		ft_putchar_fd('+', 1);
	if (sp_total_info[0]  > 0 && space_char[1] != '-')
		ft_print_spaces(sp_total_info[0], space_char[2]);
	if (space_char[0] == '+' && space_char[2] == ' ' && value > 0)
		ft_putchar_fd('+', 1);
	if (value < 0 && space_char[2] == ' ' && **(space_info + 1) != 'u')
		ft_putchar_fd('-', 1);
	if ((sp_total_info[3] -= sp_total_info[2]) > 0)
		ft_print_spaces(sp_total_info[3], '0');
	if (**(space_info + 1) != 'u')
		ft_putnbr_fd(sp_total_info[1], 1);
	else
		ft_putunbr_fd((unsigned int)value, 1);
	if (sp_total_info[0] > 0 && space_char[1] == '-')
		ft_print_spaces(sp_total_info[0], space_char[2]);
}

int		ft_integer_handle(char **space_info, int value, char space_char[3])
{
	char	*str_value;
	int		sp_number;
	int		sp_total_info[4];

	sp_total_info[0] = (space_char[0] == '+' && value > 0) ? -1 : 0;
	sp_total_info[1] = value;
	if ((value < 0 && **(space_info + 1) == 'd') || (value < 0 && **(space_info + 1) == 'i'))
	{
		if (space_char[2] != ' ')
			ft_putchar_fd('-', 1);	
		sp_total_info[1] *= -1;
		sp_total_info[0] = -1;
	}
	sp_number = ft_atoi(*space_info);
	sp_total_info[3] = (!**(space_info + 2)) ? 0 : ft_atoi(*(space_info + 2));
	str_value = (**(space_info + 1) != 'u') ? ft_itoa(sp_total_info[1]) : ft_utoa((unsigned int)value);
	if (!str_value)
		return (-1);	
	sp_total_info[2] = ft_strlen(str_value);
	sp_total_info[0] += ((sp_total_info[3] - sp_total_info[2]) > 0) ? sp_number - sp_total_info[3] 
	: sp_number - sp_total_info[2];
	ft_stdout_int(space_char, space_info, value, sp_total_info);
	ft_mem_reset((void **)&str_value);
	return (1);
}
