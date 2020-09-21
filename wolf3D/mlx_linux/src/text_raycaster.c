/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:36:26 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/20 08:22:01 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 typedef struct  data
{
    int         file_dscrptr;
    int         width;
    int         height;
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
}               map_conf;

 * */

#include <math.h>
#include <mlx.h>
#include <geoms.h>
#include "../include/colors.h"
#include "../include/wolf3D.h"
#include <stdio.h>

#define	DELTA_ANGL 0.5 * M_PI / 180
#define	WALK_DIST 0.04
#define ESC 65307
#define KEY_PRESS_EVENT 1L<<0
#define KEY_PRESS_IDENT 2


typedef struct	mlx_struct
{
	void		*xorg;
	void		*winx;
	void		*rel_img;
	void		*old_img;
}				obj_gl;

typedef struct		instruments
{
	void			*xorg;
	void			*winx;
	double			pos[2];
	int				map_pos[2];
	int				map_size[2];
	double			plane_vctr[2];
	double			player_dir[2];
	double			proj_vect[2];
	double			xrender;
	double			trvl_bound[2];
	double			trvl_through[2];
	int				hit_detect;
	int				grid_step[2];
	int				height;
	int				width;
	/*info about what side of the wall was hit: NS (North-South) or EW (East-West)*/
	int				what_size;
	/*perpendicular distance to the wall, depending on the hit direction*/	
	double			wall_dist;
	int				wall_height;
	int				wall_ceil;
	int				wall_floor;
	int				x_stripe;
	int				**map;
	int				state;
	bitmap			clr_wall_draw;
	bitmap			clr_general;
	img_info		img_rndr;
}					raycast;

void    memreset(void **mem)
{
    if (*mem)
    {
        free(*mem);
        *mem = NULL;
    }
}

void	print_matrix(raycast obj_gl)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < obj_gl.map_size[0])
	{
		while (++j < obj_gl.map_size[1])
			(j < obj_gl.map_size[1] - 1) ? printf("%d ", obj_gl.map[i][j]) : printf("%d\n", obj_gl.map[i][j]);
		j = -1;
	}
}
/*raycast			render_frame_init(map_conf info)
{
	raycast	cur_frame;

	cur_frame.cur_pos[0] = info.pos[0];
	cur_frame.cur_pos[1] = info.pos[1];
	cur_frame.plane_vctr[0] = 0;
	cur_frame.plane_vctr[1] = 0.66;
	cur_frame.player_dir[0] = 1;
	cur_frame.player_dir[1] = 0;
	cur_frame.xrender = 0;
	
	return (cur_frame);
}*/

/*RAYCASTING ALGORITHM*/

int				move_sight(int keycode, raycast *scene_chng)
{
	double	old_vect_x;
	double	old_plane_x;
	int		i;

	i = 0;
	old_vect_x = scene_chng->player_dir[0];
	old_plane_x = scene_chng->plane_vctr[0];
	if (keycode == 'w' || keycode == 'W')
	{
		scene_chng->pos[0] += (!scene_chng->map[(int)floor(scene_chng->pos[0] + WALK_DIST * 
		scene_chng->player_dir[0])][(int)floor(scene_chng->pos[1])]) ? WALK_DIST * scene_chng->player_dir[0] : 0;
		scene_chng->pos[1] += (!scene_chng->map[(int)floor(scene_chng->pos[0])][(int)floor(scene_chng->pos[1] 
		+ WALK_DIST * scene_chng->player_dir[1])]) ? WALK_DIST * scene_chng->player_dir[1] : 0;
		scene_chng->state = 1;
		//printf("%d\n", keycode);
	}
	else if (keycode == 's' || keycode == 'S')
	{
		scene_chng->pos[0] -= (!scene_chng->map[(int)floor(scene_chng->pos[0] - WALK_DIST * 
		scene_chng->player_dir[0])][(int)floor(scene_chng->pos[1])]) ? WALK_DIST * scene_chng->player_dir[0] : 0;
		scene_chng->pos[1] -= (!scene_chng->map[(int)floor(scene_chng->pos[0])][(int)floor(scene_chng->pos[1] 
		- WALK_DIST * scene_chng->player_dir[1])]) ? WALK_DIST * scene_chng->player_dir[1] : 0;
		scene_chng->state = 1;
		//printf("%d\n", keycode);
	}
	else if (keycode == 'a' || keycode == 'A')
	{
		scene_chng->player_dir[0] = scene_chng->player_dir[0] * cos(-DELTA_ANGL) - scene_chng->player_dir[1] * sin(-DELTA_ANGL);
		scene_chng->player_dir[1] = old_vect_x * sin(-DELTA_ANGL) + scene_chng->player_dir[1] * cos(-DELTA_ANGL);
		scene_chng->plane_vctr[0] = scene_chng->plane_vctr[0] * cos(-DELTA_ANGL) - scene_chng->plane_vctr[1] * sin(-DELTA_ANGL);
		scene_chng->plane_vctr[1] = old_plane_x * sin(-DELTA_ANGL) + scene_chng->plane_vctr[1] * cos(-DELTA_ANGL);
		scene_chng->state = 1;
		//printf("%d\n", keycode);
	}
	else if (keycode == 'd' || keycode == 'D')
	{
		scene_chng->player_dir[0] = scene_chng->player_dir[0] * cos(DELTA_ANGL) - scene_chng->player_dir[1] * sin(DELTA_ANGL);
		scene_chng->player_dir[1] = old_vect_x * sin(DELTA_ANGL) + scene_chng->player_dir[1] * cos(DELTA_ANGL);
		scene_chng->plane_vctr[0] = scene_chng->plane_vctr[0] * cos(DELTA_ANGL) - scene_chng->plane_vctr[1] * sin(DELTA_ANGL);
		scene_chng->plane_vctr[1] = old_plane_x * sin(DELTA_ANGL) + scene_chng->plane_vctr[1] * cos(DELTA_ANGL);
		scene_chng->state = 1;
		//printf("%d\n", keycode);
	}
	else if (keycode == ESC)
	{
		mlx_clear_window(scene_chng->xorg, scene_chng->winx);
		mlx_destroy_image(scene_chng->winx, scene_chng->img_rndr.img);
		//mlx_destroy_image
		while (i < scene_chng->map_size[0])
			memreset((void **)*(scene_chng->map + i));
		memreset((void **)scene_chng->map);
		mlx_destroy_window(scene_chng->xorg, scene_chng->winx);
		exit(0);
	}
	printf("%d\n", keycode);
	return (1);
}

