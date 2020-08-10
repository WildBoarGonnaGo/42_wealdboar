/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:27:58 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/10 19:24:11 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	colors
{
	int	trnsp;
	int	red;
	int	green;
	int	blue;
	int	_clrfull;
}				bitmap;

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

int		add_shade(bitmap vals, )
