/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:36:26 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/17 05:18:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 typedef struct  data
{
    int         file_dscrptr;
    int         width;
    int         height;
    int         resolution;
    bitmap      flr_color;
    bitmap		ceil_color;
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
    int			**map;
}               map_conf;

 * */

#include "../include/wolf3D"
#include <math.h>
#include <mlx.h>
#include <geoms.h>
#include "../include/colors.h"

#define	DELTA_ANGL 0.1 * M_PI / 180
#define	WALK_DIST 0.05
#define ESC 27
typedef struct	mlx_struct
{
	void		*xorg;
	void		*winx;
	void		*rel_img;
	void		*old_img;
	int			left;
	int			right;
	int			frwrd;
	int			back;
	int			lstrf;
	int			rstrf;
}				obj_gl;

typedef struct	instruments
{
	int				map_pos[2];
	double			plane_vctr[2];
	double			init_dir[2];
	double			proj_vect[2];
	double			xrender;
	double			trvl_bound[2];
	double			trvl_through[2];
	double			raylen;
	int				hit_detect;
	int				grid_step[2];
	/*info about what side of the wall was hit: NS (North-South) or EW (East-West)*/
	int				what_size;
	/*perpendicular distance to the wall, depending on the hit direction*/	
	double			wall_dist;
	int				wall_height;
	int				wall_ceil;
	int				wall_floor;
	int				x_stripe;
	double			angl;
	bitmap			clr_wall_draw;
	bitmap			clr_general;
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
	cur_frame.xrender = 0;

	return (cur_frame);
}

/*RAYCASTING ALGORITHM*/

int				turn_sight(int keycode, raycast *scene_chng, map_conf *plstat, obj_gl *winexec)
{
	double	old_vect_x;
	double	old_plane_x;
	int		i;

	i = 0;
	old_vect_x = scene_chng->player_dir[0];
	old_plane_x = scene_chng->plane_vctr[0];
	if (keycode == "w" || keycode = "W")
	{
		plstat->pos[0] += (!plstat->map[(int)floor(plstat->pos[0] + WALK_DIST * 
		scene_chng->proj_vect[0])][(int)floor(plstat->pos[1])]) ? WALK_DIST * scene_chng->proj_vect[0] : 0;
		plstat->pos[1] += (!plstat->map[(int)floor(plstat->pos[0])][(int)floor(plstat->pos[1] 
		+ WALK_DIST * scene_chng.proj_vect[1])]) ? WALK_DIST * scene_chng->proj_vect[1] : 0;
	}
	else if (keycode == "s" || keycode == "S")
	{
		plstat->pos[0] -= (!plstat->map[(int)floor(plstat->pos[0] - WALK_DIST * 
		scene_chng->proj_vect[0])][(int)floor(plstat->pos[1])]) ? WALK_DIST * scene_chng->proj_vect[0] : 0;
		plstat->pos[1] -= (!plstat->map[(int)floor(plstat->pos[0])][(int)floor(plstat->pos[1] 
		- WALK_DIST * scene_chng.proj_vect[1])]) ? WALK_DIST * scene_chng->proj_vect[1] : 0;
	}
	else if (keycode == "a" || keycode == "A")
	{
		scene_chng->player_dir[0] = scene_chng->player_dir[0] * cos(DELTA_ANGL) - scene_chng->player_dir[1] * sin(DELTA_ANGL);
		scene_chng->player_dir[1] = old_vect_x * sin(DELTA_ANGL) + scene_chng->player_dir[1] * cos(DELTA_ANGL);
		scene_chng->plane_vctr[0] = scene_chng->plane_vctr[0] * cos(DELTA_ANGL) - scene_chng->plane_vctr[1] * sin(DELTA_ANGL);
		scene_chng->plane_vctr[1] = old_plane_x * sin(DELTA_ANGL) + scene_chng->plane_vctr[1] * cos(DELTA_ANGL);
	}
	else if (keycode == "d" || keycode == "D")
	{
		scene_chng->player_dir[0] = scene_chng->player_dir[0] * cos(-DELTA_ANGL) - scene_chng->player_dir[1] * sin(-DELTA_ANGL);
		scene_chng->player_dir[1] = old_vect_x * sin(-DELTA_ANGL) + scene_chng->player_dir[1] * cos(-DELTA_ANGL);
		scene_chng->plane_vctr[0] = scene_chng->plane_vctr[0] * cos(-DELTA_ANGL) - scene_chng->plane_vctr[1] * sin(-DELTA_ANGL);
		scene_chng->plane_vctr[1] = old_plane_x * sin(-DELTA_ANGL) + scene_chng->plane_vctr[1] * cos(-DELTA_ANGL);
	}
	else if (keycode == ESC)
	{
		mlx_clear_window(winexec->xorg, winexec->winx)
		mlx_destroy_image(winexec->winx, winexec->rel_img);
		//mlx_destroy_image
		memreset(winexec->old_img);
		while (i < plstat->map_size[0])
			memreset(*(plstat->map + i));
		memreset(plstat->map);
		
		return (0);
	}
}

