/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:43:55 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/22 01:42:21 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

int	check_textures(t_map_conf obj, int *if_error)
{
	if (!(obj.map_stat & 1))
	{
		ft_putstr_fd("Error.\nNorth wall texture path is not found.\n", 2);
		*if_error = 0;
	}
	if (!((obj.map_stat >> 1) & 1))
	{
		ft_putstr_fd("Error.\nSouth wall texture path is not found.\n", 2);
		*if_error = 0;
	}
	if (!((obj.map_stat >> 2) & 1))
	{
		ft_putstr_fd("Error.\nWest wall texture path is not found.\n", 2);
		*if_error = 0;
	}
	if (!((obj.map_stat >> 3) & 1))
	{
		ft_putstr_fd("Error.\nEast wall texture path is not found.\n", 2);
		*if_error = 0;
	}
	return (1);
}

int	check_colors(t_map_conf obj, int *if_error)
{
	if (!((obj.map_stat >> 4) & 1))
	{
		ft_putstr_fd("Error.\nItem texture path is not found.\n", 2);
		*if_error = 0;
	}
	if (!((obj.map_stat >> 5) & 1))
	{
		ft_putstr_fd("Error.\nFloor color definition error.\n", 2);
		*if_error = 0;
	}
	if (!((obj.map_stat >> 6) & 1))
	{
		ft_putstr_fd("Error.\nCeil color definition error.\n", 2);
		*if_error = 0;
	}
	if (!((obj.map_stat >> 7) & 1))
	{
		ft_putstr_fd("Error.\nDisplay resolution definition error.\n", 2);
		*if_error = 0;
	}
	return (1);
}

int	err_check_input(t_map_conf obj)
{
	int	if_error;

	if_error = 1;
	check_textures(obj, &if_error);
	check_colors(obj, &if_error);
	return (if_error);
}
