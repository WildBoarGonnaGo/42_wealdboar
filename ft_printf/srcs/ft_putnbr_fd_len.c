/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:05:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/21 21:14:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_putnbr_fd_len(int n, int fd, int *len)
{
	long int	buf;

	buf = n;
	if (n < 0)
	{
		buf *= -1;
		ft_putchar_fd('-', fd);
	}
	if (buf >= 10)
	{
		++*len;
		ft_putnbr_fd_len(buf / 10, fd, len);
	}
	ft_putchar_fd(buf % 10 + 48, fd);
}
