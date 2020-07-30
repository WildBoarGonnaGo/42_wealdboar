/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:36:27 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 23:31:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

void		ft_putunbr_fd(unsigned int num, int fd)
{
	if (num >= 10)
		ft_putunbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + 48, fd);
}
