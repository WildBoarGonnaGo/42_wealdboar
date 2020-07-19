/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:50:52 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 18:00:31 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		ft_stdout_hex(char space_char[3], int space_info[4], char **str_value,
			char **space_info)
{
	if (space_char[1] != '-' && sp_info[3] > 0)
		ft_print_spaces(sp_info[3], space_char[2]);
	if ((sp_info[1] -= sp_info[2]) > 0)
		ft_print_spaces(sp_info[1], '0');
	if (**(space_info + 1) == 'X')
		str_value[0] = ft_str_toupper(str_value[0]);
	if (**(space_info + 1) == 'p')
		ft_putstr_fd("0x", 1);
	ft_putstr_fd(str_value[0], 1);
	if (space_char[1] == '-' && sp_info[3] > 0)
		ft_print_spaces(sp_info[3], space_char[2]);
}

int			ft_hexadec_handle(char **space_info, int value, char space_char[3])
{
	int		sp_info[4];
	char	**str_value;
	
	if (!(str_value = (char **)malloc(sizeof(char *) * 2)))
		return (-1);
	sp_info[3] = 0;
	sp_info[0] = ft_atoi(*space_info);
	sp_info[1] = (!**(space_info + 2) || **(space_info + 2) == '0') ? 0 : ft_atoi(*(space_info + 2));
	if (!(str_value[0] = ft_itoa_base((unsigned int)value, 16)))
		return (-1);
	sp_info[2] = ft_strlen(str_value[0]);
	if (space_char[0] == '-' && space_char[1] == '0')
		space_char[1] = ' ';
	sp_info[3] = (sp_info[1] - sp_info[2] > 0) ? sp_info[0] - sp_info[1] : sp_info[0] - sp_info[2];
	sp_info[3] -= (**(space_info + 1) == 'p') ? 2 : 0;
	str_value[1] = str_value[0];
	if (str_value[1] != str_value[0])
		ft_mem_reset((void **)&str_value[1]);
	ft_mem_reset((void **)&str_value[0]);
	ft_mem_reset((void **)str_value);
	return (1);
}
