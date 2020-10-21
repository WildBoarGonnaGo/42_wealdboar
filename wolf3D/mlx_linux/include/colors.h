/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 03:30:25 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/20 18:52:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# define BITMAP_PIC_SIGNATURE "BM"
# define BITMAP_PIX_PIC_OFFSET 0x0A

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct		s_bitmap
{
	unsigned long	trnsp;
	unsigned long	red;
	unsigned long	green;
	unsigned long	blue;
	unsigned long	clrfull;
}					t_bitmap;

typedef struct		s_bitmap_pic_info
{
	unsigned short	fd;
	unsigned short	indx;
	char			frmt_signature[2];
	unsigned int	file_size;
	unsigned short	reserve_1;
	unsigned short	reserve_2;
	unsigned int	pyxel_pos_offset;
	unsigned int	struct_size;
	unsigned int	width;
	unsigned int	height;
	unsigned short	plane;
	unsigned short	bites_per_pixel;
	unsigned int	comress;
	unsigned int	size_image;
	unsigned int	xpix_per_meter;
	unsigned int	ypix_per_meter;
	unsigned int	clr_table;
	unsigned int	clr_sockets;
	unsigned int	red_chnl;
	unsigned int	green_chnl;
	unsigned int	blue_chnl;
	unsigned int	alpha_chnl;
	unsigned int	cstype;
	unsigned int	padded_row;
	unsigned int	unpadded_row;
	unsigned int	img_size;	
	unsigned char	*pyxel_map;
}					t_bitmap_pic_info;


int					get_bitmaps(t_bitmap vals);
int					get_trcode(t_bitmap vals);
int					get_rcode(t_bitmap vals);
int					get_gcode(t_bitmap vals);
int					get_bcode(t_bitmap vals);
t_bitmap			add_shade(double dist, t_bitmap vals);
t_bitmap			set_color(unsigned long trnsp, unsigned long red,
					unsigned long green, unsigned long blue);

#endif
