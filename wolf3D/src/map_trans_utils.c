/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_trans_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:57:19 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 12:51:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	calc_map_size(t_map_conf *obj)
{
	int	i;

	i = -1;
	obj->map_size[0] = obj->slot;
	while (++i < obj->map_size[0])
		if (obj->map_size[1] < (int)ft_strlen(*(obj->map + i)))
			obj->map_size[1] = (int)ft_strlen(*(obj->map + i));
}

void	imp_map_info_reset(t_map_conf *obj)
{
	int	i;

	i = -1;
	if (obj->map_grid)
	{
		while (++i < obj->map_size[0])
			memreset((void **)&(*(obj->map_grid + i)));
		memreset((void **)&obj->map_grid);
	}
	i = -1;
	if (obj->item_pos)
	{
		while (++i < obj->item_count)
			memreset((void **)&(*(obj->item_pos + i)));
		memreset((void **)&obj->item_pos);
		obj->item_count = 0;
	}
}
