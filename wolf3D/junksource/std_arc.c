/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_arc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:32:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/02 05:02:06 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <geoms.h>

void			arc_init(_arc *init, double xc, double yc, double radius,
				double alpha_strt, double alpha_end)
{
	init->x_cntr = xc;
	init->y_cntr = yc;
	init->radius = radius;
	init->alpha_init = alpha_strt * M_PI / 180;
	init->alpha_out = alpha_end * M_PI / 180;
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
		trgt.y_roll = trgt.y_cntr + trgt.radius * sin(trgt.alpha_init + d_alpha);
		arc->addr = mlx_get_data_addr(arc->img, &arc->bits_per_pixel, &arc->line_size, &arc->endian);
		_mlx_pixel_put(arc, (int)trgt.x_roll, (int)trgt.y_roll, color);
		d_alpha += 0.005 * M_PI / 180;
	}
}
