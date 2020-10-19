/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:37:56 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/19 18:09:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZE3D_H
# define MAZE3D_H

# include <string.h>
# include <libft.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# include "colors.h"
# include <libft.h>
# include <math.h>

# define STRT_DIR 2 * M_PI
# define FOV_PROJ_LEN 0.6494075931975106
# define DELTA_ANGL 0.6 * M_PI / 180
# define WALK_DIST 0.025
# define ESC 65307
# define LEFT_ARROW 65361
# define RIGHT_ARRROW 65363

typedef	struct			s_line
{
	int			x_strt;
	int			y_strt;
	int			x_end;
	int			y_end;
	int			x_roll;
	int			y_roll;
	double		dl;
	double		l;
	double		dx;
	double		dy;
	double 		alpha;
}						t_line;

typedef struct			s_img_info
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}						t_img_info;

typedef	struct			s_map_conf
{
	int			file_dscrptr;
	int			width;
	int			height;
	t_bitmap	flr_color;
	t_bitmap	ceil_color;
	int			map_stat;
	int			**map_grid;
	int			slot;
	int			map_size[2];
	int			player_pos[2];
	int			item_count;
	double		player_dir[2];
	double		plane_direct[2];
	double		**item_pos;
	char		**info_handle;
	char		*no_txtr_path;
	char		*so_txtr_path;
	char		*we_txtr_path;
	char		*ea_txtr_path;
	char		*itm_txtr_path;
	char		**color;
	char		**map;
}						t_map_conf;

typedef	struct			s_route_pass
{
	int					x;
	int					y;
	double				dir;
	struct s_route_pass	*next;
	struct s_route_pass	*prev;
}						t_route_pass;

typedef struct			s_raycast
{
	void				*xorg;
	void				*winx;
	double				pos[2];
	int					map_pos[2];
	int					map_size[2];
	double				plane_vctr[2];
	double				player_dir[2];
	double				proj_vect[2];
	double				xrender;
	double				trvl_bound[2];
	double				trvl_through[2];
	double				strafe[2];
	double				xrender_pos;
	double				text_render_step;
	double				yinit_render_pos;
	double				**item_pos;
	double				item_count;
	double				new_cs_pos[2];
	double				*z_buffer_tank;
	int					pxl_itm_xpos;
	int					xrender_itm_strt;
	int					xrender_itm_end;
	int					hit_detect;
	int					bmp_text_pos[2];
	int					grid_step[2];
	int					height;
	int					width;
	int					what_size;
	int					save_option;
	double				wall_dist;
	double				item_rel_pos[2];
	int					wall_height;
	int					wall_ceil;
	int					wall_floor;
	int					x_stripe;
	int					**map;
	int					txtr_itm_wratio;
	t_bitmap			clr_wall_draw;
	t_bitmap			clr_general;
	t_bitmap			clr_floor;
	t_bitmap			clr_ceil;
	t_img_info			img_rndr;
	t_bitmap_pic_info	north_txtr;
	t_bitmap_pic_info	south_txtr;
	t_bitmap_pic_info	east_txtr;
	t_bitmap_pic_info	west_txtr;
	t_bitmap_pic_info	item_txtr;
	t_bitmap_pic_info	texture;
}						t_raycast;

void					memreset(void **mem);
void					*memrealloc(void *mem, int oldsize, int addbyte);
int						check_filepath(char *path);
t_map_conf				map_init_input(char *path);
t_route_pass			*create_list(int x, int y);
t_route_pass			*add_frwrd(t_route_pass *cur_list, int x, int y);
int						data_exist(t_route_pass *init, int x, int y);
void					purge_list(t_route_pass *init);
int						map_ansys(t_map_conf obj);
void					calc_map_size(t_map_conf *obj);
int						impostor_map(t_map_conf *obj);
int						write_bmp_file(char *filename, t_raycast obj_gl);
int						keymap_interface(int keycode, t_raycast *scene_chng);
void					insertion_sort(t_raycast *obj_gl);
void					draw_item_text(t_raycast *obj_gl);
void					draw_skyline(int x, t_raycast obj_gl);
void					init_rndr_vars(int x, t_raycast *render_tools);
void					dir_define(t_raycast *render_tools);
void					ray_strike(t_raycast *render_tools);
int						save_state(t_raycast *render_tools);
int						render_scene(t_raycast *render_tools);
void					init_render_tools(t_map_conf src, t_raycast *dst);
int             		check_filepath(char *path);
void            		map_stat_init(t_map_conf *init, t_bitmap *cl_color,
						t_bitmap *fl_color);
void					strcolor_reset(t_map_conf *init);
void					check_if_texture_ex(char *filepath, char **texture,
						int *map_stat, int offset);
void					color_define(t_map_conf *cub_stat, t_bitmap *color,
						t_bitmap *trgt);
void					line_def(char *line, t_map_conf *cub_stat);
void					map_build(t_map_conf *cub_stat, char *line);
void					line_info_reset(t_map_conf *cub_stat);
void					imp_map_info_reset(t_map_conf *obj);
void					opengl_pixel_put(t_img_info *stdput, int x,
						int y, unsigned int color);
t_line					line_init(int x_0, int y_0, int x_1, int y_1);
void					line_output(t_img_info *line_img, t_line trgt, 
						unsigned int color);

#endif
