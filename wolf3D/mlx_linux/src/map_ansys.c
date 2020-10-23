/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ansys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:19:47 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 17:50:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	minesweep_back(t_map_conf **obj, t_route_pass **cur)
{
	(*obj)->player_pos[0] = (*cur)->prev->x;
	(*obj)->player_pos[1] = (*cur)->prev->y;
	*cur = (*cur)->prev;
	purge_list((*cur)->next);
	(*cur)->next = NULL;
}

void	minesweep_frwrd(t_map_conf **obj, t_route_pass **cur,
		int *dir)
{
	(*obj)->player_pos[0] += dir[0];
	(*obj)->player_pos[1] += dir[1];
	(*obj)->map_grid[(*obj)->player_pos[0]][(*obj)->player_pos[1]] = 1;
	*cur = add_frwrd(*cur, (*obj)->player_pos[0], (*obj)->player_pos[1]);
}

int		ansys_cases(t_map_conf *obj, t_route_pass **init,
		t_route_pass **cur, int *dir)
{
	if (!obj->player_pos[0] || obj->player_pos[0] == obj->map_size[0] - 1
	|| !obj->player_pos[1] || obj->player_pos[1] == obj->map_size[1] - 1)
	{
		purge_list(*init);
		return (0);
	}
	else if (obj->map_grid[obj->player_pos[0]][obj->player_pos[1]]
	&& !(*cur)->dir)
		minesweep_back(&obj, cur);
	else if (!(obj->map_grid[obj->player_pos[0] + dir[0]]
	[obj->player_pos[1] + dir[1]]) ||obj->map_grid[obj->player_pos[0] + dir[0]]
	[obj->player_pos[1] + dir[1]] == 2)
		minesweep_frwrd(&obj, cur, dir);
	else
	{
		(*cur)->dir -= M_PI / 2;
		if (*cur == *init && !(*init)->dir)
			purge_list(*cur);
	}
	return (1);
}

int		map_ansys(t_map_conf obj)
{
	int				dir[2];
	t_route_pass	*init;
	t_route_pass	*cur;

	init = create_list(obj.player_pos[0], obj.player_pos[1]);
	obj.map_grid[obj.player_pos[0]][obj.player_pos[1]] = 1;
	cur = init;
	while (init->dir)
	{
		dir[0] = (int)cos(cur->dir);
		dir[1] = (int)sin(cur->dir);
		if (!ansys_cases(&obj, &init, &cur, dir))
			return (0);
	}
	return (1);
}
