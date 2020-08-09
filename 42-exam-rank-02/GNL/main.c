/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:37:23 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/08 18:41:40 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;

	while (get_next_line(&line))
	{
		printf("|%s\n", line);
		ft_memreset((void **)&line);
	}
	printf("|%s\n", line);
	ft_memreset((void **)&line);
	return (0);
}
