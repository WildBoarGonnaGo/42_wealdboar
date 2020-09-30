/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:34:39 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/29 23:16:01 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/wolf3D.h"
#include <libft.h>

/*
 typedef struct  data
{
    int         file_dscrptr;
    int         width;
    int         height;
    int         resolution;
    bitmap		flr_color;
    bitmap		ceil_color;
    int         map_stat;
	int			**map_grid;
	int         player_pos[2];
	int			map_size[2];
	double		obj->player_dir[2];
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
/*void            *memrealloc(void *mem, int oldsize, int addbyte);*/

/*typedef	struct			check_list
{
	int					x;
	int					y;
	double				dir;
	struct check_list	*next;
	struct check_list	*prev;	
}						route_pass;*/

route_pass				*create_list(int x, int y)
{
	route_pass			*new_list;

	if (!(new_list = (route_pass *)malloc(sizeof(route_pass))))
		return (NULL);
	new_list->x = x;
	new_list->y = y;
	new_list->next = NULL;
	new_list->dir = STRT_DIR;
	new_list->prev = new_list;
	return (new_list);
}

route_pass				*add_frwrd(route_pass *cur_list, int x, int y)
{
	route_pass			*obj_frwrd;

	obj_frwrd = (route_pass *)malloc(sizeof(route_pass));
	obj_frwrd->x = x;
	obj_frwrd->y = y;
	obj_frwrd->dir = STRT_DIR;
	obj_frwrd->next = NULL;
	obj_frwrd->prev = cur_list;
	return (obj_frwrd);
}

/*int						data_exist(route_pass *init, int x, int y)
{
	route_pass	*roll;

	roll = init;
	while (roll)
	{
		if (roll->x == x && roll->y == y)
			return (1);
		roll = roll->next;
	}
	return (0);
}*/

void					purge_list(route_pass *init)
{
	route_pass	*roll;
	route_pass	*purge;
	roll = init;
	while (roll)
	{
		purge = roll;
		roll = roll->next;
		memreset((void **)&purge);
	}
}

void	print_matrix(map_conf obj_gl)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < obj_gl.map_size[0])
	{
		while (++j < obj_gl.map_size[1])
			(j < obj_gl.map_size[1] - 1) ? printf("%d", obj_gl.map_grid[i][j]) : printf("%d\n", obj_gl.map_grid[i][j]);
		j = -1;
	}
}

/*int						check_player_pos(map_conf obj)
{
	int		info[2];
	double	alpha;

	alpha = 0;
	info[0] = -1;
	info[1] = -1;
	--obj.player_pos[0];
	--obj.player_pos[1];
	while (++info[0] < 4)
	{
		while (++info[1] < 3)
		{
			if (!obj.map_grid[obj.player_pos[0]][obj.player_pos[1]])
				return (0);
			obj.player_pos[0] += (int)cos(alpha);
			obj.player_pos[1] += (int)sin(alpha);
		}
		alpha += M_PI / 2;
		info[1] = -1;
	}
	return (1);
}*/

int						map_ansys(map_conf obj)
{
	int			dir[2];
	route_pass	*init;
	route_pass	*cur;

	init = create_list(obj.player_pos[0], obj.player_pos[1]);
	obj.map_grid[obj.player_pos[0]][obj.player_pos[1]] = 1;
	cur = init;
	while (init->dir)
	{
		dir[0] = (int)cos(cur->dir);
		dir[1] = (int)sin(cur->dir);
		if (obj.player_pos[0] == 0 || obj.player_pos[0] == obj.map_size[0] - 1
		|| obj.player_pos[1] == 0 || obj.player_pos[1] == obj.map_size[1] - 1)
		{
			purge_list(init);
			return (0);
		}
		else if (obj.map_grid[obj.player_pos[0]][obj.player_pos[1]]
		&& !cur->dir)
		{
			obj.player_pos[0] = cur->prev->x;
			obj.player_pos[1] = cur->prev->y;
			cur = cur->prev;
			purge_list(cur->next);
		}
		else if (!(obj.map_grid[obj.player_pos[0] + dir[0]]
		[obj.player_pos[1] + dir[1]]))
		{
			obj.player_pos[0] += dir[0];
			obj.player_pos[1] += dir[1];
			obj.map_grid[obj.player_pos[0]][obj.player_pos[1]] = 1;
			cur = add_frwrd(cur, obj.player_pos[0], obj.player_pos[1]);
		}
		else
		{
			cur->dir -= M_PI / 2;
			if (cur == init)
				purge_list(cur->next);
		}
	}
	return(1); 
}

