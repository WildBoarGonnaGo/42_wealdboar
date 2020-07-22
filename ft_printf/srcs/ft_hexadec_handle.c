/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:50:52 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/22 05:49:30 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

int			ft_stdout_hex(char space_char[3], int sp_info[4], char **str_value,
			char **space_info)
{
	int	len_res;

	len_res = 0;
	if (space_char[1] != '-' && sp_info[3] > 0)
		ft_print_spaces(sp_info[3], space_char[2], &len_res);
	if ((sp_info[1] -= sp_info[2]) > 0)
		ft_print_spaces(sp_info[1], '0', &len_res);
	if (**(space_info + 1) == 'X')
		str_value[0] = ft_str_toupper(str_value[0]);
	if (**(space_info + 1) == 'p')
	{
		ft_putstr_fd("0x", 1);
		len_res += 2;
	}
	if (**(space_info + 2) != 48 || ft_strncmp((const char *)*str_value, "0", 2))
	{
		ft_putstr_fd(str_value[0], 1);
		len_res += ft_strlen(str_value[0]);
	}
	if (space_char[1] == '-' && sp_info[3] > 0)
		ft_print_spaces(sp_info[3], space_char[2], &len_res);
	return (len_res);
}

int			ft_hexadec_handle(char **space_info, int value, char space_char[3], int *len_res)
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
	sp_info[3] += (value && **(space_info + 2) != 48) ? 0 : 1;
	str_value[1] = str_value[0];
	*len_res = ft_stdout_hex(space_char, sp_info, str_value, space_info);
	if (str_value[1] != str_value[0])
		ft_mem_reset((void **)&str_value[1]);
	ft_mem_reset((void **)&str_value[0]);
	ft_mem_reset((void **)str_value);
	return (1);
}
