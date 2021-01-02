/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:45:46 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/02 19:19:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	int st;
	t_rect obj;

	memset(&obj, 0, sizeof(obj) - 1);
	if (argc == 1 || argc > 2)
	{
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
		return (1);
	}
	if (!(fd = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 
		ft_strlen("Error: Operation file corrupted\n"));
		return (1);
	}
	while ((st = check_row(fd, &obj)))
	{
		if (st < 0)
			break ;
	}
	if (st < 0)
	{
		write(1, "Error: Operation file corrupted\n", 
		ft_strlen("Error: Operation file corrupted\n"));
		free_arr(&obj);
		return (1);
	}
	print_arr(&obj);
	free_arr(&obj);
	return (0);	
}
