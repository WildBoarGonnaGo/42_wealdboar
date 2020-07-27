/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:42:36 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/28 00:32:35 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void		ft_str_info_proc(int *ftstr_info, char *addr_process,
			int *len_res, char space_char[3])
{
	if (ftstr_info[1] < 0 && !ftstr_info[4] && (ftstr_info[2] != -1
	&& ftstr_info[2] < (int)ft_strlen(addr_process)))
		ftstr_info[1] = ftstr_info[0];
	if (space_char[1] == '-' || space_char[2] == '0')
		space_char[2] = ' ';
	if (space_char[1] != '-' && ftstr_info[1] > 0)
		ft_print_spaces(ftstr_info[1], space_char[2], len_res);
	if (ftstr_info[2] == -1 || ftstr_info[2] >= (int)ft_strlen(addr_process))
	{
		ft_putstr_fd(addr_process, 1);
		*len_res += (int)ft_strlen(addr_process);
	}
	else
	{
		if (ftstr_info[4])
			while (++ftstr_info[3] < ftstr_info[2])
				ft_putchar_fd_len(*(addr_process + ftstr_info[3]), 1, len_res);
	}
	if (space_char[1] == '-' && ftstr_info[1] > 0)
		ft_print_spaces(ftstr_info[1], space_char[2], len_res);
}

int			ft_string_handle(char **space_info, char *value,
			char space_char[3], int *len_res)
{
	int		ftstr_info[5];
	char	*addr_process;

	addr_process = value;
	ftstr_info[4] = (!addr_process) ? 0 : 1;
	if (!ftstr_info[4])
		if (!(addr_process = ft_strdup("(null)")))
			return (-1);
	ftstr_info[1] = 0;
	ftstr_info[3] = -1;
	*len_res = 0;
	ftstr_info[0] = ft_atoi(*space_info);
	ftstr_info[2] = (!**(space_info + 2)) ? -1 : ft_atoi(*(space_info + 2));
	ftstr_info[1] = (ftstr_info[2] != -1 &&
	ftstr_info[2] < (int)ft_strlen(addr_process))
	? ftstr_info[0] - ftstr_info[2] : ftstr_info[0] - ft_strlen(addr_process);
	ftstr_info[1] += (!ftstr_info[4] && ft_atoi(*(space_info + 2)) > 0
	&& ftstr_info[2] < 6) ? 1 : 0;
	ft_str_info_proc(ftstr_info, addr_process, len_res, space_char);
	if (!ftstr_info[4])
		ft_mem_reset((void **)&addr_process);
	return (1);
}
