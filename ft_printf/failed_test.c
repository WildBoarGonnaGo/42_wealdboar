/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:52:51 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/23 00:16:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf_out.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int				result;
	int				test_num;
	static char		*s_hidden = "hi low\0don't print me lol\0";
 
	test_num = 0;
	//result = ft_printf("this %d number", 17);
	//result = ft_printf("%07d", -54);
	//result = printf("%u\n", 429);
	//ft_printf("result = %d\n", result);
	ft_printf("___STR_EXTRA_TESTS___\n\n");
	result = ft_printf("ft_printf_00%d | Hello, %s|\n", ++test_num ,NULL);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | Hello, %s|\n", test_num, NULL);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %32s|\n", ++test_num, NULL);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %32s|\n", test_num, NULL);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %-32s|\n", ++test_num, NULL);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %-32s|\n", test_num, NULL);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %.9s|\n", ++test_num, "NULL");
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %.9s|\n", test_num, "NULL");
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %.3s|\n", ++test_num, "NULL");
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %.3s|\n", test_num, "NULL");
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %.s|\n", ++test_num, "NULL");
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %.s|\n", test_num, "NULL");
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %.0s|\n", ++test_num, "NULL");
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %.0s|\n", test_num, "NULL");
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %3s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %3s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %9s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %9s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_00%d | %.s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_00%d | %.s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.9s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.9s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.03s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.03s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.09s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.09s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.03s|\n", ++test_num, NULL);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.03s|\n", test_num, NULL);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.09s|\n", ++test_num, NULL);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.09s|\n", test_num, NULL);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %3.s|\n", ++test_num, NULL);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %3.s|\n", test_num, NULL);
	printf("result = %d\n", result);

	ft_printf("\n___HEX_EXTRA_TESTS___\n\n");
	result = ft_printf("ft_printf_%.3d | %.0X|\n", ++test_num ,0);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.0X|\n", test_num, 0);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.X|\n", ++test_num ,0);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.X|\n", test_num, 0);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %5.0X|\n", ++test_num ,0);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %5.0X|\n", test_num, 0);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %-5.0X|\n", ++test_num ,0);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %-5.0X|\n", test_num, 0);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %-5.X|\n", ++test_num ,0);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %-5.X|\n", test_num, 0);
	printf("result = %d\n", result);

	result = ft_printf("ft_printf_%.3d | %u|\n", ++test_num, 4294967295);
	ft_printf("result = %d\n", result);
	result = printf("ft_printf_%.3d | %ld|\n", ++test_num, 4294967295);
	ft_printf("result = %d\n", result);
	//result = printf("tr_printf_%.3d | %2.9p|\n", test_num, 1234);
	//printf("result = %d\n", result);
	//result = printf("Hello, %s\n", NULL);
	//printf("result = %d\n", result);
	/* result = ft_printf("ft_printf_%.3d | %.03s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.03s|\n", test_num, s_hidden);
	printf("result = %d\n", result);
	result = ft_printf("ft_printf_%.3d | %.09s|\n", ++test_num, s_hidden);
	ft_printf("result = %d\n", result);
	result = printf("tr_printf_%.3d | %.09s|\n", test_num, s_hidden);
	printf("result = %d\n", result); 
	
	int X_prec0val0_basic(void){return test("%.0X", 0);}
	int X_prec0val0_implicit(void){return test("%.X", 0);}
	int X_prec0val0_w(void){return test("%5.0X", 0);}
	int X_prec0val0_w_impl(void){return test("%5.X", 0);}
	int X_prec0val0_wlj(void){return test("%-5.0X", 0);}
	int X_prec0val0_wlj_impl(void){return test("%-5.X", 0);}
	*/


	return (0);
}
