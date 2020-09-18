/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:27:58 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/18 06:15:53 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"

void			set_color(bitmap *clr, unsigned long trnsp, unsigned long red,
				unsigned long green, unsigned long blue)
{
	clr->trnsp = trnsp << 24;
	clr->red = red << 16;
	clr->green = green << 8;
	clr->blue = blue;
	clr->_clrfull = get_bitmaps(*clr);
}


int 	get_bitmaps(bitmap vals)
{
	return ((vals.trnsp | vals.red | vals.green | vals.blue));
}

int		get_trcode(bitmap vals)
{
	return ((vals._clrfull >> 24) & 0xFF);
}

int		get_rcode(bitmap vals)
{
	return ((vals._clrfull >> 16) & 0xFF);
}

int		get_gcode(bitmap vals)
{
	return ((vals._clrfull >> 8) & 0xFF);
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
	dif.red = (int)((1 - dist) * vals.red) << 16;
	dif.green = (int)((1 - dist) * vals.green) << 8;
	dif.blue = (int)((1 -dist) * vals.blue);
	dif.trnsp = (int)((1 - dist) * vals.trnsp) << 24;
	dif._clrfull = get_bitmaps(dif);
	return (dif);
}

/*bitmap			set_color(int trnsp, int red, int green, int blue)
{
	bitmap clr;

	clr.trnsp = trnsp << 24;
	clr.red = red << 16;
	clr.green = green << 8;
	clr.blue = blue;
	clr._clrfull = get_bitmaps(*clr);
	return (clr);
}*/
