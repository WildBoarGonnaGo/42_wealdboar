/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:36:26 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/05 01:09:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*typedef struct	mlx_struct
{
	void		*xorg;
	void		*winx;
	void		*rel_img;
	void		*old_img;
}*/				obj_gl;

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

/*
typedef struct		sign_info
{
	unsigned short	fd;
	unsigned short	indx;
	unsigned short	frmt_signature; //115
	unsigned int	file_size;
	unsigned short	reserve_1;
	unsigned short	reserve_2;
	unsigned int	pyxel_pos_offset;
	unsigned int	struct_size;
	unsigned int	width;
	unsigned int	height;
	unsigned short	plane;
	unsigned short	bites_per_pixel;
	unsigned int	comress;
	unsigned int	size_image;
	unsigned int	xpix_per_meter;
	unsigned int	ypix_per_meter;
	unsigned int	clr_table;
	unsigned int	clr_sockets;
	unsigned int	padded_row;
	unsigned int	unpadded_row;
	unsigned int	img_size;	
	unsigned char	*pyxel_map;
}					bitmap_pic_info;
*/

/*
	_line			line_init(int x_0, int y_0, int x_1, int y_1);
	void			line_output(img_info *line_img, _line trgt, unsigned int color);
 * */

void			draw_skyline(int x, raycast obj_gl)
{
	_line	skyline;

	skyline = line_init(x, 0, x, (int)(obj_gl.height / 2 - 1));
	line_output(obj_gl.img_rndr, skyline, obj_gl.clr_ceil._clrfull);
	skyline = line_init(x, (int)(obj_gl.height / 2), x, obj_gl.height - 1);
	line_output(obj_gl.img_rndr, skyline, obj_gl.clr_ceil._clrfull);
}	

void			insertion_sort(raycast *obj_gl)
{
	double	key[3];
	int		i;
	int		j;

	i = -1;
	while (++indx < obj_gl->item_count)
		obj_gl->item_pos[i][2] = pow(obj_gl->item_pos[i][0] - obj_gl->pos[0], 2)
		+ pow(obj_gl->item_pos[i][1] - obj_gl->pos[1], 2);
	i = -1;
	while (++i < obj_gl->item_pos)
	{
		key[0] = obj_gl->item_pos[i][0];
		key[1] = obj_gl->item_pos[i][1];
		key[2] = obj_gl->item_pos[i][2];
		j = i;
		while (--j >= 0 && obj_gl->item_pos[j][2] > key)
		{
			obj_gl->item_pos[j + 1][0] = obj_gl->item_pos[j][0];
			obj_gl->item_pos[j + 1][1] = obj_gl->item_pos[j][1];
			obj_gl->item_pos[j + 1][2] = obj_gl->item_pos[j][2];
		}
		obj_gl->item_pos[j + 1][0] = key[0];
		obj_gl->item_pos[j + 1][1] = key[1];
		obj_gl->item_pos[j + 1][2] = key[2];
	}
}

