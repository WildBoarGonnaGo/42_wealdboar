/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 08:03:51 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/19 17:52:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			draw_skyline(int x, t_raycast obj_gl)
{
	t_line	skyline;

	skyline = line_init(x, 0, x, (int)(obj_gl.height / 2 - 1));
	line_output(&obj_gl.img_rndr, skyline, obj_gl.clr_ceil.clrfull);
	skyline = line_init(x, (int)(obj_gl.height / 2), x, obj_gl.height - 1);
	line_output(&obj_gl.img_rndr, skyline, obj_gl.clr_floor.clrfull);
}	

void			insertion_sort(t_raycast *obj_gl)
{
	double	key[3];
	int		i;
	int		j;

	i = -1;
	while (++i < obj_gl->item_count)
		obj_gl->item_pos[i][2] = pow(obj_gl->item_pos[i][0] - obj_gl->pos[0], 2)
		+ pow(obj_gl->item_pos[i][1] - obj_gl->pos[1], 2);
	i = -1;
	while (++i < obj_gl->item_count)
	{
		key[0] = obj_gl->item_pos[i][0];
		key[1] = obj_gl->item_pos[i][1];
		key[2] = obj_gl->item_pos[i][2];
		j = i;
		while (--j >= 0 && obj_gl->item_pos[j][2] < key[2])
		{
			obj_gl->item_pos[j + 1][0] = obj_gl->item_pos[j][0];
			obj_gl->item_pos[j + 1][1] = obj_gl->item_pos[j][1];
			obj_gl->item_pos[j + 1][2] = obj_gl->item_pos[j][2];
		}
		obj_gl->item_pos[j + 1][0] = key[0];
		obj_gl->item_pos[j + 1][1] = key[1];
		obj_gl->item_pos[j + 1][2] = key[2];
	}
}

void			init_rndr_vars(int x, t_raycast *render_tools)
{
	render_tools->xrender = 2 * x / (double)render_tools->width - 1;
	render_tools->proj_vect[0] = render_tools->player_dir[0] + 
	render_tools->xrender * render_tools->plane_vctr[0];
	render_tools->proj_vect[1] = render_tools->player_dir[1]
	+ render_tools->xrender * render_tools->plane_vctr[1];
	render_tools->map_pos[0] = (int)floor(render_tools->pos[0]);
	render_tools->map_pos[1] = (int)floor(render_tools->pos[1]);
	render_tools->trvl_through[0] = (!render_tools->proj_vect[1]) ?
	0 : fabs(1 / render_tools->proj_vect[0]);
	render_tools->trvl_through[1] = (!render_tools->proj_vect[0]) ?
	0 : fabs(1 / render_tools->proj_vect[1]);
	render_tools->hit_detect = 0;
}

void			dir_define(t_raycast *render_tools)
{
	if (render_tools->proj_vect[0] < 0)
	{
		render_tools->grid_step[0] = -1;
		render_tools->trvl_bound[0] = render_tools->trvl_through[0]
		* (render_tools->pos[0] - render_tools->map_pos[0]);
	}
	else
	{
		render_tools->grid_step[0] = 1;
		render_tools->trvl_bound[0] = render_tools->trvl_through[0]
		* (1 -render_tools->pos[0] + render_tools->map_pos[0]);
	}
	if (render_tools->proj_vect[1] < 0)
	{
		render_tools->grid_step[1] = -1;
		render_tools->trvl_bound[1] = render_tools->trvl_through[1]
		* (render_tools->pos[1] - render_tools->map_pos[1]);
	}
	else
	{
		render_tools->grid_step[1] = 1;
		render_tools->trvl_bound[1] = render_tools->trvl_through[1]
		* (1 -render_tools->pos[1] + render_tools->map_pos[1]);
	}
}

void			ray_strike(t_raycast *render_tools)
{
	while (!render_tools->hit_detect)
	{
		if (render_tools->trvl_bound[0] < render_tools->trvl_bound[1])
		{
			render_tools->trvl_bound[0] += render_tools->trvl_through[0];
			render_tools->map_pos[0] += render_tools->grid_step[0];
			render_tools->what_size = 0;
		}
		else
		{
			render_tools->trvl_bound[1] += render_tools->trvl_through[1];
			render_tools->map_pos[1] += render_tools->grid_step[1];
			render_tools->what_size = 1;
		}
		render_tools->hit_detect = (render_tools->map[render_tools->map_pos[0]]
		[render_tools->map_pos[1]] == 1) ? 1 : 0;
	}
}
