/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geoms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:15:34 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/24 22:16:47 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMS_H
# define GEOMS_H

#include <mlx.h>
#include <math.h>
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

typedef struct	geom_4
{
	int			x_cntr;
	int			y_cntr;
	int			radius;
	int			x_roll;
	int			y_roll;
	double		alpha_init;
	double		alpha_out;
}				_arc;

typedef struct	bit_struct
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				img_info;

void			_mlx_pixel_put(img_info *stdput, int x, int y, unsigned int color);
void			line_init(_line *init, int x_0, int y_0, int x_1, int y_1);
void			line_output(img_info *line_img, _line trgt, unsigned int color);
void			crcl_output(img_info *crcl, _crcl trgt, unsigned int color);
void			poly_init( _poly *init, int s_wid, int edge_num, int cent_xy[2]);
void			poly_output(img_info *poly_img, _poly trgt, unsigned int color, 
				double alpha_init);
void			arc_init(_arc *trgt, int iarc_info[3], double darc_info[2]);
void			arc_output(img_info *arc, _arc trgt, unsigned int color);

#endif
