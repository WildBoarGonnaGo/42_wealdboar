/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_poly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 00:17:55 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/22 00:19:21 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geoms.h"

void			poly_init( _poly *init, int s_wid, int edge_num, int cent_xy[2])
{
	init->x_cntr = cent_xy[0];
	init->y_cntr = cent_xy[1];
	init->inn_crcl_r = s_wid;
	init->edge_num = edge_num;
	init->alpha = (360 / init->edge_num) * (M_PI / 180);
	init->out_crcl_r = init->inn_crcl_r / cos(init->alpha / 2);
}

void			poly_output(img_info *poly_img, _poly trgt, unsigned int color, 
				double alpha_init)
{
	_line	epoly;

	alpha_init = M_PI * alpha_init / 180;
	trgt.alpha_init = alpha_init - trgt.alpha / 2;
	while (trgt.edge_num--)
	{
   		epoly.x_strt = trgt.x_cntr + trgt.out_crcl_r * cos(trgt.alpha_init);
		epoly.y_strt = trgt.y_cntr + trgt.out_crcl_r * sin(trgt.alpha_init);
		trgt.alpha_init += trgt.alpha;
		epoly.x_end = trgt.x_cntr + trgt.out_crcl_r * cos(trgt.alpha_init);
		epoly.y_end = trgt.y_cntr + trgt.out_crcl_r * sin(trgt.alpha_init);
		line_output(poly_img, epoly, color);
	}
}
