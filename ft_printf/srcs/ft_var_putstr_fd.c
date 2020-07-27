/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:24:50 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/28 01:12:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

void		ft_var_putstr_fd(int args, int fd, ...)
{
	va_list	str_arg;
	char	*str;

	va_start(str_arg, fd);
	while (args-- > 0)
	{
		str = va_arg(str_arg, char *);
		ft_putstr_fd(str, fd);
	}
	va_end(str_arg);
}
