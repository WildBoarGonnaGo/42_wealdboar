/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:14:12 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 16:15:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_expand.h"

void		ft_mem_reset(void **mem_target)
{
	if (*mem_target)
	{
		free(*mem_target);
		*mem_target = NULL;
	}
	else if (mem_target)
	{
		free(mem_target);
		mem_target = NULL;
	}
}
