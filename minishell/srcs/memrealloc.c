/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memrealloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:00:01 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:20:53 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*memrealloc(void *mem, int oldsize, int addbyte)
{
	void	*res;
	int		indx;
	void	*mem_to_purge;

	indx = -1;
	oldsize += (addbyte < 0) * addbyte;
	mem_to_purge = mem;
	res = malloc(oldsize + (addbyte > 0) * addbyte);
	while (++indx < oldsize && mem)
		*(char *)(res + indx) = *(char *)(mem + indx);
	while (indx < oldsize + addbyte)
		*(char *)(res + indx++) = 0;
	if (mem_to_purge)
		free(mem_to_purge);
	return (res);
}
