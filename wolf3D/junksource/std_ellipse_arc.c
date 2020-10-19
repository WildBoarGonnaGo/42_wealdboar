/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_ellipse_arc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:17:19 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/16 14:34:00 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geoms.h"

void		ellipse_init(_ellipse *init, double alpha_strt, double alpha_arc,
			double l_radius, double b_radius, double xc, double yc, double slope)
{
	init->l_radius = l_radius;
	init->b_radius = b_radius;
	init->alpha_init = alpha_strt * M_PI / 180;
	init->alpha_out = alpha_arc * M_PI / 180;
	init->x_cntr = xc;
	init->y_cntr = yc;
	init->slope = slope * M_PI / 180;
}

void		std_ellipse_arc(t_img_info *ellipse, _ellipse trgt, unsigned int color)
{
	double	dalpha;
	double	dr;

	dalpha = trgt.alpha_init;
	while (dalpha <= trgt.alpha_init + trgt.alpha_out)
	{
		dr =	trgt.l_radius * trgt.b_radius / sqrt(pow(trgt.b_radius, 2) * pow(sin(dalpha), 2) + 
				pow(trgt.l_radius, 2) * pow(cos(dalpha), 2));
		trgt.x_roll = trgt.x_cntr + dr * cos(dalpha + trgt.slope);
		trgt.y_roll = trgt.y_cntr + dr * sin(dalpha + trgt.slope);
		ellipse->addr =	mlx_get_data_addr(ellipse->img, &ellipse->bits_per_pixel, &ellipse->line_size,
						&ellipse->endian);
		_mlx_pixel_put(ellipse, (int)trgt.x_roll, (int)trgt.y_roll, color);
		dalpha += 0.001 * M_PI / 180;
	}
}	
