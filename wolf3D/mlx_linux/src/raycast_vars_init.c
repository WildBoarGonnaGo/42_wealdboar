/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vars_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:25:32 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/17 18:42:00 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	init_vars(t_map_conf src, t_raycast *dst)
{
	dst->width = src.width;
	dst->height = src.height;
	dst->pos[0] = src.player_pos[0];
	dst->pos[1] = src.player_pos[1];
	dst->player_dir[0] = src.player_dir[0];
	dst->player_dir[1] = src.player_dir[1];
	dst->plane_vctr[0] = src.plane_direct[0];
	dst->plane_vctr[1] = src.plane_direct[1];
	dst->map_size[0] = src.map_size[0];
	dst->map_size[1] = src.map_size[1];
	dst->map = src.map_grid;
	dst->img_rndr.img = NULL;
	dst->img_rndr.addr = NULL;
	dst->winx = NULL;
	dst->xorg = NULL;
	read_bitmap_file(src.no_txtr_path, &dst->north_txtr);
	read_bitmap_file(src.so_txtr_path, &dst->south_txtr);
	read_bitmap_file(src.ea_txtr_path, &dst->east_txtr);
	read_bitmap_file(src.we_txtr_path, &dst->west_txtr);
	read_bitmap_file(src.itm_txtr_path, &dst->item_txtr);
	dst->clr_floor = src.flr_color;
	dst->clr_ceil = src.ceil_color;
	dst->item_count = src.item_count;
	dst->item_pos = src.item_pos;
}

void	init_render_tools(t_map_conf src, t_raycast *dst)
{
	int	i;

	i = -1;
	init_vars(src, dst);
	dst->z_buffer_tank = (double *)malloc(sizeof(double) * dst->width);
	while (++i < src.map_size[0])
		memreset((void **)(src.map + i));
	memreset((void **)&src.map);
	dst->save_option = 0;
}
