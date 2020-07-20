/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:42:36 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 17:42:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

int			ft_string_handle(char **space_info, char *value, char space_char[3])
{
	int		sp_number;
	int		sp_total;
	int		skip;
	int		pos;

	sp_total = 0;
	pos = -1;
	sp_number = ft_atoi(*space_info);
	skip = (!**(space_info + 2)) ? -1 : ft_atoi(*(space_info + 2));
	sp_total = (skip != -1 && skip < (int)ft_strlen(value)) ? sp_number - skip :
	sp_number - ft_strlen(value);
	if (space_char[0] == '+' || space_char[2] == '0')
		return (-1);
	if (space_char[1] != '-' && sp_total > 0)
		ft_print_spaces(sp_total, space_char[2]);
	if (skip == -1 || skip > (int)ft_strlen(value))
		ft_putstr_fd(value, 1);
	else
	{
		while (++pos < skip)
			ft_putchar_fd(*(value + pos), 1);
	}
	if (space_char[1] == '-' && sp_total > 0)
		ft_print_spaces(sp_total, space_char[2]);
	return (1);
}