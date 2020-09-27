/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:00:57 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/23 21:19:16 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <geoms.h>
#include "../include/colors.h"

#define	BITMAP_PIC_SIGNATURE 0x424D
#define BITMAP_PIX_PIC_OFFSET 0x0A

/*typedef struct		sign_info
{
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
}					bitmap_pic_info;*/

int	read_bitmap_file(char *filename, bitmap_pic_info *img_info)
{
	char			pos[8192];

	img_info->indx = 0;
	if ((img_info->fd = open(filename, O_RDONLY)) < 0)
		return (-1);
	read(img_info->fd, &pos, 10);
	read(img_info->fd, &img_info->pyxel_pos_offset, 4);
	read(img_info->fd, &img_info->struct_size, 4);
	read(img_info->fd, &img_info->width, 4);
	read(img_info->fd, &img_info->height, 4);
	read(img_info->fd, &img_info->plane, 2);
	read(img_info->fd, &img_info->bites_per_pixel, 2);
	read(img_info->fd, &img_info->comress, 4);
	read(img_info->fd, &img_info->size_image, 4);
	read(img_info->fd, &img_info->xpix_per_meter, 4);
	read(img_info->fd, &img_info->ypix_per_meter, 4);
	read(img_info->fd, &img_info->clr_table, 4);
	read(img_info->fd, &img_info->clr_sockets, 4);
	img_info->padded_row = (unsigned int)(img_info->width + ((4 - img_info->width % 4) & 0x3)) * img_info->bites_per_pixel / 8;
	img_info->unpadded_row = img_info->width * img_info->bites_per_pixel / 8;
	img_info->pyxel_map = (unsigned char *)malloc(img_info->size_image);
	while (img_info->indx < img_info->height)
	{
		read(img_info->fd, img_info->pyxel_map + (img_info->height - img_info->indx - 1) * img_info->unpadded_row, img_info->unpadded_row);
		read(img_info->fd, &pos, img_info->padded_row - img_info->unpadded_row);
		++img_info->indx;
	}
	close(img_info->fd);
	return (0);
}

#include <stdio.h>

/*
typedef struct	bit_struct
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}

void			_mlx_pixel_put(img_info *stdput, int x, int y, unsigned int color)
{
	char	*dst;

	dst = stdput->addr + (y * stdput->line_size + x * (stdput->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
 * */

int	main(void)
{
	void				*xorg;
	void				*winx;
	bitmap_pic_info		test;
	img_info			test_img;
	int					i;
	int					j;
	char				*dst;
	bitmap				clr_pxl;
	//unsigned int		color;

	i = -1;
	j = -1;
	if (read_bitmap_file("/home/lchantel/texture_pack/wall_text_10_512.bmp", &test) < 0)
	{	
		printf("\nError: there is no such file, or it's directory");
		return (-1);
	}
	xorg = mlx_init();
	winx = mlx_new_window(xorg, test.width, test.height, "Texture output");
	test_img.img = mlx_new_image(xorg, test.width, test.height);
	//test_img.bits_per_pixel = test.bytes_per_pixel;
	//test_img.line_size = test.unpadded_row;
	test_img.addr = mlx_get_data_addr(test_img.img, &test_img.bits_per_pixel, &test_img.line_size, &test_img.endian);
	while (++i < (int)test.height)
	{
		while (++j < (int)test.width)
		{
			//test_img.addr = mlx_get_data_addr(test_img.img, &test_img.bits_per_pixel, &test_img.line_size, &test_img.endian);
			dst = test_img.addr + (i * test_img.line_size + j * test_img.bits_per_pixel / 8);
			clr_pxl._clrfull = *(unsigned int *)(test.pyxel_map + (i * test.unpadded_row + j * test.bites_per_pixel / 8)); 
			*(unsigned int *)dst = clr_pxl._clrfull;
		}
		j = -1;
	}
	mlx_put_image_to_window(xorg, winx, test_img.img, 0, 0);
	mlx_loop(xorg);
}
