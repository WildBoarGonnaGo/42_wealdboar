/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_geoms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 05:42:43 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/24 22:15:43 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../colors.h"
#include <stdlib.h>

typedef	struct	geom_0
{
	int			x_strt;
	int			y_strt;
	int			x_end;
	int			y_end;
	int			x_roll;
	int			y_roll;
	double		dl;
	double		l;
	double		dx;
	double		dy;
	double 		alpha;
}				_line;

typedef	struct	geom_1
{
	int			x_strt;
	int			y_strt;
	int 		x_roll;
	int			y_roll;
	int			radius;
	double		alpha;
}				_crcl;

typedef	struct	geom_2
{
	int			x_cntr;
	int			y_cntr;
	int			x_roll;
	int			y_roll;
	int			width;
	int			height;
}				_rect;

typedef struct	geom_3
{
	int			edge_num;
	int			x_cntr;
	int			y_cntr;
	int			x_roll;
	int			y_roll;
	int			inn_crcl_r;
	int			out_crcl_r;
	double		alpha;
	double		alpha_init;
}				_poly;

typedef struct	bit_struct
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				img_info;

void			_mlx_pixel_put(img_info *stdput, int x, int y, unsigned int color)
{
	char	*dst;

	dst = stdput->addr + (y * stdput->line_size + x * (stdput->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void			line_output(img_info *line_img, _line trgt, unsigned int color)
{
	int pyx;

	pyx = 0;
	trgt.alpha = (trgt.x_end == trgt.x_strt) ? M_PI / 2 :
	atan2((double)(trgt.y_end - trgt.y_strt) , (double)(trgt.x_end - trgt.x_strt));
	if (trgt.alpha == M_PI / 2 && trgt.y_end < trgt.y_strt)
	{
		  pyx = trgt.y_end;
		  trgt.y_end = trgt.y_strt;
		  trgt.y_strt = pyx;
		  pyx = 0;
	}
	trgt.l = sqrt(pow((trgt.y_end - trgt.y_strt), 2) + pow((trgt.x_end - trgt.x_strt), 2));
	trgt.x_roll = trgt.x_strt;
	trgt.y_roll = trgt.y_strt;
	while (trgt.dl <= trgt.l)
	{
		trgt.x_strt = trgt.x_roll + pyx * cos(trgt.alpha);
		trgt.y_strt = trgt.y_roll + (pyx++) * sin(trgt.alpha);
		trgt.dx = trgt.x_strt - trgt.x_roll;
		trgt.dy = trgt.y_strt - trgt.y_roll;
		trgt.dl = sqrt(pow(trgt.dx, 2) + pow(trgt.dy, 2));
		line_img->addr = mlx_get_data_addr(line_img->img, &line_img->bits_per_pixel, &line_img->line_size, &line_img->endian); 
		_mlx_pixel_put(line_img, trgt.x_strt, trgt.y_strt, color);
	}
}

void			crcl_output(img_info *crcl, _crcl trgt, unsigned int color)
{
	if (trgt.alpha != 360)
	{
		trgt.x_roll = trgt.x_strt + trgt.radius * sin((M_PI * trgt.alpha) / 180);
		trgt.y_roll = trgt.y_strt + trgt.radius * cos((M_PI * trgt.alpha) / 180);
		trgt.alpha += 0.5;
		crcl->addr = mlx_get_data_addr(crcl->img, &crcl->bits_per_pixel, &crcl->line_size, &crcl->endian); 
		_mlx_pixel_put(crcl, trgt.x_roll, trgt.y_roll, color);
		crcl_output(crcl, trgt, color);
	}
}

void			rect_output(img_info* rect, _rect trgt, unsigned int color)
{
	trgt.x_roll = trgt.x_cntr - trgt.height / 2;
	trgt.y_roll = trgt.y_cntr - trgt.width / 2;
	while (trgt.x_roll != trgt.x_cntr + trgt.height / 2)
	{
		rect->addr = mlx_get_data_addr(rect->img, &rect->bits_per_pixel, 
		&rect->line_size, &rect->endian);
		_mlx_pixel_put(rect, trgt.x_roll++, trgt.y_roll, color);
	}
	while (trgt.y_roll != trgt.y_cntr + trgt.width / 2)
	{
		rect->addr = mlx_get_data_addr(rect->img, &rect->bits_per_pixel, 
		&rect->line_size, &rect->endian);
		_mlx_pixel_put(rect, trgt.x_roll, trgt.y_roll++, color);
	}
	while (trgt.x_roll != trgt.x_cntr - trgt.height / 2)
	{
		rect->addr = mlx_get_data_addr(rect->img, &rect->bits_per_pixel, 
		&rect->line_size, &rect->endian);
		_mlx_pixel_put(rect, trgt.x_roll--, trgt.y_roll, color);
	}
	while (trgt.y_roll != trgt.y_cntr - trgt.width / 2)
	{
		rect->addr = mlx_get_data_addr(rect->img, &rect->bits_per_pixel, 
		&rect->line_size, &rect->endian);
		_mlx_pixel_put(rect, trgt.x_roll, trgt.y_roll--, color);
	}
}

void			line_init(_line *init, int x_0, int y_0, int x_1, int y_1)
{
	init->x_strt = x_0;
	init->y_strt = y_0;
	init->x_end = x_1;
	init->y_end = y_1;
}

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

/*void			set_color(bitmap *clr, int trnsp, int red,
				int green, int blue)
{
	clr->trnsp = trnsp << 24;
	clr->red = red << 16;
	clr->green = green << 8;
	clr->blue = blue;
	clr->_clrfull = get_bitmaps(*clr);
}*/

int				main(void)
{
	void		*_xorg;
	void		*win_x;
	img_info	crcl;
	img_info	rect;
	img_info	poly_1;
	img_info	poly_2;
 	bitmap		clr_0;
	bitmap		clr_1;
	bitmap		clr_2;
	bitmap		clr_3;
	_crcl		fig_0;
	_rect		fig_1;
	_poly		fig_2;
	_line		fig_3;
	int			cent_xy[2] = {200, 150};

	set_color(&clr_0, 131, 192, 244, 24);
	set_color(&clr_1, 142, 91, 210, 210);
	set_color(&clr_2, 155, 94, 162, 236);
	set_color(&clr_3, 110, 222, 60, 12);
	fig_0.radius = 100;
	fig_0.x_strt = 200;
	fig_0.y_strt = 150;
	fig_0.alpha = 0;
	fig_1.x_cntr = 200;
	fig_1.y_cntr = 150;
	fig_1.width = 250;
	fig_1.height = 150;
	_xorg = mlx_init();
	win_x = mlx_new_window(_xorg, 800, 600, "Geoms output");
	crcl.img = mlx_new_image(_xorg, 400, 300);
	rect.img = mlx_new_image(_xorg, 400, 300);
	poly_1.img = mlx_new_image(_xorg, 400, 300);
	poly_2.img = mlx_new_image(_xorg, 400, 300);
	poly_init(&fig_2, 50, 3, cent_xy);
	line_init(&fig_3, 198, 152, 202, 148);
	crcl_output(&crcl, fig_0, clr_0._clrfull);
	rect_output(&rect, fig_1, clr_1._clrfull);
	poly_output(&poly_1, fig_2, clr_2._clrfull, 210);
	line_output(&poly_1, fig_3, clr_2._clrfull);
	line_init(&fig_3, 198, 148, 202, 152);
	line_output(&poly_1, fig_3, clr_2._clrfull);
	poly_init(&fig_2, 90, 5, cent_xy);
	poly_output(&poly_2, fig_2, clr_3._clrfull, 0);
	mlx_put_image_to_window(_xorg, win_x, crcl.img, 0, 0);
	mlx_put_image_to_window(_xorg, win_x, rect.img, 400, 0);
	mlx_put_image_to_window(_xorg, win_x, poly_1.img, 0, 300);
	mlx_put_image_to_window(_xorg, win_x, poly_2.img, 400, 300);
	mlx_loop(_xorg);
}
