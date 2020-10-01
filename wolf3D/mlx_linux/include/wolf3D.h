/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:37:56 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/02 00:08:49 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include <string.h>
# include <libft.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "colors.h"
# include <math.h>

# define STRT_DIR 2 * M_PI
# define FOV_PROJ_LEN 0.6494075931975106


typedef struct  data
{
    int         file_dscrptr;
    int         width;
    int         height;
    int         resolution;
    bitmap		fl_color;
    bitmap		cl_color;
    int         map_stat;
	int			**map_grid;
	int         slot;
	int			map_size[2];
	int			player_pos[2];
	double		player_dir[2];
	double		plane_direct[2]
	char        **info_handle;
    char        *no_txtr_path;
    char        *so_txtr_path;
    char        *we_txtr_path;
    char        *ea_txtr_path;
    char        *itm_txtr_path;
    char        **color;
    char		**map;
}               map_conf;

typedef	struct			check_list
{
	int					x;
	int					y;
	double				dir;
	struct check_list	*next;
	struct check_list	*prev;	
}						route_pass;

typedef struct			instruments
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
	int					bmp_text_pos[2];
	int					hit_detect;
	int					grid_step[2];
	int					height;
	int					width;
	int					what_size;	
	double				wall_dist;
	int					wall_height;
	int					wall_ceil;
	int					wall_floor;
	int					x_stripe;
	int					**map;
	int					texture_bit;
	bitmap				clr_wall_draw;
	bitmap				clr_general;
	bitmap				clr_floor;
	bitmap				clr_ceil;
	img_info			img_rndr;
	bitmap_pic_info		north_txtr;
	bitmap_pic_info		south_txtr;
	bitmap_pic_info		east_txtr;
	bitmap_pic_info		west_txtr;
	bitmap_pic_info		item_txtr;
}						raycast;

void            memreset(void **mem);
void            *memrealloc(void *mem, int oldsize, int addbyte);
int             check_filepath(char *path);
map_conf        map_init_input(char *path);
route_pass		*create_list(int x, int y);
route_pass		*add_frwrd(route_pass *cur_list, int x, int y);
int				data_exist(route_pass *init, int x, int y);
void			purge_list(route_pass *init);
int				map_ansys(map_conf obj);
void			calc_map_size(map_conf *obj);
void			impostor_map(map_conf *obj);

#endif
