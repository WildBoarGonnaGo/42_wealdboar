/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:07:24 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/24 01:09:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			save_option_true(t_raycast *scene_rndr)
{
	scene_rndr->save_option = 1;
	render_scene(scene_rndr);
	exit(0);
}

int				save_state(t_raycast *render_tools)
{
	write_bmp_file("./deepthought.bmp", *render_tools);
	if (render_tools->img_rndr.img)
		mlx_destroy_image(render_tools->xorg, render_tools->img_rndr.img);
	raycast_exit_proc_fin(render_tools);
	return (1);
}
