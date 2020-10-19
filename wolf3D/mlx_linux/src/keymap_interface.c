/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:52:13 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/16 22:54:25 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"
#include <stdio.h>

void			player_move(t_raycast *scene_chng, int dir_factor)
{
	scene_chng->pos[0] += (!scene_chng->map[(int)floor(scene_chng->pos[0] + WALK_DIST * 
	scene_chng->player_dir[0] * dir_factor)][(int)floor(scene_chng->pos[1])]) ?
	WALK_DIST * scene_chng->player_dir[0] * dir_factor : 0;
	scene_chng->pos[1] += (!scene_chng->map[(int)floor(scene_chng->pos[0])][
	(int)floor(scene_chng->pos[1] + WALK_DIST * scene_chng->player_dir[1] * dir_factor)]) ?
	WALK_DIST * scene_chng->player_dir[1] * dir_factor : 0;
}

void			player_strafe(t_raycast *scene_chng, int dir_factor)
{
	double	strafe_dir[2];

	strafe_dir[0] = -scene_chng->player_dir[1] * sin(M_PI / 2);
	strafe_dir[1] = scene_chng->player_dir[0] * sin(M_PI / 2);
	scene_chng->pos[0] += (!scene_chng->map[(int)floor(scene_chng->pos[0] + WALK_DIST * 
	strafe_dir[0] * dir_factor)][(int)floor(scene_chng->pos[1])]) ?
	WALK_DIST * strafe_dir[0] * dir_factor : 0;
	scene_chng->pos[1] += (!scene_chng->map[(int)floor(scene_chng->pos[0])][
	(int)floor(scene_chng->pos[1] + WALK_DIST * strafe_dir[1] * dir_factor)])
	? WALK_DIST * strafe_dir[1] * dir_factor : 0;
}

void			player_turn(t_raycast *scene_chng, int dir_factor)
{
	double	old_vect_x;
	double	old_plane_x;

	old_vect_x = scene_chng->player_dir[0];
	old_plane_x = scene_chng->plane_vctr[0];
	scene_chng->player_dir[0] = scene_chng->player_dir[0] * cos(dir_factor * DELTA_ANGL)
	- scene_chng->player_dir[1] * sin(dir_factor * DELTA_ANGL);
	scene_chng->player_dir[1] = old_vect_x * sin(dir_factor * DELTA_ANGL)
	+ scene_chng->player_dir[1] * cos(dir_factor * DELTA_ANGL);
	scene_chng->plane_vctr[0] = scene_chng->plane_vctr[0] * cos(dir_factor * DELTA_ANGL)
	- scene_chng->plane_vctr[1] * sin(dir_factor * DELTA_ANGL);
	scene_chng->plane_vctr[1] = old_plane_x * sin(dir_factor * DELTA_ANGL)
	+ scene_chng->plane_vctr[1] * cos(dir_factor * DELTA_ANGL);
}

void			esc_pgrm_exit(t_raycast *scene_chng)
{
		int	i;

		mlx_clear_window(scene_chng->xorg, scene_chng->winx);
		mlx_destroy_window(scene_chng->xorg, scene_chng->winx);
		i = -1;	
		while (++i < scene_chng->map_size[0])
			memreset((void **)&(*(scene_chng->map + i)));
		memreset((void **)scene_chng->map);
		memreset((void **)&scene_chng->z_buffer_tank);
		exit(0);
}

int				keymap_interface(int keycode, t_raycast *scene_chng)
{
	if (keycode == 'w' || keycode == 'W')
		player_move(scene_chng, 1);
	else if (keycode == 's' || keycode == 'S')
		player_move(scene_chng, -1);
	else if (keycode == 'd' || keycode == 'D')
		player_strafe(scene_chng, 1);
	else if (keycode == 'a' || keycode == 'A')
		player_strafe(scene_chng, -1);
	else if (keycode == LEFT_ARROW)
		player_turn(scene_chng, -1);
	else if (keycode == RIGHT_ARRROW)
		player_turn(scene_chng, 1);
	else if (keycode == ESC)
		esc_pgrm_exit(scene_chng);
	return (1);
}
