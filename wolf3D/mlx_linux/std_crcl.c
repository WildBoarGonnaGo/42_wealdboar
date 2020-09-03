/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_crcl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:27:32 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/24 21:59:53 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <geoms.h>

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
