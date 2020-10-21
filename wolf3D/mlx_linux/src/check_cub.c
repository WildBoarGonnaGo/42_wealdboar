/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 23:24:18 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/21 15:42:19 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"
#include "../include/colors.h"
#include "../include/maze3d.h"

void			resolution_def(t_map_conf *cub_stat)
{
	int	i;

	i = -1;
	if ((cub_stat->arr_size = check_arr_size(cub_stat->info_handle)) < 3)
	{
		while (++i < cub_stat->arr_size)
			memreset((void **)(cub_stat->info_handle + i));
		memreset((void **)&cub_stat->info_handle);
		memreset((void **)&cub_stat->arr_purge);
		ft_putstr_fd("Error.\nNot enough resolution data to compute further.\n", 2);
		exit(-1);
	}
	cub_stat->width = ft_atoi(*(cub_stat->info_handle + 1));
	cub_stat->height = ft_atoi(*(cub_stat->info_handle + 2));
	cub_stat->map_stat |= (1 << 7);
}

void			def_map_stats(t_map_conf *cub_stat, char *line,
				t_bitmap *cl_color, t_bitmap *fl_color)
{
	if (!ft_strncmp("R", *cub_stat->info_handle, 1))
		resolution_def(cub_stat);
	else if (!ft_strncmp("NO", *cub_stat->info_handle, 2))
		check_if_texture_ex(*(cub_stat->info_handle + 1),
		&cub_stat->no_txtr_path, cub_stat, 0);
	else if (!ft_strncmp("SO", *cub_stat->info_handle, 2))
		check_if_texture_ex(*(cub_stat->info_handle + 1),
		&cub_stat->so_txtr_path, cub_stat, 1);
	else if (!ft_strncmp("WE", *cub_stat->info_handle, 2))
		check_if_texture_ex(*(cub_stat->info_handle + 1),
		&cub_stat->we_txtr_path, cub_stat, 2);
	else if (!ft_strncmp("EA", *cub_stat->info_handle, 2))
		check_if_texture_ex(*(cub_stat->info_handle + 1),
		&cub_stat->ea_txtr_path, cub_stat, 3);
	else if (!ft_strncmp("S", *cub_stat->info_handle, 1))
		check_if_texture_ex(*(cub_stat->info_handle + 1),
		&cub_stat->itm_txtr_path, cub_stat, 4);
	else if (!ft_strncmp("F", *cub_stat->info_handle, 1))
		color_define(cub_stat, fl_color, &cub_stat->flr_color, 5);
	else if (!ft_strncmp("C", *cub_stat->info_handle, 1))
		color_define(cub_stat, cl_color, &cub_stat->ceil_color, 6);
	else if (!**cub_stat->info_handle)
		line_info_reset(cub_stat);
	else
		map_build(cub_stat, line);
}

t_map_conf		map_init_input(char *path)
{
	char        *line;
	t_map_conf	cub_stat;
	t_bitmap	cl_color;
	t_bitmap	fl_color;

	map_stat_init(&cub_stat, &cl_color, &fl_color);
	check_cub_ext(path);
    check_filepath(path);
    cub_stat.file_dscrptr = open(path, O_RDONLY);
	while ((get_next_line(cub_stat.file_dscrptr, &line)) > 0)
    {
		line_def(line, &cub_stat);
		cub_stat.arr_purge = line;
		def_map_stats(&cub_stat, line, &cl_color, &fl_color);
		cub_stat_clean(&cub_stat);
    }
	cub_stat_clean(&cub_stat);
	if (!err_check_input(cub_stat))
	{
		map_conf_reset(&cub_stat);
		exit (-1);
	}
	close(cub_stat.file_dscrptr);
    return (cub_stat);
}
