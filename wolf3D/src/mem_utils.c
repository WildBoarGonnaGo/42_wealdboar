/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:49:31 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 12:51:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	memreset(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

void	*memrealloc(void *mem, int oldsize, int addbyte)
{
	void	*mem_to_purge;
	void	*res;
	int		indx;

	indx = -1;
	mem_to_purge = mem;
	res = malloc(oldsize + addbyte);
	while (++indx < oldsize && mem)
		*(char *)(res + indx) = *(char *)(mem_to_purge + indx);
	while (indx < oldsize + addbyte)
		*(char *)(res + indx++) = 0;
	memreset(&mem_to_purge);
	return (res);
}

void	line_info_reset(t_map_conf *cub_stat)
{
	memreset((void **)cub_stat->info_handle);
	memreset((void **)&cub_stat->info_handle);
}

void	cub_stat_clean(t_map_conf *cub_stat)
{
	int	i;

	i = -1;
	memreset((void **)&cub_stat->arr_purge);
	cub_stat->arr_size = check_arr_size(cub_stat->info_handle);
	while (++i < cub_stat->arr_size)
		memreset((void **)(cub_stat->info_handle + i));
	memreset((void **)cub_stat->info_handle);
	memreset((void **)&cub_stat->info_handle);
}

void	map_conf_reset(t_map_conf *cub_stat)
{
	int	i;

	i = -1;
	memreset((void **)&cub_stat->no_txtr_path);
	memreset((void **)&cub_stat->so_txtr_path);
	memreset((void **)&cub_stat->we_txtr_path);
	memreset((void **)&cub_stat->ea_txtr_path);
	memreset((void **)&cub_stat->itm_txtr_path);
	while (++i < cub_stat->slot)
		memreset((void **)(cub_stat->map + i));
	memreset((void **)&cub_stat->map);
}
