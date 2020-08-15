/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:27:58 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/14 05:04:51 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int 	get_bitmaps(bitmap vals)
{
	return ((vals.trnsp << 24 | vals.red << 16 | vals.green << 8 | vals.blue));
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

	dif._clrfull = 0xFFFFFF;
	dif.red = (get_rcode(vals) | (int)(dist * (get_rcode(dif) - get_rcode(vals))));
	dif.blue = (get_rcode(vals) | (int)(dist * (get_bcode(dif) - get_bcode(vals))));
	dif.green = (get_gcode(vals) | (int)(dist * (get_gcode(dif) - get_gcode(vals))));
	dif.trnsp = vals.trnsp;
	dif._clrfull = get_bitmaps(dif);
	return (dif);
}
