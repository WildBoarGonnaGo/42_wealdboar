/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:16:33 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/22 01:53:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			check_if_texture_ex(char *filepath, char **texture,
				t_map_conf *cub_stat, int offset)
{
	int i;

	i = -1;
	if (check_filepath(filepath))
	{
		if (!(*texture = ft_strdup(filepath)))
		{
			cub_stat->arr_size = check_arr_size(cub_stat->info_handle);
			while (++i < cub_stat->arr_size)
				memreset((void **)(cub_stat->info_handle + i));
			memreset((void **)&cub_stat->info_handle);
			memreset((void **)&cub_stat->arr_purge);
			ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
			exit(-1);
		}
		cub_stat->map_stat |= (1 << offset);
	}
}

void			color_define(t_map_conf *cub_stat, t_bitmap *color,
				t_bitmap *trgt, int offset)
{
	int	i;

	i = -1;
	if (!(cub_stat->color = ft_split(*(cub_stat->info_handle + 1), ',')))
		color_split_error(cub_stat);
	if ((cub_stat->arr_size = check_arr_size(cub_stat->info_handle)) < 2)
	{
		memreset((void **)&cub_stat->arr_purge);
		while (++i < cub_stat->arr_size)
			memreset((void **)(cub_stat->info_handle + i));
		memreset((void **)&cub_stat->info_handle);
		ft_putstr_fd("Error.\nNot enough color-chanels data", 2);
		ft_putstr_fd("to compute further.\n", 2);
		exit(-1);
	}
	color->red = ft_atoi(*(cub_stat->color));
	color->green = ft_atoi(*(cub_stat->color + 1));
	color->blue = ft_atoi(*(cub_stat->color + 2));
	*color = set_color(0, color->red, color->green, color->blue);
	*trgt = *color;
	strcolor_reset(cub_stat);
	cub_stat->map_stat |= (1 << offset);
}

void			line_def(char *line, t_map_conf *cub_stat)
{
	cub_stat->info_handle = ft_split(line, ' ');
	if (!*cub_stat->info_handle)
	{
		if (!(cub_stat->info_handle = (char **)malloc(sizeof(char *))))
		{
			memreset((void **)&cub_stat->arr_purge);
			ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
			exit(-1);
		}
		if (!(*cub_stat->info_handle = ft_strdup("")))
		{
			memreset((void **)&cub_stat->arr_purge);
			memreset((void **)&cub_stat->info_handle);
			ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
			exit(-1);
		}
	}
}

void			map_build(t_map_conf *cub_stat, char *line)
{
	if (!(cub_stat->map = (char **)memrealloc(cub_stat->map, sizeof(char *)
	* cub_stat->slot, sizeof(char *))))
		map_build_error(cub_stat);
	if (!(*(cub_stat->map + cub_stat->slot++) = ft_strdup(line)))
	{
		--cub_stat->slot;
		map_build_error(cub_stat);
	}
}