int				render_scene(raycast render_tools, obj_gl *_config, 
				map_conf _info)
{
	_line	vert_draw;

	_config->rel_img = mlx_new_image(obj_gl->xorg, _info.width, _info.heigth);
	mlx_clear_window(_config->xorg, _config->winx);
	//mlx_destroy_image(_config->xorg, _config->old_img);
	memreset(&_config->old_img);
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
		render_tools.hit_detect = 0;
		render_tools.map_pos[0] = (int)_info.pos[0];
		render_tools.map_pos[1] = (int)_info.pos[1];
		if (render_tools.proj_vect[0] < 0)
		{
			render_tools.grid_step[0] = -1;
			render_tools.trvl_bound[0] = render_tools.trvl_through[0] * (_info.pos[0] - render_tools.map_pos[0]);
		}
		else
		{
			render_tools.grid_step[0] = 1;
			render_tools.trvl_bound[0] = render_tools.trvl_through[0] * (1 -info.pos[0] + render_tools.map_pos[0]);
		}
		if (render_tools.proj_vect[1] < 0)
		{
			render_tools.grid_step[1] = -1;
			render_tools.trvl_bound[1] = render_tools.trvl_through[1] * (_info.pos[1] - render_tools.map_pos[1]);
		}
		else
		{
			render_tools.grid_step[1] = 1;
			render_tools.trvl_bound[1] = render_tools.trvl_through[1] * (1 -info.pos[1] + render_tools.map_pos[1]);
		}
		/*Perform DDA*/
		while (!render_tools.hit_detect)
		{
			if (abs(render_tools.trvl_bound[0]) < abs(render_tools.trvl_bound[1]))
			{
				render_tools.trvl_bound[0] += render_tools.trvl_through[0];
				render_tools.map_pos[0] += render_tools.grid_step[0];
				render_tools.what_size = 0;
			}
			else
			{
				render_tools.trvl_bound[1] += render_tools.trvl_through[1];
				render_tools.map_pos[1] += render_tools.grid_step[1];
				render_tools.what_size = 1;
			}
			/*Check if ray has hit the wall*/
			render_tools.hit_detect = (_info.map[render_tools.map_pos[0]][render_tools[map_pos[1]]]) ? 1 : 0
		}
		/*calculate the distance projected in camera direction*/
		if (!render_tools.what_size)
			render_tools.wall_dist = (render_tools.map_pos[0] - _info.pos[0] + 
			(1 - render_tools.grid_step[0]) / 2) / render_tools.proj_vect[0];
		else
			render_tools.wall_dist = (render_tools.map_pos[1] - _info.pos[1] + 
			(1 - render_tools.grid_step[1]) / 2) / render_tools.proj_vect[1];
		/*height of the wall to draw*/
		render_tools.wall_height = (int)_info.height / render_tools.wall_dist;
		render_tools.wall_ceil = ((_info.height / 2 - render_tools.wall_height / 2) < 0) ?
		0 : _info.height / 2 - render_tools.wall_height / 2;
		render_tools.wall_floor = ((_info.height / 2 + render_tools.wall_height / 2) > _info.height) ?
		_info.height : _info.height / 2 + render_tools.wall_height / 2;
		render_tools.clr_wall_draw = (!render_tools.what_size) ? render_tools.clr_general : add_shade(0.5, render_tools.clr_general);
		/*
		 void			line_init(_line *init, int x_0, int y_0, int x_1, int y_1)
		{
			init->x_strt = x_0;
			init->y_strt = y_0;
			init->x_end = x_1;
			init->y_end = y_1;
		}

		void			line_output(img_info *line_img, _line trgt, unsigned int color)
		 * */
		line_init(&vert_draw, render_tools.xrender, render_tools.wall_ceil,
		render_tools.xrender, render_tools.clr_wall_draw._clrfull);
		line_output(&_config->rel_img, vert_draw, render_tools.clr_wall_draw._clrfull);
	}
	mlx_put_image_to_window(_config->xorg, )
	config->old_img = config->rel_img;
	return (1);
}

int	main(void)
{
	map_conf	test_map;
	raycast		roller;
	obj_gl		scene_rndr;
	int			pos[2];

	pos[0] = 0;
	pos[1] = -1;
	/*width of screen*/
	test_map.width = 640;
	/*height of screen*/
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
	scene_rndr.winx = mlx_new_window(scene_rndr.xorg, test_map.width, test_map.height, "Maze Raycaster");
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
	
}