/*
 *typedef struct	bit_struct
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				img_info;

 * */

int				render_scene(raycast *render_tools)
{
	_line	vert_draw;
	int		x;
	
	if (render_tools->img_rndr.img)
		mlx_destroy_image(render_tools->xorg, render_tools->img_rndr.img);
	render_tools->img_rndr.img = mlx_new_image(render_tools->xorg, render_tools->width, render_tools->height);
	mlx_clear_window(render_tools->xorg, render_tools->winx);
	//mlx_destroy_image(_config->xorg, _config->old_img);
	x = -1;
	while (++x < render_tools->width)
	{
		/*calculate ray position and direction
		x coordinate in camera space
		xrender - x-coordinate in camera space
		proj_vect[0] - x projection of result vector
		proj_vect[1] - y projection of result vecto*/
		
		render_tools->xrender = 2 * x / (double)render_tools->width - 1;
		render_tools->proj_vect[0] = render_tools->player_dir[0] + render_tools->xrender * render_tools->plane_vctr[0];
		render_tools->proj_vect[1] = render_tools->player_dir[1] + render_tools->xrender * render_tools->plane_vctr[1];

		/* Which box of the map we're in
		 map_pos[0] - start x coordinate of player
		 map_pos[1] - start y coordinate of player*/
		render_tools->map_pos[0] = (int)floor(render_tools->pos[0]);
		render_tools->map_pos[1] = (int)floor(render_tools->pos[1]);
		
		/*x and y projecton of vectors from one side of box to another*/
		render_tools->trvl_through[0] = (!render_tools->proj_vect[1]) ? 0 : fabs(1 / render_tools->proj_vect[0]);
		render_tools->trvl_through[1] = (!render_tools->proj_vect[0]) ? 0 : fabs(1 / render_tools->proj_vect[1]);
		/*hit_detect - was wall hit
		 trvl_bound[0] - x projection of ray to box boundary
		 trvl_bound[1] - y projection of ray to box boundary*/
		render_tools->hit_detect = 0;
		if (render_tools->proj_vect[0] < 0)
		{
			render_tools->grid_step[0] = -1;
			render_tools->trvl_bound[0] = render_tools->trvl_through[0] * (render_tools->pos[0] - render_tools->map_pos[0]);
		}
		else
		{
			render_tools->grid_step[0] = 1;
			render_tools->trvl_bound[0] = render_tools->trvl_through[0] * (1 -render_tools->pos[0] + render_tools->map_pos[0]);
		}
		if (render_tools->proj_vect[1] < 0)
		{
			render_tools->grid_step[1] = -1;
			render_tools->trvl_bound[1] = render_tools->trvl_through[1] * (render_tools->pos[1] - render_tools->map_pos[1]);
		}
		else
		{
			render_tools->grid_step[1] = 1;
			render_tools->trvl_bound[1] = render_tools->trvl_through[1] * (1 -render_tools->pos[1] + render_tools->map_pos[1]);
		}
		/*Perform DDA*/
		while (!render_tools->hit_detect)
		{
			if (render_tools->trvl_bound[0] < render_tools->trvl_bound[1])
			{
				render_tools->trvl_bound[0] += render_tools->trvl_through[0];
				render_tools->map_pos[0] += render_tools->grid_step[0];
				render_tools->what_size = 0;
			}
			else
			{
				render_tools->trvl_bound[1] += render_tools->trvl_through[1];
				render_tools->map_pos[1] += render_tools->grid_step[1];
				render_tools->what_size = 1;
			}
			/*Check if ray has hit the wall*/
			render_tools->hit_detect = (render_tools->map[render_tools->map_pos[0]][render_tools->map_pos[1]]) ? 1 : 0;
		}
		/*calculate the distance projected in camera direction*/
		if (!render_tools->what_size)
			render_tools->wall_dist = (render_tools->map_pos[0] - render_tools->pos[0] + 
			(1 - render_tools->grid_step[0]) / 2) / render_tools->proj_vect[0];
		else
			render_tools->wall_dist = (render_tools->map_pos[1] - render_tools->pos[1] + 
			(1 - render_tools->grid_step[1]) / 2) / render_tools->proj_vect[1];
		/*height of the wall to draw*/
		render_tools->wall_height = (int)render_tools->height / render_tools->wall_dist;
		render_tools->wall_ceil = ((render_tools->height / 2 - render_tools->wall_height / 2) < 0) ?
		0 : render_tools->height / 2 - render_tools->wall_height / 2;
		render_tools->wall_floor = ((render_tools->height / 2 + render_tools->wall_height / 2) > render_tools->height) ?
		render_tools->height : render_tools->height / 2 + render_tools->wall_height / 2;
		render_tools->clr_wall_draw = (!render_tools->what_size) ? render_tools->clr_general : add_shade(0.5, render_tools->clr_general);
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
		line_init(&vert_draw, x, render_tools->wall_ceil, x, render_tools->wall_floor);
		line_output(&render_tools->img_rndr, vert_draw, render_tools->clr_wall_draw._clrfull);
	}
	mlx_put_image_to_window(render_tools->xorg, render_tools->winx, render_tools->img_rndr.img, 0, 0);
	render_tools->state = 0;
	return (1);
}

