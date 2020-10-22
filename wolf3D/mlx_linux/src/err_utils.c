/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:33:37 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/22 01:43:11 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

int		check_arr_size(char **arr)
{
	int	size;

	size = -1;
	if (arr)
	{
		while (*(arr + ++size))
			;
	}
	else
		size = 0;
	return (size);
}

void	color_split_error(t_map_conf *cub_stat)
{
	int	i;

	i = -1;
	memreset((void **)&cub_stat->arr_purge);
	cub_stat->arr_size = check_arr_size(cub_stat->info_handle);
	while (++i < cub_stat->arr_size)
		memreset((void **)(cub_stat->info_handle + i));
	memreset((void **)&cub_stat->info_handle);
	ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
	exit(1);
}

void	map_build_error(t_map_conf *cub_stat)
{
	int	i;

	i = -1;
	memreset((void **)&cub_stat->arr_purge);
	while (++i < cub_stat->slot)
		memreset((void **)(cub_stat->map + i));
	memreset((void **)&cub_stat->map);
	cub_stat->arr_size = check_arr_size(cub_stat->info_handle);
	i = -1;
	while (++i < cub_stat->arr_size)
		memreset((void **)(cub_stat->info_handle + i));
	memreset((void **)&cub_stat->info_handle);
	ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
	exit(-1);
}
