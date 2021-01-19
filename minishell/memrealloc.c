/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memrealloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:00:01 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/19 13:32:02 by wildboarg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	*memrealloc(void *mem, int oldsize, int addbyte)
{
	void	*mem_to_purge;
	void	*res;
	int		indx;

	indx = -1;
	mem_to_purge = mem;
	oldsize += (addbyte < 0) * addbyte;
	res = malloc(oldsize + (addbyte > 0) * addbyte);
	while (++indx < oldsize && mem)
		*(char *)(res + indx) = *(char *)(mem_to_purge + indx);
	while (indx < oldsize + addbyte)
		*(char *)(res + indx++) = 0;
	free(mem_to_purge);
	mem_to_purge = NULL;
	return (res);
}

