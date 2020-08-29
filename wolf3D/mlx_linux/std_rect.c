/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:21:54 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/24 21:47:46 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <geoms.h>

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


