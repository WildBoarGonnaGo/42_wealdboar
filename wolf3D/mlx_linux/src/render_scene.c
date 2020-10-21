/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 07:57:43 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/20 11:13:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			wall_side_hit(t_raycast *render_tools)
{
	if (!render_tools->what_size)
	{
		render_tools->wall_dist = (render_tools->map_pos[0] - render_tools->pos[0] + 
		(1 - render_tools->grid_step[0]) / 2) / render_tools->proj_vect[0];
		render_tools->texture = (render_tools->grid_step[0] > 0) ? 
		render_tools->south_txtr : render_tools->north_txtr;
	}
	else
	{
		render_tools->wall_dist = (render_tools->map_pos[1] - render_tools->pos[1] + 
		(1 - render_tools->grid_step[1]) / 2) / render_tools->proj_vect[1];
		render_tools->texture = (render_tools->grid_step[1] > 0) ? 
		render_tools->east_txtr : render_tools->west_txtr;
	}
}

void			pretext_prep(t_raycast *render_tools)
{
	render_tools->wall_height = (int)render_tools->height / render_tools->wall_dist;
	render_tools->wall_ceil = ((render_tools->height / 2 - render_tools->wall_height / 2) < 0) ?
	0 : render_tools->height / 2 - render_tools->wall_height / 2;
	render_tools->wall_floor = ((render_tools->height / 2 + render_tools->wall_height / 2) > render_tools->height) ?
	render_tools->height : render_tools->height / 2 + render_tools->wall_height / 2;
	render_tools->xrender_pos = (!render_tools->what_size) ? render_tools->pos[1] + render_tools->wall_dist
	* render_tools->proj_vect[1] : render_tools->pos[0] + render_tools->wall_dist * render_tools->proj_vect[0];
	render_tools->xrender_pos -= floor(render_tools->xrender_pos);
	render_tools->bmp_text_pos[0] = (render_tools->xrender_pos * render_tools->texture.width);
	if ((!render_tools->what_size && render_tools->proj_vect[0] > 0) || 
	(render_tools->what_size == 1 && render_tools->proj_vect[1] < 0))
	render_tools->bmp_text_pos[0] = render_tools->texture.width - 1 - render_tools->bmp_text_pos[0];
	render_tools->text_render_step = (double)render_tools->texture.height / render_tools->wall_height;
	render_tools->yinit_render_pos = (render_tools->wall_ceil - (render_tools->height /2
	- render_tools->wall_height/2)) * render_tools->text_render_step;
}

void			scene_draw(int x, t_raycast *render_tools)
{
	while (render_tools->wall_ceil < render_tools->wall_floor)
	{
		render_tools->bmp_text_pos[1] = (int)render_tools->yinit_render_pos
		& (render_tools->texture.height - 1);
		render_tools->clr_general.clrfull = *(unsigned int *)(render_tools->texture.pyxel_map
		+ render_tools->bmp_text_pos[1] * render_tools->texture.unpadded_row
		+ render_tools->bmp_text_pos[0] * render_tools->texture.bites_per_pixel / 8);
		render_tools->clr_wall_draw = (!render_tools->what_size) ? render_tools->clr_general :
		add_shade(0.5, render_tools->clr_general);
		*(unsigned int *)(render_tools->img_rndr.addr + (render_tools->wall_ceil++)
		* render_tools->img_rndr.line_size + x * render_tools->img_rndr.bits_per_pixel / 8)
		= render_tools->clr_wall_draw.clrfull;
		render_tools->yinit_render_pos += render_tools->text_render_step;
	}
}

void			full_render_cycle(int x, t_raycast *render_tools)
{
	draw_skyline(x, *render_tools);	
	init_rndr_vars(x, render_tools);
	dir_define(render_tools);
	ray_strike(render_tools);	
	wall_side_hit(render_tools);
	pretext_prep(render_tools);
	scene_draw(x, render_tools);
	render_tools->z_buffer_tank[x] = render_tools->wall_dist;
}

int				render_scene(t_raycast *render_tools)
{
	int		x;
		
	render_tools->img_rndr.img = mlx_new_image(render_tools->xorg, 
	render_tools->width, render_tools->height);
	render_tools->img_rndr.addr = mlx_get_data_addr(render_tools->img_rndr.img,
	&render_tools->img_rndr.bits_per_pixel, &render_tools->img_rndr.line_size, 
	&render_tools->img_rndr.endian); 
	mlx_clear_window(render_tools->xorg, render_tools->winx);
	x = -1;
	while (++x < render_tools->width)
		full_render_cycle(x, render_tools);
	draw_item_text(render_tools);
	if (render_tools->save_option)
		return (save_state(render_tools));
	mlx_put_image_to_window(render_tools->xorg, render_tools->winx,
	render_tools->img_rndr.img, 0, 0);
	if (render_tools->img_rndr.img)
		mlx_destroy_image(render_tools->xorg, render_tools->img_rndr.img);
	return (1);
}
