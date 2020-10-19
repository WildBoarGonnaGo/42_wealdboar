/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 08:16:11 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/19 15:42:18 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	write_bmp_init(t_bitmap_pic_info *bmp, t_raycast obj_gl)
{
	bmp->red_chnl = 0xFF0000;
	bmp->green_chnl = 0xFF00;
	bmp->blue_chnl = 0xFF;
	bmp->alpha_chnl = 0;
	bmp->cstype = 0;
	bmp->bites_per_pixel = 24;
	bmp->pyxel_pos_offset = 122;
	bmp->struct_size = 108;
	bmp->plane = 1;
	bmp->comress = 0;
	bmp->xpix_per_meter = 2834;
	bmp->ypix_per_meter = 2834;
	bmp->reserve_1 = 0;
	bmp->reserve_2 = 0;
	bmp->clr_sockets = 0;
	bmp->clr_table = 0;
	bmp->width = obj_gl.width;
	bmp->height = obj_gl.height;
	bmp->frmt_signature[0] = 'B';
	bmp->frmt_signature[1] = 'M';
	bmp->padded_row = (int)((obj_gl.width + ((4 - obj_gl.width % 4) & 0x3))
	* bmp->bites_per_pixel / 8);
	bmp->unpadded_row = (int)(obj_gl.width * bmp->bites_per_pixel / 8);	
	bmp->file_size = bmp->pyxel_pos_offset + bmp->padded_row * bmp->height;
	bmp->size_image = bmp->unpadded_row * bmp->height;
}

void	write_data(t_bitmap_pic_info bmp)
{
	write(bmp.fd, &bmp.file_size, 4);
	write(bmp.fd, &bmp.reserve_1, 2);
	write(bmp.fd, &bmp.reserve_2, 2);
	write(bmp.fd, &bmp.pyxel_pos_offset, 4);
	write(bmp.fd, &bmp.struct_size, 4);
	write(bmp.fd, &bmp.width, 4);
	write(bmp.fd, &bmp.height, 4);
	write(bmp.fd, &bmp.plane, 2);
	write(bmp.fd, &bmp.bites_per_pixel, 2);
	write(bmp.fd, &bmp.comress, 4);
	write(bmp.fd, &bmp.size_image, 4);
	write(bmp.fd, &bmp.xpix_per_meter, 4);
	write(bmp.fd, &bmp.ypix_per_meter, 4);
	write(bmp.fd, &bmp.clr_table, 4);
	write(bmp.fd, &bmp.clr_sockets, 4);
	write(bmp.fd, &bmp.red_chnl, 4);
	write(bmp.fd, &bmp.green_chnl, 4);
	write(bmp.fd, &bmp.blue_chnl, 4);
	write(bmp.fd, &bmp.alpha_chnl, 4);
	write(bmp.fd, &bmp.cstype, 4);
	write(bmp.fd, &bmp.cstype, 36);
	write(bmp.fd, &bmp.reserve_1, 4);
	write(bmp.fd, &bmp.reserve_1, 4);
	write(bmp.fd, &bmp.reserve_1, 4);
}

void	write_img_data(t_raycast obj_gl, int *pos,
		t_bitmap_pic_info bmp, unsigned int color)
{
	unsigned short empty;

	empty = 0;
	while (++pos[0] < (int)bmp.height)
	{
		while (++pos[1] < (int)bmp.width)
		{
			color = *(unsigned int *)(obj_gl.img_rndr.addr + obj_gl.img_rndr.line_size
			* (bmp.height - 1 - pos[0]) + pos[1] * obj_gl.img_rndr.bits_per_pixel / 8);
			write(bmp.fd, &color, (int)(bmp.bites_per_pixel / 8));
		}
		write(bmp.fd, &empty, bmp.padded_row - bmp.unpadded_row);
		pos[1] = -1;
	}
}

int		write_bmp_file(char *filename, t_raycast obj_gl)
{
	t_bitmap_pic_info	bmp;
	int					pos[2];
	unsigned int		color;
	unsigned short		empty;

	empty = 0;
	pos[0] = -1;
	pos[1] = -1;
	color = 0;
	bmp.indx = 0;
	if ((bmp.fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 666)) < 0)
		return (-1);
	write_bmp_init(&bmp, obj_gl);
	write(bmp.fd, &bmp.frmt_signature[0], 1);
	write(bmp.fd, &bmp.frmt_signature[1], 1);
	write_data(bmp);	
	write_img_data(obj_gl, pos, bmp, color);
	close(bmp.fd);
	return (1);
}
