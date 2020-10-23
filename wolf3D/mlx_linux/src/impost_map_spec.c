/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impost_map_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 02:06:26 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 16:32:34 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	map_grid_reset(t_map_conf *obj, int *pos)
{
	int	i;

	i = -1;
	while (++i < obj->item_count)
		memreset((void **)(obj->item_pos + i));
	memreset((void **)&obj->item_pos);
	i = -1;
	while (++i < pos[0])
		memreset((void **)(obj->map_grid + i));
	memreset((void **)&obj->map_grid);
	map_conf_reset(obj);
}

void	err_invalid_char(t_map_conf *obj, int *pos)
{
	map_grid_reset(obj, pos);
	ft_putstr_fd("Error.\nUnknown character within the map.\n", 2);
	exit(-1);
}

void	err_invalid_player(t_map_conf *obj, int *pos)
{
	map_grid_reset(obj, pos);
	ft_putstr_fd("Error.\nNo player position defined.\n", 2);
	exit(-1);
}

void	player_pos_ansys(int *pos, t_map_conf *obj)
{
	++obj->player_indx;
	if (obj->player_indx > 1)
	{
		map_grid_reset(obj, pos);
		ft_putstr_fd("Error.\nMultiple player positions.\n", 2);
		exit(-1);
	}
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
