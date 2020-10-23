/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:57:59 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 12:50:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			item_vars_init(t_raycast *obj_gl)
{
	obj_gl->wall_height = (int)fabs(obj_gl->height / obj_gl->new_cs_pos[1]);
	obj_gl->wall_ceil = (((obj_gl->height - obj_gl->wall_height) / 2) < 0) ? 0 :
	(obj_gl->height - obj_gl->wall_height) / 2;
	obj_gl->wall_floor = (((obj_gl->height + obj_gl->wall_height) / 2) >
	obj_gl->height - 1) ? obj_gl->height - 1 : (obj_gl->height
	+ obj_gl->wall_height) / 2;
	obj_gl->txtr_itm_wratio = obj_gl->wall_height;
	obj_gl->xrender_itm_strt = ((obj_gl->pxl_itm_xpos - obj_gl->txtr_itm_wratio
	/ 2) < 0) ? 0 : obj_gl->pxl_itm_xpos - obj_gl->txtr_itm_wratio / 2;
	obj_gl->xrender_itm_end = ((obj_gl->pxl_itm_xpos + obj_gl->txtr_itm_wratio
	/ 2) > obj_gl->width - 1) ? obj_gl->width - 1 : obj_gl->pxl_itm_xpos
	+ obj_gl->txtr_itm_wratio / 2;
	obj_gl->x_stripe = obj_gl->xrender_itm_strt;
	obj_gl->text_render_step = (double)obj_gl->item_txtr.height
	/ obj_gl->wall_height;
	obj_gl->yinit_render_pos = (obj_gl->wall_ceil - ((obj_gl->height
	- obj_gl->wall_height) / 2)) * obj_gl->text_render_step;
}

void			item_pxl_output(t_raycast *obj_gl)
{
	obj_gl->bmp_text_pos[1] = (int)obj_gl->yinit_render_pos &
	(obj_gl->item_txtr.height - 1);
	obj_gl->clr_general.clrfull = *(unsigned int *)(obj_gl->item_txtr.pyxel_map
	+ obj_gl->item_txtr.unpadded_row * obj_gl->bmp_text_pos[1] +
	obj_gl->bmp_text_pos[0] * obj_gl->item_txtr.bites_per_pixel / 8);
	obj_gl->clr_general.red = get_rcode(obj_gl->clr_general);
	obj_gl->clr_general.green = get_gcode(obj_gl->clr_general);
	obj_gl->clr_general.blue = get_bcode(obj_gl->clr_general);
	if (obj_gl->clr_general.red && obj_gl->clr_general.blue
	&& obj_gl->clr_general.green)
	{
		obj_gl->clr_wall_draw = add_shade(0.5, obj_gl->clr_general);
		*(unsigned int *)(obj_gl->img_rndr.addr + obj_gl->wall_ceil
		* obj_gl->img_rndr.line_size + obj_gl->x_stripe *
		obj_gl->img_rndr.bits_per_pixel / 8) = obj_gl->clr_wall_draw.clrfull;
	}
	obj_gl->yinit_render_pos += obj_gl->text_render_step;
	++obj_gl->wall_ceil;
}

void			line_cycle(t_raycast *obj_gl, double *old_value)
{
	obj_gl->xrender = (obj_gl->x_stripe - (obj_gl->pxl_itm_xpos
	- obj_gl->txtr_itm_wratio / 2)) * obj_gl->item_txtr.width
	/ obj_gl->txtr_itm_wratio;
	obj_gl->bmp_text_pos[0] = (int)obj_gl->xrender &
	(obj_gl->item_txtr.width - 1);
	if (obj_gl->new_cs_pos[1] > 0 && obj_gl->x_stripe > 0 &&
	obj_gl->x_stripe < obj_gl->width && obj_gl->z_buffer_tank[obj_gl->x_stripe]
	> obj_gl->new_cs_pos[1])
	{
		while (obj_gl->wall_ceil < obj_gl->wall_floor)
			item_pxl_output(obj_gl);
	}
	++obj_gl->x_stripe;
	obj_gl->yinit_render_pos = old_value[0];
	obj_gl->wall_ceil = old_value[1];
}

void			draw_item_text(t_raycast *obj_gl)
{
	int		i;
	double	trans_factor;
	double	old_value[2];

	i = -1;
	insertion_sort(obj_gl);
	trans_factor = 1 / (obj_gl->player_dir[1] * obj_gl->plane_vctr[0]
	- obj_gl->player_dir[0] * obj_gl->plane_vctr[1]);
	while (++i < obj_gl->item_count)
	{
		item_vars_base(obj_gl, trans_factor, i, old_value);
		item_vars_init(obj_gl);
		old_value[0] = obj_gl->yinit_render_pos;
		old_value[1] = obj_gl->wall_ceil;
		while (obj_gl->x_stripe < obj_gl->xrender_itm_end)
			line_cycle(obj_gl, old_value);
	}
}
