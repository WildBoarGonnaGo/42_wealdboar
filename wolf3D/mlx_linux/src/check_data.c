/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:34:39 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/23 01:55:39 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/maze3d.h"
#include <libft.h>

void	ew_case(t_map_conf *obj, int dir_factor)
{
	obj->player_dir[0] = 0;
	obj->player_dir[1] = dir_factor;
	obj->plane_direct[0] = (-1) * dir_factor * FOV_PROJ_LEN;
	obj->plane_direct[1] = 0;
}

void	ns_case(t_map_conf *obj, int dir_factor)
{
	obj->player_dir[0] = dir_factor;
	obj->player_dir[1] = 0;
	obj->plane_direct[0] = 0;
	obj->plane_direct[1] = dir_factor * FOV_PROJ_LEN;
}

void	new_item(t_map_conf *obj, int *pos)
{
	int	i;

	i = -1;
	if (!(obj->item_pos = (double **)memrealloc(obj->item_pos, sizeof(double *)
	* obj->item_count, sizeof(double *))))
	{
		map_conf_reset(obj);
		while (++i < obj->item_count)
			memreset((void **)(obj->item_pos + i));
		memreset((void **)&obj->item_pos);
		ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
		exit(1);
	}
	*(obj->item_pos + obj->item_count) = (double *)malloc(sizeof(double) * 3);
	**(obj->item_pos + obj->item_count) = (double)pos[0] + 0.5;
	*(*(obj->item_pos + obj->item_count++) + 1) = (double)pos[1] + 0.5;
	*(*(obj->map_grid + pos[0]) + pos[1]) = 2;
}

void	map_trans_process(t_map_conf *obj, int *pos)
{
	if (ft_strchr("NSWE", *(*(obj->map + pos[0]) + (obj->map_size[1] - 1
	- pos[1]))) && *(*(obj->map + pos[0]) + (obj->map_size[1] - 1 - pos[1])))
	{
		obj->player_pos[0] = pos[0];
		obj->player_pos[1] = pos[1];
		if (*(*(obj->map + pos[0]) + (obj->map_size[1] - 1 - pos[1])) == 'E')
			ew_case(obj, -1);
		else if (*(*(obj->map + pos[0]) + (obj->map_size[1]
		- 1 - pos[1])) == 'W')
			ew_case(obj, 1);
		else if (*(*(obj->map + pos[0]) + (obj->map_size[1]
		- 1 - pos[1])) == 'N')
			ns_case(obj, -1);
		else if (*(*(obj->map + pos[0]) + (obj->map_size[1]
		- 1 - pos[1])) == 'S')
			ns_case(obj, 1);
		*(*(obj->map_grid + pos[0]) + pos[1]) = 0;
	}
	else if (*(*(obj->map + pos[0]) + (obj->map_size[1] - 1 - pos[1])) == '1')
		*(*(obj->map_grid + pos[0]) + pos[1]) = 1;
	else if (*(*(obj->map + pos[0]) + (obj->map_size[1] - 1 - pos[1])) == '2')
		new_item(obj, pos);
	else if (*(*))
		*(*(obj->map_grid + pos[0]) + pos[1]) = 0;
}

int		impostor_map(t_map_conf *obj)
{
	int	pos[2];

	obj->item_count = 0;
	pos[0] = -1;
	pos[1] = -1;
	obj->map_grid = (int **)malloc(sizeof(int *) * obj->map_size[0]);
	while (++pos[0] < obj->map_size[0])
	{
		*(obj->map_grid + pos[0]) = (int *)malloc(sizeof(int)
		* obj->map_size[1]);
		while (++pos[1] < obj->map_size[1])
			map_trans_process(obj, pos);
		pos[1] = -1;
	}
	return (1);
}
