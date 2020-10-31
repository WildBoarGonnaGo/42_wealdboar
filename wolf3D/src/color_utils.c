/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:56:41 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 12:55:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"

int			get_bitmaps(t_bitmap vals)
{
	return ((vals.trnsp | vals.red | vals.green | vals.blue));
}

int			get_trcode(t_bitmap vals)
{
	return ((vals.clrfull >> 24) & 0xFF);
}

int			get_rcode(t_bitmap vals)
{
	return ((vals.clrfull >> 16) & 0xFF);
}

int			get_gcode(t_bitmap vals)
{
	return ((vals.clrfull >> 8) & 0xFF);
}

int			get_bcode(t_bitmap vals)
{
	return (vals.clrfull & 0xFF);
}
