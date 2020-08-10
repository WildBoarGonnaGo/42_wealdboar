/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:37:23 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/08/10 00:18:40 by wealdboar        ###   ########.fr       */
=======
/*   Updated: 2020/08/08 18:41:40 by lchantel         ###   ########.fr       */
>>>>>>> 61d00e1c4618fb06660e8e2cb5400b81c99fb3fa
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
<<<<<<< HEAD
	char	*line;
	int		state;

	while ((state = get_next_line(&line)))
	{
		printf("%d |%s\n", state, line);
		ft_memreset((void **)&line);
	}
	printf("%d |%s\n", state, line);
=======
	char *line;

	while (get_next_line(&line))
	{
		printf("|%s\n", line);
		ft_memreset((void **)&line);
	}
	printf("|%s\n", line);
>>>>>>> 61d00e1c4618fb06660e8e2cb5400b81c99fb3fa
	ft_memreset((void **)&line);
	return (0);
}
