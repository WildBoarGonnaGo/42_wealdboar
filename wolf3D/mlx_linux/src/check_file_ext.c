/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:07:47 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/21 15:46:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

void	check_cub_ext(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		ft_putstr_fd("Error.\nInvalid configuration file name.\n", 2);
		exit(-1);
	}
	if (ft_memcmp(filename + len - 4, ".cub", 4))
	{
		ft_putstr_fd("Error.\nInvalid configuration file extension.\n", 2);
		exit(-1);
	}
}

void	check_bmp_ext(char *filename, t_raycast *obj_gl, t_map_conf *cub_stat)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		raycast_exit_proc_mid(obj_gl, cub_stat);
		ft_putstr_fd("Error.\nInvalid bitmap picture file extension.\n", 2);
		exit(-1);
	}
	if (ft_memcmp(filename + len - 4, ".bmp", 4))
	{
		raycast_exit_proc_mid(obj_gl, cub_stat);
		ft_putstr_fd("Error.\nInvalid bitmap picture file extension.\n", 2);
		exit(-1);
	}
}
