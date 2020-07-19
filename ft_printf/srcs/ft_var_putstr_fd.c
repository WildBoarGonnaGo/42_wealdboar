/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:24:50 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 16:26:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

void		ft_var_putstr_fd(int args, int fd, ...)
{
	va_list	strArg;
	char	*str;

	va_start(strArg, fd);
	while (args-- > 0)
	{
		str = va_arg(strArg, char *);
		ft_putstr_fd(str, fd);
	}
	va_end(strArg);
}
