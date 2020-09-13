/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:36:26 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/14 00:21:08 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 typedef struct  data
{
    int         file_dscrptr;
    int         width;
    int         height;
    int         resolution;
    int         flr_color;
    int         ceil_color;
    int         map_stat;
	int			**map_grid;
    int         pos[2];
	int			map_size[2];
	double		player_dir[2];
    char        **info_handle;
    char        *no_txtr_path;
    char        *so_txtr_path;
    char        *we_txtr_path;
    char        *ea_txtr_path;
    char        *s_txtr_path;
    char        **color;
    char        **map;
}               map_conf;

 * */

#include "../include/wolf3D"
#include <math.h>
#include <mlx.h>

#define FOV	66 * M_PI / 360

typedef struct	mlx_struct
{
	void		*xorg;
	void		*winx;
	int			left;
	int			right;
	int			frwrd;
	int			back;
	int			lstrf;
	int			rstrf;
}				obj_gl;

typedef struct	instruments
{
	int 		map_pos[2];
	double		plane_vctr[2];
	double		init_dir[2];
	double		pos[2];
	double		proj_vect[2];
	double		xrender;
	double		trvl_bound[2];
	double		trvl_through[2];
	double		raylen;
	double		hit_detect;
}				raycast;

raycast			render_frame(map_conf info)
{
	raycast	cur_frame;

	cur_frame.cur_pos[0] = info.pos[0];
	cur_frame.cur_pos[1] = info.pos[1];
	cur_frame.plane_vctr[0] = 0;
	cur_frame.plane_vctr[1] = 0.66;
	cur_frame.init_dir[0] = info.player_dir[0];
	cur_frame.init_dir[1] = info.player_dir[1];
}

/*RAYCASTING ALGORITHM*/

void			render_scene(raycast render_tools, obj_gl _config, 
				map_conf _info, unsigned int wall_color)
{
	while (render_tools.xrender < _info.width)
	{
		/*calculate ray position and direction
		x coordinate in camera space
		xrender - x-coordinate in camera space
		proj_vect[0] - x projection of result vector
		proj_vect[1] - y projection of result vecto*/
		
		render_tools.xrender = 2 * x / (double)_info.width - 1;
		render_tools.proj_vect[0] = _info.player_dir[0] + render_tools.xrender * plane_vctr[0];
		render_tools.proj_vect[1] = _info.player_dir[1] + render_tools.xrender * plane_vctr[1];

		/* Which box of the map we're in
		 map_pos[0] - start x coordinate of player
		 map_pos[1] - start y coordinate of player*/
		render_tools.map_pos[0] = (int)_info.pos[0];
		render_tools.map_pos[1] = (int)_info.pos[1];
		
		
		/*x and y projecton of vectors from one side of box to another*/
		render_tools.raylen = sqrt(pow(render_tools.proj_vect[0], 2) + pow(render_tools.proj_vect[1], 2));
		render_tools.trvl_through[0] = abs(render_tools.raylen / render_tools.proj_vect[0]);
		render_tools.trvl_through[1] = abs(render_tools.raylen / render_tools.proj_vect[1]);
		/*hit_detect - was wall hit
		 trvl_bound[0] - x projection of ray to box boundary
		 trvl_bound[1] - y projection of ray to box boundary*/
		render_tool.hit_detect = 0;
		if ()
	}	
}

int	main(void)
{
	map_conf	test_map;
	raycast		roller;
	obj_gl		scene_rndr;
	int			pos[2];

	pos[0] = 0;
	pos[1] = -1;
	/*length of screen*/
	test_map.width = 640;
	/*width of screen*/
	test_map.height = 480;
	/*pos[0] - x position of player
	 *pos[1] - y position of player*/
	test_map.pos[0] = 8;
	test_map.pos[1] = 7;
	/* map_size[0] - x size of map
	 * map_size[1] - y size of map
	 * */
	test_map.map_size[0] = 15;
	test_map.map_size[1] = 15;
	/*
	 * player_dir[0] - x-map direction;
	 * player_dir[1] - y-map direction;
	 * */
	scene_rndr.xorg = mlx_init();

	/*MAP INIZIALIZATION*/

	test.map = (int **)malloc(sizeof(int *) * test_map.map_size[0]);
	while (pos[0] < test_map.map_size[0])
		*(test.map + pos[0]++) = (int *)malloc(sizeof(int) * test_map.map_size[1]);
	pos[0] = -1;
	while (++pos[0] < test_map.map_size[0])
	{
		if (!pos[0] || pos[0] == test_map.map_size[0] - 1)
		{
			while (++pos[1] < test_map.map_size[1])
				*(*(test.map + pos[0]) + pos[1]) = 1;
			pos[1] = -1;
			continue ;
		}
		while (++pos[1] < test_map.map_size[1])
				*(*(test_map + pos[0]) + pos[1]) = (!pos[1] || pos[1] == 14) ? 
				1 : 0;
		pos[1] = -1;
	}

	/*RAYCASTING ALGORITHM*/
	
}
