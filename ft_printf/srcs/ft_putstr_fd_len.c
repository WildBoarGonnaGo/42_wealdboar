/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:43:05 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/22 21:48:16 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_putstr_fd_len(char *s, int fd, int *len)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	*len += ft_strlen(s);
}
