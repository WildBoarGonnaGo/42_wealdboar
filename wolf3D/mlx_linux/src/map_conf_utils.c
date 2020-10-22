/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 07:21:15 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/22 01:51:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

int		check_filepath(char *path)
{
	int fd;

	if ((fd = open(path, O_RDWR)) < 0)
	{
		ft_putstr_fd("Error.\nThere is no such file, or it's directory.\n", 2);
		return (0);
	}
	if (close(fd) < 0)
	{
		ft_putstr_fd("Error.\nFile stream shutdown error.\n", 2);
		return (0);
	}
	return (1);
}

void	stats_zero(t_map_conf *init)
{
	init->file_dscrptr = 0;
	init->width = 0;
	init->height = 0;
	init->flr_color.clrfull = 0;
	init->ceil_color.clrfull = 0;
	init->map_stat = 0;
	init->slot = 0;
	init->info_handle = NULL;
	init->player_pos[0] = 0;
	init->player_pos[1] = 0;
	init->player_dir[0] = 0;
	init->player_dir[1] = 0;
	init->map_size[0] = 0;
	init->map_size[1] = 0;
	init->plane_direct[0] = 0;
	init->plane_direct[1] = 0;
}

void	map_stat_init(t_map_conf *init, t_bitmap *cl_color,
		t_bitmap *fl_color)
{
	stats_zero(init);
	init->no_txtr_path = NULL;
	init->so_txtr_path = NULL;
	init->we_txtr_path = NULL;
	init->ea_txtr_path = NULL;
	init->itm_txtr_path = NULL;
	init->color = NULL;
	init->map = NULL;
	init->map_grid = NULL;
	init->item_pos = NULL;
	init->map_stat = 0;
	cl_color->clrfull = 0;
	fl_color->clrfull = 0;
}

void	strcolor_reset(t_map_conf *init)
{
	memreset((void **)&(*(init->color)));
	memreset((void **)&(*(init->color + 1)));
	memreset((void **)&(*(init->color + 2)));
	memreset((void **)&init->color);
}
