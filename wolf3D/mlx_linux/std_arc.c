/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_arc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:32:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/24 23:19:26 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <geoms.h>

void			arc_init(_arc *init, int iarc_info[3], double darc_info[2])
{
	init->x_cntr = iarc_info[0];
	init->y_cntr = iarc_info[1];
	init->radius = iarc_info[2];
	init->alpha_init = darc_info[0] * M_PI / 180;
	init->alpha_out = darc_info[1] * M_PI / 180;
}

void			arc_output(img_info *arc, _arc trgt, unsigned int color)
{
	double			d_alpha; 
	double			fin_alpha;

	d_alpha = 0;
	fin_alpha = trgt.alpha_init + trgt.alpha_out;
	while (trgt.alpha_init + d_alpha <= fin_alpha)
	{
		trgt.x_roll = trgt.x_cntr + trgt.radius * cos(trgt.alpha_init + d_alpha);
		trgt.y_roll = trgt.x_cntr + trgt.radius * sin(trgt.alpha_init + d_alpha);
		arc->addr = mlx_get_data_addr(arc->img, &arc->bits_per_pixel, &arc->line_size, &arc->endian);
		_mlx_pixel_put(arc, trgt.x_roll, trgt.y_roll, color);
		d_alpha += 0.1 * M_PI / 360;
	}
}
