/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 03:30:25 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/24 03:36:12 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# define BITMAP_PIC_SIGNATURE 0x424D
# define BITMAP_PIX_PIC_OFFSET 0x0A

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct			colors
{
	unsigned long		trnsp;
	unsigned long		red;
	unsigned long		green;
	unsigned long		blue;
	unsigned long		_clrfull;
}						bitmap;

typedef struct		sign_info
{
	unsigned short	fd;
	unsigned short	indx;
	unsigned short	frmt_signature; //115
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
	unsigned int	padded_row;
	unsigned int	unpadded_row;
	unsigned int	img_size;	
	unsigned char	*pyxel_map;
}					bitmap_pic_info;


int		get_bitmaps(bitmap vals);
int		get_trcode(bitmap vals);
int		get_rcode(bitmap vals);
int		get_gcode(bitmap vals);
int		get_bcode(bitmap vals);
bitmap	add_shade(double dist, bitmap vals);
void	set_color(bitmap *clr, unsigned long trnsp, unsigned long red,
		unsigned long green, unsigned long blue);
int		read_bitmap_file(char *filename, bitmap_pic_info *img_info);

#endif
