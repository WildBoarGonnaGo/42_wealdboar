/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_vars_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 01:34:42 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/22 01:35:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			item_vars_base(t_raycast *obj_gl, double trans_factor, int i,
				double *old_value)
{
	obj_gl->new_cs_pos[0] = obj_gl->item_pos[i][0] - obj_gl->pos[0];
	obj_gl->new_cs_pos[1] = obj_gl->item_pos[i][1] - obj_gl->pos[1];
	old_value[0] = obj_gl->new_cs_pos[0];
	obj_gl->new_cs_pos[0] = trans_factor * (obj_gl->new_cs_pos[0]
	* obj_gl->player_dir[1] - obj_gl->new_cs_pos[1] * obj_gl->player_dir[0]);
	obj_gl->new_cs_pos[1] = trans_factor * (-old_value[0]
	* obj_gl->plane_vctr[1] + obj_gl->new_cs_pos[1] * obj_gl->plane_vctr[0]);
	obj_gl->pxl_itm_xpos = (int)(obj_gl->width * (1
	+ obj_gl->new_cs_pos[0] / obj_gl->new_cs_pos[1]) / 2);
}
