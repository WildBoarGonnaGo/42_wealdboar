/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 03:30:25 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/22 11:42:02 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct			colors
{
	int					trnsp;
	int					red;
	int					green;
	int					blue;
	unsigned int		_clrfull;
}						bitmap;

int		get_bitmaps(bitmap vals);
int		get_trcode(bitmap vals);
int		get_rcode(bitmap vals);
int		get_gcode(bitmap vals);
int		get_bcode(bitmap vals);
bitmap	add_shade(double dist, bitmap vals);
void	set_color(bitmap *clr, int trnsp, int red,
		int green, int blue);

#endif
