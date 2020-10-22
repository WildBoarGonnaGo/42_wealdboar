/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:27:58 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/22 01:18:22 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"

t_bitmap	set_color(unsigned long trnsp, unsigned long red,
			unsigned long green, unsigned long blue)
{
	t_bitmap clr;

	clr.trnsp = trnsp << 24;
	clr.red = red << 16;
	clr.green = green << 8;
	clr.blue = blue;
	clr.clrfull = get_bitmaps(clr);
	return (clr);
}

t_bitmap	add_shade(double dist, t_bitmap vals)
{
	t_bitmap	dif;

	vals.red = get_rcode(vals);
	vals.green = get_gcode(vals);
	vals.blue = get_bcode(vals);
	vals.trnsp = get_trcode(vals);
	dif.red = (int)((1 - dist) * vals.red) << 16;
	dif.green = (int)((1 - dist) * vals.green) << 8;
	dif.blue = (int)((1 - dist) * vals.blue);
	dif.trnsp = (int)((1 - dist) * vals.trnsp) << 24;
	dif.clrfull = get_bitmaps(dif);
	return (dif);
}
