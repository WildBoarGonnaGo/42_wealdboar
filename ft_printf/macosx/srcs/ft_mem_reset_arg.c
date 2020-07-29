/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_reset_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:16:12 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 16:22:07 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

void	ft_mem_reset_arg(int num, ...)
{
	int		i;
	va_list	mem_frwrd;

	i = -1;
	va_start(mem_frwrd, num);
	while (++i < num)
		ft_mem_reset(va_arg(mem_frwrd, void **));
	va_end(mem_frwrd);
}
