/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 23:24:18 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/11 05:38:59 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"
#include "../include/colors.h"
#include <libft.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/wolf3D.h"

void    memreset(void **mem)
{
    if (*mem)
    {
        free(*mem);
        *mem = NULL;
    }
}

void    *memrealloc(void *mem, int oldsize, int addbyte)
{
    void    *mem_to_purge;
	void	*res;
    int     indx;

    indx = -1;    
    mem_to_purge = mem;
    res = malloc(oldsize + addbyte);
    while (++indx < oldsize && mem)
        *(char *)(res + indx) = *(char *)(mem_to_purge + indx);
    while (indx < oldsize + addbyte)
        *(char *)(res + indx++) = 0;
    memreset(&mem_to_purge);
    return (res);
}

int             check_filepath(char *path)
{
    int fd;

    if ((fd = open(path, O_RDONLY)) < 0)
    {
        perror(strerror(errno));
        exit(0);
    }
    if (close(fd) < 0)
    {
        perror(strerror(errno));
        exit(0);
    }
    return (1);
}

void            map_stat_init(map_conf *init)
{
    init->file_dscrptr = 0;
    init->width = 0;
    init->height = 0;
    init->resolution = 0;
    init->flr_color = 0;
    init->ceil_color = 0;
    init->map_stat = 0;
    init->pos = 0;
    init->info_handle = NULL;
    init->no_txtr_path = NULL;
    init->so_txtr_path = NULL;
    init->we_txtr_path = NULL;
    init->ea_txtr_path = NULL;
    init->s_txtr_path = NULL;
    init->color = NULL;
    init->map = NULL;
	init->map_grid = NULL;
}

void            strcolor_reset(map_conf *init)
{
    memreset((void **)&(*(init->color)));
    memreset((void **)&(*(init->color + 1)));
    memreset((void **)&(*(init->color + 2)));
    memreset((void **)&init->color);
}

map_conf        map_init_input(char *path)
{
    char        *line;
    map_conf    cub_stat;
    bitmap      cl_color;
    bitmap      fl_color;

	map_stat_init(&cub_stat);
    cl_color._clrfull = 0;
    fl_color._clrfull = 0;
    check_filepath(path);
    cub_stat.file_dscrptr = open(path, O_RDONLY);
	while ((get_next_line(cub_stat.file_dscrptr, &line)) > 0)
    {
        cub_stat.info_handle = ft_split(line, ' ');
        if (!*cub_stat.info_handle)
        {
            cub_stat.info_handle = (char **)malloc(sizeof(char *));
            *cub_stat.info_handle = ft_strdup("");
        } 
        if (!ft_strncmp("R", *cub_stat.info_handle, 1))
        {
            cub_stat.width = ft_atoi(*(cub_stat.info_handle + 1));
            cub_stat.height = ft_atoi(*(cub_stat.info_handle + 2));
        }
        else if (!ft_strncmp("NO", *cub_stat.info_handle, 2))
        {
            if (check_filepath(*(cub_stat.info_handle + 1)))
                cub_stat.no_txtr_path = ft_strdup(*(cub_stat.info_handle + 1));
        }
        else if (!ft_strncmp("SO", *cub_stat.info_handle, 2))
        {
            if (check_filepath(*(cub_stat.info_handle + 1)))
                cub_stat.so_txtr_path = ft_strdup(*(cub_stat.info_handle + 1));
        }
        else if (!ft_strncmp("WE", *cub_stat.info_handle, 2))
        {
            if (check_filepath(*(cub_stat.info_handle + 1)))
                cub_stat.we_txtr_path = ft_strdup(*(cub_stat.info_handle + 1));
        }
        else if (!ft_strncmp("EA", *cub_stat.info_handle, 2))
        {
            if (check_filepath(*(cub_stat.info_handle + 1)))
                cub_stat.we_txtr_path = ft_strdup(*(cub_stat.info_handle + 1));
        }
        else if (!ft_strncmp("S", *cub_stat.info_handle, 1))
        {
            if (check_filepath(*(cub_stat.info_handle + 1)))
                 cub_stat.we_txtr_path = ft_strdup(*(cub_stat.info_handle + 1));
        }
        else if (!ft_strncmp("F", *cub_stat.info_handle, 1))
        {
            cub_stat.color = ft_split(*(cub_stat.info_handle + 1), ',');
            fl_color.red = ft_atoi(*(cub_stat.color));
            fl_color.green = ft_atoi(*(cub_stat.color + 1));
            fl_color.blue = ft_atoi(*(cub_stat.color + 2));
            set_color(&fl_color, 0, fl_color.red, fl_color.green, fl_color.blue);
			cub_stat.flr_color = fl_color._clrfull;
            strcolor_reset(&cub_stat);
        }
        else if (!ft_strncmp("C", *cub_stat.info_handle, 1))
        {
            cub_stat.color = ft_split(*(cub_stat.info_handle + 1), ',');
            cl_color.red = ft_atoi(*(cub_stat.color));
            cl_color.green = ft_atoi(*(cub_stat.color + 1));
            cl_color.blue = ft_atoi(*(cub_stat.color + 2));
            set_color(&cl_color, 0, cl_color.red, cl_color.green, cl_color.blue);
			cub_stat.ceil_color = cl_color._clrfull; 
            strcolor_reset(&cub_stat);
        }
        else if (!**cub_stat.info_handle)
		{
			memreset((void **)*cub_stat.info_handle);
			memreset((void **)cub_stat.info_handle);
			memreset((void **)&line);
            continue ;
		}
        else
        {
            cub_stat.map = (char **)memrealloc(cub_stat.map, sizeof(char *) * cub_stat.pos, sizeof(char *));
            *(cub_stat.map + cub_stat.pos++ )= ft_strdup(line);
			memreset((void **)cub_stat.info_handle);	
        }
        memreset((void **)&line);
    }
	cub_stat.map = (char **)memrealloc(cub_stat.map, sizeof(char *) * cub_stat.pos, sizeof(char *));
	*(cub_stat.map + cub_stat.pos++ )= ft_strdup(line);
	memreset((void **)cub_stat.info_handle);
	memreset((void **)&line);
    return (cub_stat);
}