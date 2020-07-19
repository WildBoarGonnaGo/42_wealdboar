/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:46:41 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 17:47:59 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

int			ft_char_handle(char **space_info, char value, char space_char[3])
{
	int		sp_number;
	int		sp_total;

	sp_total = 0;
	sp_number = ft_atoi(*space_info);
	sp_total = sp_number - 1;
	if (space_char[1] != '-' && sp_total > 0)
		ft_print_spaces(sp_total, space_char[2]);
	ft_putchar_fd(value, 1);
	if (space_char[1] == '-' && sp_total > 0)
		ft_print_spaces(sp_total, space_char[2]);
	return (1);
}