void						calc_map_size(map_conf *obj)
{
	int	i;

	i = -1;
	obj->map_size[0] = obj->slot;
	while (++i < obj->map_size[0])
		if (obj->map_size[1] < (int)ft_strlen(*(obj->map + i)))
			obj->map_size[1] = (int)ft_strlen(*(obj->map + i));
}

int							impostor_map(map_conf *obj)
{
	int	pos[2];
	
	pos[0] = -1;
	pos[1] = -1;
	obj->map_grid = (int **)malloc(sizeof(int *) * obj->map_size[0]);
	while (++pos[0] < obj->map_size[0])
	{
		*(obj->map_grid + pos[0]) = (int *)malloc(sizeof(int) * obj->map_size[1]);
		while (++pos[1] < obj->map_size[1])
		{
			if (ft_strchr("NSWE", *(*(obj->map + pos[0]) + pos[1])) &&
			*(*(obj->map + pos[0]) + pos[1]))
			{
				obj->player_pos[0] = pos[0];
				obj->player_pos[1] = pos[1];
				if (*(*(obj->map + pos[0]) + pos[1]) == 'N')
				{
					obj->player_dir[0] = FOV_PROJ_LEN;
					obj->player_dir[1] = -1;
				}
				else if (*(*(obj->map + pos[0]) + pos[1]) == 'S')
				{
					obj->player_dir[0] = -FOV_PROJ_LEN;
					obj->player_dir[1] = 1;
				}
				else if (*(*(obj->map + pos[0]) + pos[1]) == 'W')
				{
					obj->player_dir[0] = -1;
					obj->player_dir[1] = -FOV_PROJ_LEN;
				}
				else if (*(*(obj->map + pos[0]) + pos[1]) == 'E')
				{
					obj->player_dir[0] = 1;
					obj->player_dir[1] = FOV_PROJ_LEN;
				}
				if (!obj->player_dir[0])
					return (0);
				*(*(obj->map_grid + pos[0]) + pos[1]) = 4;
			}
			else if (*(*(obj->map + pos[0]) + pos[1]) == '1')
				*(*(obj->map_grid + pos[0]) + pos[1]) = 1;
			else if (*(*(obj->map + pos[0]) + pos[1]) == '2')
				*(*(obj->map_grid + pos[0]) + pos[1]) = 2;
			else 
				*(*(obj->map_grid + pos[0]) + pos[1]) = 0;	
		}
		pos[1] = -1;
	}
	return (1);
}

/*int 	main(int argc, char *argv[])
{
    map_conf	map;
	int			i;

	i = 0;
    if (argc != 2)
    {
        perror("Wrong number of arguments.\n");
        return (0);
    }
    map = map_init_input(argv[1]);
	calc_map_size(&map);	
    printf("Floor color code: %lx\n", map.flr_color._clrfull);
    printf("Ceil color code: %lx\n\n", map.ceil_color._clrfull);
	while (i < map.slot)
		printf("%s\n", *(map.map + i++));
	printf("\nImpostor map-grid:\n\n");
	impostor_map(&map);
	print_matrix(map);
	printf("Map status: %s", ((map_ansys(map)) ? "Map is valid\n\n" : "Map is invalid\n\n"));
    return (0);
}*/
