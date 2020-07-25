/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_test_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:13:11 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/25 04:48:37 by lchantel         ###   ########.fr       */
/*   Updated: 2020/07/24 01:18:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf_out.h"
#include <stdio.h>

int	main(void)
{
	//int		a = -4;
	//int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	//int		f = 42;
	//int		g = 25;
	//int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	int		count = 0;
	int		result;
 	char	*n = "abcdefghijklmnop";
	//char	*o = "-a";
	//char	*p = "-12";
	//char	*q = "0";
	//char	*r = "%%";
	//char	*s = "-2147483648";
	//char	*t = "0x12345678";
	//char	*u = "-0";
	
	result = ft_printf("ft_test %.3d | %i |\n", ++count, i);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i |\n", count, i);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d|\n", ++count, i, j);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d|\n", count, i, j);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d|\n", ++count, i, j, k);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d|\n", count, i, j, k);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d|\n", ++count, i, j, k, l);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d|\n", count, i, j, k, l);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d, %d|\n", ++count, i, j, k, l, m);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d, %d|\n", count, i, j, k, l, m);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d, %d, %s |\n", ++count, i, j, k, l, m, n);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d, %d, %s |\n", count, i, j, k, l, m, n);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d, %d, %s, %c |\n", ++count, i, j, k, l, m, n, c);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d, %d, %s, %c |\n", count, i, j, k, l, m, n, c);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d, %d, %s, %c, %d |\n", ++count, i, j, k, l, m, n, c, c);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d, %d, %s, %c, %d |\n", count, i, j, k, l, m, n, c, c);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d, %d, %s, %c, %d, %u |\n", ++count, i, j, k, l, m, n, c, c, j);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d, %d, %s, %c, %d, %u |\n", count, i, j, k, l, m, n, c, c, j);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X|\n", ++count, i, j, k, l, m, n, c, c, j, j, j);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X|\n", count, i, j, k, l, m, n, c, c, j, j, j);
	printf("result = %d\n", result);

	//TEST 3
	result = ft_printf("ft_test %.3d | %0i, %0d, %0d, %0d, %0d, %0d|\n", ++count, i, j, k, l, m, c);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %0i, %0d, %0d, %0d, %0d, %0d|\n", ++count, i, j, k, l, m, c);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %0i, %0d, %0d, %0d, %0d, %0d, %0d|\n", ++count, i, j, k, l, m, c, e);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %0i, %0d, %0d, %0d, %0d, %0d, %0d|\n", ++count, i, j, k, l, m, c, e);
	printf("result = %d\n", result);

	result = ft_printf("ft_test %.3d | %0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d|\n", ++count, i, j, k, l, m, c, e, d);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d|\n", ++count, i, j, k, l, m, c, e, d);
	printf("result = %d\n", result);
	//TEST 4
	result = ft_printf("ft_test %.3d | %1d|\n", ++count, e);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %1d|\n", ++count, e);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %2d|\n", ++count, e);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | 2%2d|\n", ++count, e);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %14d|\n", ++count, e);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %14d|\n", ++count, e);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %14.0d|\n", ++count, e);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %14.0d|\n", ++count, e);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %0*.*i|\n", ++count, 2, -2, 8);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %0*.*i|\n", count, 2, -2, 8);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %0*.*i|\n", ++count, 2, 0, 8);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %0*.*i|\n", count, 2, 0, 8);
	printf("result = %d\n", result);
	result = ft_printf("ft_test %.3d | %0*.*i|\n", ++count, 2, 1, 8);
	ft_printf("result = %d\n", result);
	result = printf("tr_test %.3d | %0*.*i|\n", count, 2, 1, 8);
	printf("result = %d\n", result);
}

