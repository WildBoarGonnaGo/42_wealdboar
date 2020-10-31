/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_forked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:59:43 by lchantel          #+#    #+#             */
/*   Updated: 2020/10/23 16:32:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maze3d.h"

t_route_pass			*create_list(int x, int y)
{
	t_route_pass			*new_list;

	if (!(new_list = (t_route_pass *)malloc(sizeof(t_route_pass))))
		return (NULL);
	new_list->x = x;
	new_list->y = y;
	new_list->next = NULL;
	new_list->dir = STRT_DIR;
	new_list->prev = new_list;
	return (new_list);
}

t_route_pass			*add_frwrd(t_route_pass *cur_list, int x, int y)
{
	t_route_pass			*obj_frwrd;

	obj_frwrd = (t_route_pass *)malloc(sizeof(t_route_pass));
	obj_frwrd->x = x;
	obj_frwrd->y = y;
	obj_frwrd->dir = STRT_DIR;
	obj_frwrd->next = NULL;
	obj_frwrd->prev = cur_list;
	obj_frwrd->prev->next = obj_frwrd;
	return (obj_frwrd);
}

void					purge_list(t_route_pass *init)
{
	t_route_pass	*roll;
	t_route_pass	*purge;

	roll = init;
	while (roll)
	{
		purge = roll;
		roll = roll->next;
		memreset((void **)&purge);
	}
}
