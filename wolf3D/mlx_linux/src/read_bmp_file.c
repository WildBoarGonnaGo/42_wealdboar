/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 04:33:33 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/24 03:10:12 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"

int	read_bitmap_file(char *filename, bitmap_pic_info *img_info)
{
	char			pos[2048];

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
	img_info->padded_row = (unsigned int)(img_info->width +
	((4 - img_info->width % 4) & 0x3)) * img_info->bites_per_pixel / 8;
	img_info->unpadded_row = img_info->width * img_info->bites_per_pixel / 8;
	img_info->pyxel_map = (unsigned char *)malloc(img_info->size_image);
	while (img_info->indx < img_info->height)
	{
		read(img_info->fd, img_info->pyxel_map + (img_info->height - img_info->indx - 1)
		* img_info->unpadded_row, img_info->unpadded_row);
		read(img_info->fd, &pos, img_info->padded_row - img_info->unpadded_row);
		++img_info->indx;
	}
	close(img_info->fd);
	return (0);
}
