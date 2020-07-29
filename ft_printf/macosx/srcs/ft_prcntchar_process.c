/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcntchar_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 03:46:39 by wealdboar         #+#    #+#             */
/*   Updated: 2020/07/29 04:58:09 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

int	ft_prcntchar_process(char **space_info, char space_char[3], int *len_res)
{
	int	space_num;

	space_num = ft_atoi(*space_info) - 1;
	if (space_char[1] != '-' && space_num > 0)
		ft_print_spaces(space_num, space_char[2], len_res);
	ft_putchar_fd_len('%', 1, len_res);
	if (space_char[1] == '-' && space_num > 0)
		ft_print_spaces(space_num, space_char[2], len_res);
	return (1);
}
