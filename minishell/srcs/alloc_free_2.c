/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:05:39 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:19:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	alloc_free_2(void ***mem)
{
	int i;

	i = -1;
	if (*mem)
	{
		while (*(*mem + ++i))
		{
			free(*(*mem + i));
			*(*mem + i) = NULL;
		}
		free(*mem);
		*mem = NULL;
	}
}
