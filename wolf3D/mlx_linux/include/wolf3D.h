/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:37:56 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/12 16:23:51 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include <string.h>
# include <libft.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

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
    int         pos;
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

void            memreset(void **mem);
void            *memrealloc(void *mem, int oldsize, int addbyte);
int             check_filepath(char *path);
map_conf        map_init_input(char *path);

#endif
