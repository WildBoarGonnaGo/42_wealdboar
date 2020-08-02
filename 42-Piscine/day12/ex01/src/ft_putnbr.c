/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:00:57 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/13 18:18:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_user_lib.h"

void	ft_putnbr(int num)
{
	if (num == 0)
		ft_putchar('0');
	if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(-1 * num);
	}
	else if (num > 0)
	{
		if (num >= 10)
			ft_putnbr(num / 10);
		ft_putchar((num % 10) + 48);
	}
}
