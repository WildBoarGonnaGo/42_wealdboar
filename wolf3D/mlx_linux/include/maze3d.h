/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:37:56 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/24 01:10:18 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZE3D_H
# define MAZE3D_H

# include <string.h>
# include <libft.h>
# include <fcntl.h>
# include "mlx.h"
# include "colors.h"
# include "libft.h"
# include <math.h>

# define STRT_DIR 2 * M_PI
# define FOV_PROJ_LEN 0.6494075931975106
# define DELTA_ANGL 0.75 * M_PI / 180
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
	double		alpha;
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
	int			arr_size;
	t_bitmap	flr_color;
	t_bitmap	ceil_color;
	int			map_stat;
	int			**map_grid;
	int			slot;
	int			map_size[2];
	int			max_res[2];
	int			player_pos[2];
	int			item_count;
	int			player_indx;
	double		player_dir[2];
	double		plane_direct[2];
	double		**item_pos;
	char		**info_handle;
	char		*arr_purge;
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
t_map_conf				map_init_input(char *path, int *max_res);
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
void					init_render_tools(t_map_conf *src, t_raycast *dst);
int						check_filepath(char *path);
void					map_stat_init(t_map_conf *init, t_bitmap *cl_color,
						t_bitmap *fl_color, int *max);
void					strcolor_reset(t_map_conf *init);
void					check_if_texture_ex(char *filepath, char **texture,
						t_map_conf *cub_stat, int offset);
void					color_define(t_map_conf *cub_stat, t_bitmap *color,
						t_bitmap *trgt, int offset);
void					line_def(char *line, t_map_conf *cub_stat);
void					map_build(t_map_conf *cub_stat, char *line);
void					line_info_reset(t_map_conf *cub_stat);
void					imp_map_info_reset(t_map_conf *obj);
void					opengl_pixel_put(t_img_info *stdput, int x,
						int y, unsigned int color);
t_line					line_init(int x_0, int y_0, int x_1, int y_1);
void					line_output(t_img_info *line_img, t_line trgt,
						unsigned int color);
int						err_check_input(t_map_conf obj);
int						check_arr_size(char **arr);
void					color_split_error(t_map_conf *cub_stat);
void					map_build_error(t_map_conf *cub_stat);
void					cub_stat_clean(t_map_conf *cub_stat);
void					map_conf_reset(t_map_conf *cub_stat);
void					raycast_memalloc_err(t_raycast *obj_gl,
						t_map_conf *obj);
void					raycast_exit_proc_mid(t_raycast *obj_gl,
						t_map_conf *obj);
void					raycast_exit_proc_fin(t_raycast *obj_gl);
int						read_bitmap_file(char *filename,
						t_bitmap_pic_info *img_info,
						t_map_conf *cub_stat, t_raycast *obj_gl);
void					check_cub_ext(char *filename);
void					check_bmp_ext(char *filename, t_raycast *obj_gl,
						t_map_conf *cub_stat);
void					item_vars_base(t_raycast *obj_gl, double trans_factor,
						int i, double *old_value);
void					ew_case(t_map_conf *obj, int dir_factor);
void					ns_case(t_map_conf *obj, int dir_factor);
void					map_grid_reset(t_map_conf *obj, int *pos);
void					err_invalid_char(t_map_conf *obj, int *pos);
void					player_pos_ansys(int *pos, t_map_conf *obj);
void					err_invalid_player(t_map_conf *obj, int *pos);
void					path_exit(void);
void					max_res_config(t_map_conf *obj);
void					save_option_true(t_raycast *scene_rndr);

#endif