int	main(void)
{
	map_conf	test_map;
	raycast		scene_rndr;
	int			pos[2];

	pos[0] = 0;
	pos[1] = -1;
	 
	/*width of screen*/
	scene_rndr.width = 1024;
	/*height of screen*/
	scene_rndr.height = 768;
	/*pos[0] - x position of player
	 *pos[1] - y position of player*/
	scene_rndr.pos[0] = 12;
	scene_rndr.pos[1] = 2;
	/* map_size[0] - x size of map
	 * map_size[1] - y size of map
	 * */
	test_map.map_size[0] = 15;
	test_map.map_size[1] = 15;
	/*
	 * player_dir[0] - x-map direction;
	 * player_dir[1] - y-map direction;
	 * */
	scene_rndr.player_dir[0] = 1;
	scene_rndr.player_dir[1] = 0;
	scene_rndr.plane_vctr[0] = 0;
	scene_rndr.plane_vctr[1] = 0.66;
	scene_rndr.img_rndr.img = NULL;
	scene_rndr.img_rndr.addr = NULL;
	scene_rndr.xorg = mlx_init();
	scene_rndr.winx = mlx_new_window(scene_rndr.xorg, scene_rndr.width, scene_rndr.height, "Maze Raycaster");
	/*MAP INIZIALIZATION*/

	scene_rndr.map = (int **)malloc(sizeof(int *) * test_map.map_size[0]);
	while (pos[0] < test_map.map_size[0])
		*(scene_rndr.map + pos[0]++) = (int *)malloc(sizeof(int) * test_map.map_size[1]);
	pos[0] = -1;
	while (++pos[0] < test_map.map_size[0])
	{
		if (!pos[0] || pos[0] == test_map.map_size[0] - 1)
		{
			while (++pos[1] < test_map.map_size[1])
				*(*(scene_rndr.map + pos[0]) + pos[1]) = 1;
			pos[1] = -1;
			continue ;
		}
		while (++pos[1] < test_map.map_size[1])
				*(*(scene_rndr.map + pos[0]) + pos[1]) = (!pos[1] || pos[1] == 14) ? 
				1 : 0;
		pos[1] = -1;
	}
	scene_rndr.map_size[0] = test_map.map_size[0];
	scene_rndr.map_size[1] = test_map.map_size[1];
	//print_matrix(scene_rndr);
	set_color(&scene_rndr.clr_general, 128, 47, 225, 185);
	//mlx_key_hook(scene_rndr.winx, move_sight, &scene_rndr);
	//if (scene_rndr.state)
	/*
	#define KEY_PRESS_EVENT 1L<<0
	#define KEY_PRESS_IDENT 2
	 * */
	mlx_hook(scene_rndr.winx, 2, 1L<<0, move_sight, &scene_rndr);
	mlx_loop_hook(scene_rndr.xorg, render_scene, &scene_rndr);
	
	mlx_loop(scene_rndr.xorg);
}
