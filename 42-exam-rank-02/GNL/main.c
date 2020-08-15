/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:37:23 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/10 00:18:40 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		state;

	while ((state = get_next_line(&line)))
	{
		printf("%d |%s\n", state, line);
		ft_memreset((void **)&line);
	}
	printf("%d |%s\n", state, line);
	ft_memreset((void **)&line);
	return (0);
}
