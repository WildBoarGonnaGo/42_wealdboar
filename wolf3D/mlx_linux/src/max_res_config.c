/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_res_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:06:36 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 15:27:49 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"
#include "../include/get_next_line_bonus.h"

void	max_res_alloc_err_fst(t_map_conf *obj)
{
	memreset((void **)&obj->arr_purge);
	ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
	exit(-1);
}

void	max_res_alloc_err_sec(t_map_conf *obj)
{
	int	i;

	i = -1;
	memreset((void **)&obj->arr_purge);
	obj->arr_size = check_arr_size(obj->info_handle);
	while (++i < obj->arr_size)
		memreset((void **)(obj->info_handle + i));
	memreset((void **)&obj->info_handle);
	ft_putstr_fd("Error.\nDynamic memory allocation error.\n", 2);
	exit(-1);
}

void	mem_res_purge(t_map_conf *obj, char **res)
{
	int	i;

	i = -1;
	memreset((void **)&obj->arr_purge);
	obj->arr_size = check_arr_size(obj->info_handle);
	while (++i < obj->arr_size)
		memreset((void **)(obj->info_handle + i));
	i = -1;
	while (++i < 2)
		memreset((void **)(res + i));
	memreset((void **)&res);
	memreset((void **)&obj->info_handle);
}

void	max_res_config(t_map_conf *obj)
{
	char *line;
	char **res;

	obj->info_handle = NULL;
	obj->max_res[0] = 0;
	obj->max_res[1] = 0;
	if (!check_filepath("./res_config.txt"))
		path_exit();
	obj->file_dscrptr = open("./res_config.txt", O_RDONLY);
	while (get_next_line(obj->file_dscrptr, &line))
	{
		obj->arr_purge = line;
		if (!(obj->info_handle = ft_split(line, ' ')))
			max_res_alloc_err_fst(obj);
		if (!(res = ft_split(*obj->info_handle, 'x')))
			max_res_alloc_err_sec(obj);
		obj->max_res[0] = ft_atoi(*res);
		obj->max_res[1] = ft_atoi(*(res + 1));
		mem_res_purge(obj, res);
	}
	memreset((void **)&line);
}
