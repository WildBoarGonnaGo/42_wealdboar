/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:28:03 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/13 22:43:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_user_lib.h"

int	ft_err_output(int err_num, char *str)
{
	int state;

	state = 1;
	if (err_num == 2)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		state = 0;
	}
	if (err_num == 21)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(str);
		ft_putstr(": Is a directory\n");
		state = 0;
	}
	if (err_num == 13)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(str);
		ft_putstr(": Permission denied\n");
		state = 0;
	}
	return (state);
}
