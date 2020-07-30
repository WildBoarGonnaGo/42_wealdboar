/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:09:54 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/21 20:10:27 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void		ft_putunbr_fd_len(unsigned int num, int fd, int *len)
{
	if (num >= 10)
		ft_putunbr_fd(num / 10, fd);
	++*len;
	ft_putchar_fd(num % 10 + 48, fd);
}
