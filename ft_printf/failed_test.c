/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:52:51 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/22 00:37:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf_out.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int result;

	//result = ft_printf("this %d number", 17);
	//result = ft_printf("%07d", -54);
	//result = printf("%u\n", 429);
	//ft_printf("result = %d\n", result);
	ft_printf("Hello, %s\n", NULL);
	result = printf("Hello, %s\n", NULL);
	printf("result = %d\n", result);
	return (0);
}
