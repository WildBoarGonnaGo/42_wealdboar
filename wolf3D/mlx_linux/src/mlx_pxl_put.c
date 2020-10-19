/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pxl_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:20:45 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/19 17:53:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void			opengl_pixel_put(t_img_info *stdput, int x, int y, unsigned int color)
{
	char	*dst;

	dst = stdput->addr + (y * stdput->line_size + x * (stdput->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
