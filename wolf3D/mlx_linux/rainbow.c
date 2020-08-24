/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:56:01 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/23 17:47:24 by lchantel         ###   ########.fr       */
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

#include <mlx.h>
#include "geoms.h"
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

void			draw_rainbow(_rainbow trgt, img_info *img, unsigned int *colors)
{
	double	dlt_rnbow;
	int		count;

	count = 0;
	dlt_rnbow = (trgt.b_radius - trgt.l_radius) / 7;
	
}

int				main(void)
{
	void		*_xorg;
	void		*winx;
	img_info	rainbow;
	bitmap		_clrs_rain[7];
	_rainbow	rainbow;
	
	_clrs_rain[0]._clrfull = 0xFF0000;
	_clrs_rain[1]._clrfull = 0xFF7F00;
	_clrs_rain[2]._clrfull = 0xFFFF00;
	_clrs_rain[3]._clrfull = 0x00FF00;
	_clrs_rain[4]._clrfull = 0x0000FF;
	_clrs_rain[5]._clrfull = 0x4B0082;
	_clrs_rain[6]._clrfull = 0x8F00FF;
	_xorg = mlx_init();
	win_x = mlx_new_window(_xorg, 800, 600, "Rainbow");
	rainbow.img = mlx_new_image(_xorg, 800, 600);

}
