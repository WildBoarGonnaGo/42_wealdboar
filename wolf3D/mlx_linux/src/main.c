/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:34:39 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/11 05:42:36 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/wolf3d.h"

int	str_ansys(char **str, int max_pos)
{
	int	i;
	int	pos;
	int	len;

	pos = 0;
	while (pos < max_pos)
	{
		i = 0;
		if (!pos)
		{
			while (!ft_strchr(" 1", *(*(str + pos) + i++) && *(str + i))
				;
			return (!*(*(str + pos) + i));
		}
		else if (pos == max_pos)
		{
			while
		}
		while (*(str) )

	}
}

int	map_ansys(map_conf *obj)
{
	int	indx;

	indx = 0;
	while (indx )	
}

int main(int argc, char *argv[])
{
    map_conf	map;
	int			i;

	i = 0;
    if (argc != 2)
    {
        perror("Wrong number of arguments.\n");
        return (0);
    }
    map = map_init_input(argv[1]);
    printf("Floor color code: %x\n", map.flr_color);
    printf("Ceil color code: %x\n", map.ceil_color);
	printf("Total number of strings: %d\n\n", map.pos);
	while (i < map.pos)
		printf("%s\n", *(map.map + i++));
	printf("\n");
    return (0);
}
