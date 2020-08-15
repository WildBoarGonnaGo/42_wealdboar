/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 03:37:53 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/14 05:45:56 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "utils.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	bitmap _obj;
	//int	a = 0x00FF00;
	char *str[2];

	if (argc != 2)
		return (0);
	_obj._clrfull = ft_atou_base(argv[1], 16);
	printf("origin color hex code: %s\n", argv[1]);
	printf("orgin color dec number: %u\n", _obj._clrfull);
	_obj = add_shade(0.25, _obj);
	printf("shaded color dec number: %u\n", _obj._clrfull);
	str[0] = gethex_impl(_obj._clrfull);
	str[1] = str[0];
	printf("new color hex code: %s", str[0]);
	//printf("check: %x\n", _obj._clrfull);
	//printf("check dec: %d\n", a);
	ft_memreset((void **)&str[1]);
	return (0);
}
