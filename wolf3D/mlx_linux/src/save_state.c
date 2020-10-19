/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:07:24 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/19 15:37:59 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

int				save_state(t_raycast *render_tools)
{
	int	i;

	i = -1;
	mlx_put_image_to_window(render_tools->xorg, render_tools->winx,
	render_tools->img_rndr.img, 0, 0);
	write_bmp_file("../deepthought.bmp", *render_tools);
	mlx_clear_window(render_tools->xorg, render_tools->winx);
	if (render_tools->img_rndr.img)
		mlx_destroy_image(render_tools->xorg, render_tools->img_rndr.img);
	mlx_destroy_window(render_tools->xorg, render_tools->winx);
	i = -1;
	while (++i < render_tools->map_size[0])
		memreset((void **)&(*(render_tools->map + i)));
	memreset((void **)render_tools->map);
	return (1);
}
