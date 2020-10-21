/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_exit_proc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:05:54 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/21 21:02:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	raycast_memalloc_err(t_raycast *obj_gl, t_map_conf *obj)
{
	int	i;

	i = -1;
	memreset((void **)&obj_gl->north_txtr.pyxel_map);
	memreset((void **)&obj_gl->south_txtr.pyxel_map);
	memreset((void **)&obj_gl->east_txtr.pyxel_map);
	memreset((void **)&obj_gl->west_txtr.pyxel_map);
	memreset((void **)&obj_gl->item_txtr.pyxel_map);
	while (++i < obj_gl->map_size[0])
		memreset((void **)(obj_gl->map + i));
	memreset((void **)&obj_gl->map);
	map_conf_reset(obj);
	perror("Error.\nDynamic memory allocation error.\n");
	exit(1);
}

void	raycast_exit_proc_mid(t_raycast *obj_gl, t_map_conf *obj)
{
	int	i;

	i = -1;
	memreset((void **)&obj_gl->north_txtr.pyxel_map);
	memreset((void **)&obj_gl->south_txtr.pyxel_map);
	memreset((void **)&obj_gl->east_txtr.pyxel_map);
	memreset((void **)&obj_gl->west_txtr.pyxel_map);
	memreset((void **)&obj_gl->item_txtr.pyxel_map);
	while (++i < obj_gl->map_size[0])
		memreset((void **)(obj_gl->map + i));
	memreset((void **)&obj_gl->map);
	memreset((void **)&obj_gl->z_buffer_tank);
	memreset((void **)&obj_gl->img_rndr.addr);
	map_conf_reset(obj);
}

void	raycast_exit_proc_fin(t_raycast *obj_gl)
{
	int	i;

	i = -1;
	memreset((void **)&obj_gl->north_txtr.pyxel_map);
	memreset((void **)&obj_gl->south_txtr.pyxel_map);
	memreset((void **)&obj_gl->east_txtr.pyxel_map);
	memreset((void **)&obj_gl->west_txtr.pyxel_map);
	memreset((void **)&obj_gl->item_txtr.pyxel_map);
	while (++i < obj_gl->map_size[0])
		memreset((void **)(obj_gl->map + i));
	memreset((void **)&obj_gl->map);
	memreset((void **)&obj_gl->z_buffer_tank);
	i = -1;
	while (++i < obj_gl->item_count)
		memreset((void **)(obj_gl->item_pos + i));
	memreset((void **)&obj_gl->item_pos);
}
