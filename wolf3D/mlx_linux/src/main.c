/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:34:39 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/27 23:18:36 by lchantel         ###   ########.fr       */
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
/*void            *memrealloc(void *mem, int oldsize, int addbyte);*/

typedef	struct			check_list
{
	int					x;
	int					y;
	struct check_list	*next;
	struct check_list	*prev;	
}						route_pass;

route_pass				*create_list(int x, int y)
{
	route_pass			*new_list;

	if (!(new_list = (route_pass *)malloc(sizeof(route_pass))))
		return (NULL);
	new_list->x = x;
	new_list->y = y;
	new_list->next = NULL;
	new_list->prev = new_list;
	return (new_list);
}

route_pass				*add_frwrd(route_pass *cur_list, int x, int y)
{
	route_pass			*obj_frwrd;

	obj_frwrd = (route_pass *)malloc(sizeof(route_pass));
	obj_frwrd->x = x;
	obj_frwrd->y = y;
	obj_frwrd->next = NULL;
	obj_frwrd->prev = cur_list;
	return (obj_frwrd);
}

int						data_exist(route_pass *init, int x, int y)
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
}

void					purge_list(route_pass *init)
{
	route_pass	*roll;
	route_pass	*purge;
	roll = init;
	while (roll)
	{
		purge = roll;
		roll = roll->next;
		memreset((void **)purge);
	}
}

int						map_ansys(map_conf obj)
{
	int			info[4];
	double		dir[2];
	route_pass	*init;
	route_pass	*cur;

	info[0] = 1;
	info[1] = 0;
	info[2] = 0;
	info[3] = 1;
	dir[0] = M_PI;
	dir[1] = 0;
	while (obj.map[0][info[1]++] != '1')
		;
	init = create_list(info[0], info[1]);
	cur = init;
	while (!info[2])
	{
		if (dir[1] == -2 * M_PI)
		{
			dir[1] = 0;
			dir[0] = M_PI;
			cur = cur->prev;
			if (cur == init)
				return (1);
		}
		else if ((obj.map[(int)(info[0] + sin(dir[0]))][(int)(info[1] + cos(dir[0]))] == '1')
		|| data_exist(init, info[0] + sin(dir[0]), info[1] + cos(dir[0])))
		{
			dir[0] -= M_PI / 2;
			dir[1] -= M_PI / 2;
		}
		else
		{
			if (!info[0] || (info[0] == obj.map_size[0] - 1) || !info[1] || (info[1] == obj.map_size[1] - 1))
				return (0);
			if (cur->next)
			{	
				if (!(cur->next->x == (int)(info[0] + sin(dir[0])) && cur->next->y == (int)(info[1] + cos(dir[0]))))
					purge_list(cur->next);
			}
			else
			{
				info[0] += (int)sin(dir[0]);
				info[1] += (int)cos(dir[0]);
				cur = add_frwrd(cur, info[0], info[1]);
				dir[0] = M_PI;
				dir[1] = 0;	
			}
			if (cur->x == init->x && cur->y == init->y)
			{
				purge_list(init);
				info[2] = 1;
			}
		}
	}
	return (1);
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

/*void	map_stats_reset()
{
	int		str_clean;

}*/

int 	main(int argc, char *argv[])
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
    printf("Ceil color code: %lx\n", map.ceil_color._clrfull);
	printf("Total number of strings: %d\n", map.slot);
	printf("Map status: %s", ((map_ansys(map)) ? "Map is valid\n\n" : "Map is invalid\n\n"));
	while (i < map.slot)
		printf("%s\n", *(map.map + i++));
	printf("\n");
	
    return (0);
}
