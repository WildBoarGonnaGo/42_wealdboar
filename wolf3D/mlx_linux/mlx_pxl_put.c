/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pxl_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:20:45 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/21 23:23:18 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geoms.h"

void			_mlx_pixel_put(img_info *stdput, int x, int y, unsigned int color)
{
	char	*dst;

	dst = stdput->addr + (y * stdput->line_size + x * (stdput->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
