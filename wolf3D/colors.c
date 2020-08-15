/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:27:58 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/15 17:03:01 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int 	get_bitmaps(bitmap vals)
{
	return ((vals.trnsp | vals.red | vals.green | vals.blue));
}

int		get_trcode(bitmap vals)
{
	return (vals._clrfull & (0xFF << 24));
}

int		get_rcode(bitmap vals)
{
	return (vals._clrfull & (0xFF << 16));
}

int		get_gcode(bitmap vals)
{
	return (vals._clrfull & (0xFF << 8));
}

int		get_bcode(bitmap vals)
{
	return(vals._clrfull & 0xFF);
}

bitmap	add_shade(double dist, bitmap vals)
{
	bitmap	dif;

	vals.red = get_rcode(vals);
	vals.green = get_gcode(vals);
	vals.blue = get_bcode(vals);
	vals.trnsp = get_trcode(vals);
	dif.red = (int)((1 - dist) * (vals.red >> 16)) << 16;
	dif.green = (int)((1 - dist) * (vals.green >> 8)) << 8;
	dif.blue = (int)((1 -dist) * vals.blue);
	dif.trnsp = vals.trnsp;
	dif._clrfull = get_bitmaps(dif);
	return (dif);
}
