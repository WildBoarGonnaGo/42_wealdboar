/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:16:33 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/19 07:33:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			check_if_texture_ex(char *filepath, char **texture,
				int *map_stat, int offset)
{
	if (check_filepath(filepath))
	{
		*texture = ft_strdup(filepath);
		*map_stat |= (1 << offset);
	}
}

void			color_define(t_map_conf *cub_stat, t_bitmap *color,
				t_bitmap *trgt)
{
	cub_stat->color = ft_split(*(cub_stat->info_handle + 1), ',');
	color->red = ft_atoi(*(cub_stat->color));
	color->green = ft_atoi(*(cub_stat->color + 1));
	color->blue = ft_atoi(*(cub_stat->color + 2));
	*color = set_color(255, color->red, color->green, color->blue);
	*trgt = *color;
	strcolor_reset(cub_stat);
}

void			line_def(char *line, t_map_conf *cub_stat)
{
	cub_stat->info_handle = ft_split(line, ' ');	
	if (!*cub_stat->info_handle)
	{
		cub_stat->info_handle = (char **)malloc(sizeof(char *));
		*cub_stat->info_handle = ft_strdup("");
	}
}

void			map_build(t_map_conf *cub_stat, char *line)
{
	cub_stat->map = (char **)memrealloc(cub_stat->map, sizeof(char *)
	* cub_stat->slot, sizeof(char *));
	*(cub_stat->map + cub_stat->slot++) = ft_strdup(line);
	memreset((void **)cub_stat->info_handle);
}