void			draw_item_text(int x, raycast *obj_gl)
{
	int		i;
	double	trans_factor;
	double	old_value;

	i = -1;
	insertion_sort(obj_gl);
	trans_factor = 1 / (obj_gl->player_dir[1] * obj_gl->plane_vctr[0]
	- obj_gl->player_dir[0] * obj_gl->plane_vctr[1]);
	while (++i < obj_gl->item_count)
	{	
		obj_gl->new_cs_pos[0] = obj_gl->item_pos[i][0] - obj_gl->pos[0];
		obj_gl->new_cs_pos[1] = obj_gl->item_pos[i][1] - obj_gl.pos[1];
		old_value = obj_gl->new_cs_pos[0];
		obj_gl->new_cs_pos[0] = trans_factor * (obj_gl.new_cs_pos[0] * obj_gl.player_dir[1]
		- obj_gl->new_cs_pos[1] * obj_gl.player_dir[0]);
		obj_gl->new_cs_pos[1] = trans_factor * (-old_value * obj_gl.plane_vctr[1]
		+ obj_gl->new_cs_pos[1] * obj_gl.plane_vctr[0]);
		obj_gl->pxl_itm_xpos = (int)(obj_gl.width * (1 + obj_gl.new_cs_pos[0] / obj_gl.new_cs_pos[1]) / 2);
		obj_gl.wall_height = (int)abs(obj_gl.height / obj_gl.new_cs_pos[1]);
		obj_gl.wall_ceil = (((obj_gl.height - obj_gl.wall_height) / 2) < 0) ? 0 :
		(obj_gl.height - obj_gl.wall_height) / 2;
		obj_gl.wall_floor = (((obj_gl.height + obj_gl.wall_height) / 2) > obj_gl.height - 1)
		? obj_gl.height - 1: (obj_gl.height + obj_gl.wall_height) / 2; 
		obj_gl.txtr_itm_wratio = obj_gl.wall_height;
		obj_gl.xrender_itm_strt = (((obj_gl.pxl_itm_xpos - obj_gl.txtr_itm_wratio) / 2) < 0) ? 0 :
		(obj_gl.pxl_itm_xpos - obj_gl.txtr_itm_wratio) / 2;
		obj_gl.xrender_itm_end = (((obj_gl.pxl_itm_xpos + obj_gl.txtr_itm_wratio) / 2)
		> obj_gl.width - 1) ? obj_gl.width - 1 : (obj_gl.height + obj_gl.wall_height) / 2;
		obj_gl.x_stripe = obj_gl.xrender_itm_strt;
		obj_gl.text_render_step = (double)obj_gl.item_txtr.height / obj_gl.wall_height;
		obj_gl.yinit_render_pos = (obj_gl.wall_ceil - ((obj_gl.height - obj_gl.wall_height) / 2))
		old_value = obj_gl.yinit_render_pos;
		* obj_gl.text_render_step;
		while (obj_gl.x_stripe < obj_gl.xrender_itm_end)
		{
			obj_gl.xrender = (obj_gl.x_stripe - ((obj_gl.pxl_itm_xpos - obj_gl.txtr_itm_wratio) / 2))
			* obj_gl.item_txtr.width / obj_gl.txtr_itm_wratio;
			obj_gl.bmp_text_pos[0] = (int)xrender & (obj_gl.item_txtr.width - 1);
			if (obj_gl.new_cs_pos[1] > 0 && x_stripe > 0 && x_stripe < obj_gl.width
			&& obj_gl.z_buffer_tank[x_stripe] > obj_gl.new_cs_pos[1])
				while (obj_gl.wall_ceil < obj_gl.wall_floor)
				{
					obj_gl.bmp_text_pos[1] = (int)obj_gl.yinit_render_pos & (obj_gl.item_txtr.height - 1);
					obj_gl.clr_general._clrfull = *(unsigned int *)(obj_gl.item_txtr.pyxel_map + 
					obj_gl.item_txtr.unpadded_row * obj_gl.bmp_text_pos[1] +
					obj_gl.bmp_text_pos[0] * obj_gl.item_txtr.bites_per_pixel / 8);
					*(unsigned int *)(obj_gl.img_info.addr + (obj_gl.wall_ceil++) * obj_gl.img_info.line_size + 
					obj_gl.x_stripe * obj_gl.img_info.bits_per_pixel / 8) = obj_gl.clr_general._clrfull;
					obj_gl.yinit_render_pos += obj_gl.text_render_step;
				}
			++obj_gl.x_stripe;
			obj_gl.yinit_render_pos = old_value;
		}
	}
}

