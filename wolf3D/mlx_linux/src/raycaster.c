/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:36:26 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/21 20:50:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "../include/colors.h"
#include "../include/maze3d.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_map_conf	cub_file_info;
	t_raycast	scene_rndr;

	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
		exit (-1);
	}
	cub_file_info = map_init_input(argv[1]);
	calc_map_size(&cub_file_info);	
	impostor_map(&cub_file_info);
	if (!map_ansys(cub_file_info))
	{
		ft_putstr_fd("Error.\nInvalid map to work with.\n", 2);
		exit (-1);
	}
	impostor_map(&cub_file_info);
	init_render_tools(&cub_file_info, &scene_rndr);
	scene_rndr.xorg = mlx_init();
	scene_rndr.winx = mlx_new_window(scene_rndr.xorg, scene_rndr.width, scene_rndr.height, "Maze Raycaster");
	if (argc == 3)
	{
		if (!(ft_strncmp("--save", argv[2], 6)))
		{
			scene_rndr.save_option = 1;
			render_scene(&scene_rndr);
			exit(0);
		}
	}
	mlx_hook(scene_rndr.winx, 2, 1L<<0, keymap_interface, &scene_rndr);
	mlx_loop_hook(scene_rndr.xorg, render_scene, &scene_rndr);
	mlx_loop(scene_rndr.xorg);
}
