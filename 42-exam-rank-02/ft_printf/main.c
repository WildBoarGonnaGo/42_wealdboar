/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:58:19 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/27 23:55:33 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *str, ...);

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	a;
	int		res;
	int		seq;
	int		b;
	char	*str = "World!";

	a = 5;
	seq = 0;
	b = -1234;
	ft_printf("___INTEGER_TEST___\n\n");
	res = ft_printf("ft_test %0.3d | a = %d_\n", seq, a);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %d_\n", seq, a);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | b = %0.5d_\n", seq, b);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | b = %0.5d_\n", seq, b);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | b = %7.5d_\n", seq, b);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | b = %7.5d_\n", seq, b);
	printf("tr_test %0.3d | res = %d\n", seq++, res);
	res = ft_printf("ft_test %0.3d | b = %4.5d a = %4.5d_\n", seq, b, a);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | b = %4.5d a = %4.5d_\n", seq, b, a);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | INT_MIN = %d_\n", seq, INT_MIN);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | INT_MIN = %d_\n", seq, INT_MIN);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);

	ft_printf("\n___STR_TEST___\n\n");
	res = ft_printf("ft_test %0.3d | Hello, %s_\n", seq, str);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %s_\n", seq, str);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | Hello, %.3s_\n", seq, str);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %.3s_\n", seq, str);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | Hello, %5.4s_\n", seq, str);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %5.4s_\n", seq, str);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | Hello, %s_\n", seq, NULL);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %s_\n", seq, NULL);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);

	ft_printf("\n___STR_TEST___\n\n");
	res = ft_printf("ft_test %0.3d | Hello, %s_\n", seq, str);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %s_\n", seq, str);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | Hello, %.4s_\n", seq, str);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %.4s_\n", seq, str);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | Hello, %5.4s_\n", seq, str);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %5.4s_\n", seq, str);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | Hello, %s_\n", seq, NULL);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | Hello, %s_\n", seq, NULL);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);

	ft_printf("\n___HEX_TEST___\n\n");
	res = ft_printf("ft_test %0.3d | a = %x_\n", seq, a);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %x_\n", seq, a);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | a = %x_\n", seq, 27);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %x_\n", seq, 27);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | a = %x_\n", seq, 169);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %x_\n", seq, 169);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | a = %x_\n", seq, b);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %x_\n", seq, b);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | a = %x_\n", seq, b);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %x_\n", seq, b);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | a = %10.7x_\n", seq, b);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %10.7x_\n", seq, b);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);
	res = ft_printf("ft_test %0.3d | a = %7.10x_\n", seq, b);
	ft_printf("ft_test %0.3d | res = %d_\n", seq, res);
	res = printf("tr_test %0.3d | a = %7.10x_\n", seq, b);
	printf("tr_test %0.3d | res = %d_\n", seq++, res);

	return (0);
}
