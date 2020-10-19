/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:19:19 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/19 18:07:25 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

t_line			line_init(int x_0, int y_0, int x_1, int y_1)
{
	t_line	init;

	init.x_strt = x_0;
	init.y_strt = y_0;
	init.x_end = x_1;
	init.y_end = y_1;

	return (init);
}

void			line_output(t_img_info *line_img, t_line trgt, unsigned int color)
{
	int pyx;

	pyx = 0;
	trgt.alpha = (trgt.x_end == trgt.x_strt) ? M_PI / 2 + (trgt.y_end < trgt.y_strt) * M_PI :
	atan2((double)(trgt.y_end - trgt.y_strt) , (double)(trgt.x_end - trgt.x_strt));
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
		opengl_pixel_put(line_img, trgt.x_strt, trgt.y_strt, color);
	}
}