int				render_scene(raycast *render_tools)
{
	//_line	vert_draw;
	int		x;
		
	render_tools->img_rndr.img = mlx_new_image(render_tools->xorg, render_tools->width, render_tools->height);
	render_tools->img_rndr.addr = mlx_get_data_addr(render_tools->img_rndr.img,
	&render_tools->img_rndr.bits_per_pixel, &render_tools->img_rndr.line_size, 
	&render_tools->img_rndr.endian); 
	mlx_clear_window(render_tools->xorg, render_tools->winx);
	x = -1;
	while (++x < render_tools->width)
	{
		/*at first draw skyline*/
		draw_skyline(x, *render_tools);
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
			/*Check if there is an item*/
			if (render_tools->map[render_tools->map_pos[0]][render_tools->map_pos[1]] == 2
			&& !render_tools->item_found)
			{
				render_tools->item_found = 1;
				render_tools->item_pos[0] = render_tools->map_pos[0];
				render_tools->item_pos[1] = render_tools->map_pos[1];
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
		/*render_tools->xrender_pos represents the exact value where the wall was hit*/
		render_tools->xrender_pos = (!render_tools->what_size) ? render_tools->pos[1] + render_tools->wall_dist
		* render_tools->proj_vect[1] : render_tools->pos[0] + render_tools->wall_dist * render_tools->proj_vect[0];
		/*Let's calculate the ratio position about the init texture bmp coordinates {0, 0}*/
		render_tools->xrender_pos -= floor(render_tools->xrender_pos);
		/*render_tools->bmp_text_pos[0] - relative bmp texture x-coordinate
		  render_tools->bmp_text_pos[1] - relative bmp texture y-coordinate
		 Let's calculate these coordinates*/
		render_tools->bmp_text_pos[0] = (render_tools->xrender_pos * render_tools->texture.width);
		/*There are some unique situation, when texture coordinates need to be corrected, due the 
		 opposite walls must be mirrored*/
		if ((!render_tools->what_size && render_tools->proj_vect[0] > 0) || 
		(render_tools->what_size == 1 && render_tools->proj_vect[1] < 0))
			render_tools->bmp_text_pos[0] = render_tools->texture.width - 1 - render_tools->bmp_text_pos[0];
		/*render_tools->text_render_step - texture step to draw certain pixel, depending on ratio below*/
		render_tools->text_render_step = (double)render_tools->texture.height / render_tools->wall_height;
		/*Now let's find out what pixel to draw we need to start. That's why we need render_tools->bmp_text_pos[1]*/
		render_tools->yinit_render_pos = (render_tools->wall_ceil - (render_tools->height /2
		- render_tools->wall_height/2)) * render_tools->text_render_step;
		while (render_tools->wall_ceil < render_tools->wall_floor)
		{
			render_tools->bmp_text_pos[1] = (int)render_tools->yinit_render_pos & (render_tools->texture.height - 1);
			render_tools->clr_general._clrfull = *(unsigned int *)(render_tools->texture.pyxel_map
			+ render_tools->bmp_text_pos[1] * render_tools->texture.unpadded_row
			+ render_tools->bmp_text_pos[0] * render_tools->texture.bites_per_pixel / 8);
			render_tools->clr_wall_draw = (!render_tools->what_size) ? render_tools->clr_general :
			add_shade(0.5, render_tools->clr_general);
			*(unsigned int *)(render_tools->img_rndr.addr + (render_tools->wall_ceil++)
			* render_tools->img_rndr.line_size + x * render_tools->img_rndr.bits_per_pixel / 8)
			= render_tools->clr_wall_draw._clrfull;
			render_tools->yinit_render_pos += render_tools->text_render_step;
		}
		dst->z_buffer_tank[x] = render_tools->wall_dist;
		//line_init(&vert_draw, x, render_tools->wall_ceil, x, render_tools->wall_floor);
		//line_output(&render_tools->img_rndr, vert_draw, render_tools->clr_wall_draw._clrfull);
	}

	mlx_put_image_to_window(render_tools->xorg, render_tools->winx, render_tools->img_rndr.img, 0, 0);
	if (render_tools->img_rndr.img)
		mlx_destroy_image(render_tools->xorg, render_tools->img_rndr.img);
	render_tools->state = 0;
	return (1);
}

void	init_render_tools(map_conf src, raycast *dst)
{
	dst->width = src.width;
	dst->height = src.height;
	dst->pos[0] = src.player_pos[0];
	dst->pos[1] = src.player_dos[1];
	dst->player_dir[0] = src.player_dir[0];
	dst->player_dir[1] = src.player_dir[1];
	dst->plane_vctr[0] = src.plane_direct[0];
	dst->plane_vctr[1] = src.plane_direct[1];
	dst->map_size[0] = src.map_size[0];
	dst->map_size[1] = src.map_size[1];
	dst->map = src.map_grid;
	dst->img_rndr.winx = NULL;
	dst->img_rndr.xorg = NULL;
	read_bitmap_file(src.no_txtr_path, &dst->north_txtr);
	read_bitmap_file(src.so_txtr_path, &dst->south_txtr);
	read_bitmap_file(src.ea_txtr_path, &dst->east_txtr);
	read_bitmap_file(src.we_txtr_path, &dst->west_txtr);
	read_bitmap_file(src.itm_txtr_path, &dst->item_txtr);
	dst->clr_floor = src.fl_color;
	dst->clr_ceil = src.cl_color;
	dst->item_count = src.item_count;
	dst->item_pos = src.item_pos;
	dst->z_buffer_tank = (double *)malloc(sizeof(double) * dst->width);
}

int		main(int argc, char *argv[])
{
	map_conf			cub_file_info;
	raycast				scene_rndr;
	int			pos[2];

	if (argc != 2)
	{
		perror("Error\n");
		return (0);
	}
	if (!(cub_file_info = map_init_input(argv[1])))
	{
		perror("Error\n");
		return (0);
	}
	calc_map_size(&cub_file_info);	
	impostor_map(&cub_file_info);
	if (!map_ansys(cub_file_info))
	{
		perror("Error\n");
		return (-1);
	}
		
	pos[0] = 0;
	pos[1] = -1;
	scene_rndr.player_dir[0] = 1;
	scene_rndr.player_dir[1] = 0;
	scene_rndr.plane_vctr[0] = 0;
	scene_rndr.plane_vctr[1] = 0.66;
	scene_rndr.img_rndr.img = NULL;
	scene_rndr.img_rndr.addr = NULL;
	scene_rndr.xorg = mlx_init();
	scene_rndr.winx = mlx_new_window(scene_rndr.xorg, scene_rndr.width, scene_rndr.height, "Maze Raycaster");
	/*MAP INIZIALIZATION*/
	read_bitmap_file("/home/lchantel/texture_pack/wall_text_10_512.bmp", &scene_rndr.texture);
	scene_rndr.map = (int **)malloc(sizeof(int *) * test_map.map_size[0]);
	/*while (pos[0] < test_map.map_size[0])
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
	}*/
	scene_rndr.map_size[0] = test_map.map_size[0];
	scene_rndr.map_size[1] = test_map.map_size[1];
	set_color(&scene_rndr.clr_general, 128, 47, 225, 185);
	mlx_hook(scene_rndr.winx, 2, 1L<<0, move_sight, &scene_rndr);
	mlx_loop_hook(scene_rndr.xorg, render_scene, &scene_rndr);
	
	mlx_loop(scene_rndr.xorg);
}
