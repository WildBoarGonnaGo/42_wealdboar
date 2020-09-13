/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:56:01 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/25 00:45:32 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * rainbow colors:
 * red: #FF0000 
 * orange: #FF7F00
 * yellow: #FFFF00
 * green: #00FF00
 * dark blue: #0000FF
 * dark purple: #4B0082
 * purple: #8F00FF
 * */

#include <geoms.h>
#include "../colors.h"

typedef struct	geom_5
{
	int			x_cntr;
	int			y_cntr;
	int			l_radius;
	int			b_radius;
}				_rainbow;

_rainbow		rainbow_init(int xcntr, int ycntr, int l_radius, int b_radius)
{
	_rainbow	init;

	init.x_cntr = xcntr;
	init.y_cntr = ycntr;
	init.l_radius = l_radius;
	init.b_radius = b_radius;
	return (init);
}

void			draw_rainbow(_rainbow trgt, img_info *img, bitmap *colors)
{
	double	dlt_rnbow;
	double	buf;
	int		count;
	_arc	draw;
	int		iarc_info[3];
	double	darc_info[2];

	count = 7;
	dlt_rnbow = (trgt.b_radius - trgt.l_radius) / 7;
	buf = dlt_rnbow;
	while (count--)
	{
		while (dlt_rnbow-- > 0)
		{
			darc_info[0] = 180;
			darc_info[1] = 180;
			iarc_info[0] = trgt.x_cntr;
			iarc_info[1] = trgt.y_cntr;
			iarc_info[2] = trgt.l_radius++;
			arc_init(&draw, iarc_info, darc_info);
			arc_output(img, draw, colors[count]._clrfull);
		}
		dlt_rnbow = buf;
	}
}

int				main(void)
{
	void		*_xorg;
	void		*winx;
	img_info	rainbow;
	bitmap		_clrs_rain[7];
	_rainbow	obj;
	
	_clrs_rain[0]._clrfull = 0xFF0000;
	_clrs_rain[1]._clrfull = 0xFF7F00;
	_clrs_rain[2]._clrfull = 0xFFFF00;
	_clrs_rain[3]._clrfull = 0x00FF00;
	_clrs_rain[4]._clrfull = 0x0000FF;
	_clrs_rain[5]._clrfull = 0x4B0082;
	_clrs_rain[6]._clrfull = 0x8F00FF;
	_xorg = mlx_init();
	winx = mlx_new_window(_xorg, 800, 600, "Rainbow");
	rainbow.img = mlx_new_image(_xorg, 800, 600);
	obj = rainbow_init(400, 200, 140, 210);
	draw_rainbow(obj, &rainbow, _clrs_rain);
	mlx_put_image_to_window(_xorg, winx, rainbow.img, 0, 0);
	mlx_loop(_xorg);
}
