/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 04:33:33 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/22 02:01:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include "../include/maze3d.h"

void	read_bmp_data(t_bitmap_pic_info *img_info)
{
	read(img_info->fd, &img_info->frmt_signature[0], 1);
	read(img_info->fd, &img_info->frmt_signature[1], 1);
	read(img_info->fd, &img_info->file_size, 4);
	read(img_info->fd, &img_info->reserve_1, 2);
	read(img_info->fd, &img_info->reserve_2, 2);
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
}

int		read_bitmap_file(char *filename, t_bitmap_pic_info *img_info,
		t_map_conf *cub_stat, t_raycast *obj_gl)
{
	char			pos[2048];

	img_info->indx = 0;
	check_bmp_ext(filename, obj_gl, cub_stat);
	if ((img_info->fd = open(filename, O_RDONLY)) < 0)
		return (0);
	read_bmp_data(img_info);
	img_info->padded_row = (unsigned int)(img_info->width +
	((4 - img_info->width % 4) & 0x3)) * img_info->bites_per_pixel / 8;
	img_info->unpadded_row = img_info->width * img_info->bites_per_pixel / 8;
	if (!(img_info->pyxel_map = (unsigned char *)malloc(img_info->size_image)))
		return (0);
	while (img_info->indx < img_info->height)
	{
		read(img_info->fd, img_info->pyxel_map + (img_info->height
		- img_info->indx - 1) * img_info->unpadded_row, img_info->unpadded_row);
		read(img_info->fd, &pos, img_info->padded_row - img_info->unpadded_row);
		++img_info->indx;
	}
	close(img_info->fd);
	return (1);
}
