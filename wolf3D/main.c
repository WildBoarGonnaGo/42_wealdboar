/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 03:37:53 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/15 17:10:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "utils.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	bitmap _obj;
	bitmap _blk;
	bitmap _dist;
	double	dist = 0.75;

	char 	*str[2];
	if (argc != 2)
		return (0);
	_obj._clrfull = ft_atou_base(argv[1], 16);
	printf("origin color hex code: %s\n", argv[1]);
	printf("orgin color dec number: %u\n", _obj._clrfull);
	_dist = add_shade(dist, _obj);
	str[0] = gethex_impl(_dist._clrfull);
	str[1] = str[0];
	printf("new color hex code: %s\n", str[0]);	
	ft_memreset((void **)&str[1]);
	printf("new color dec number: %d\n", _dist._clrfull);
	return (0);
}
