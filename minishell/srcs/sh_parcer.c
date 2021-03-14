/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:25:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	sh_parcer_body(int *info, t_shell *obj)
{
	info[1] = obj->roll;
	find_elem(obj, 0);
	++obj->lst_flag[0];
	info[3] = ft_strlen(obj->recycle) + 1;
	obj->lst_head = ft_lstnew(NULL);
	obj->lst_head->content = ft_strdup(obj->recycle);
	ft_lstadd_back(&obj->lst_start, obj->lst_head);
	if (!info[2])
	{
		obj->lst_newoper = obj->lst_head;
		info[2] = 1;
	}
	if (!(ft_strncmp((char *)obj->lst_newoper->content,
	"export", ft_strlen("export") + 1)))
		obj->is_export = 1;
	sh_free_str(&obj->recycle);
	return ((ft_strncmp(";", (char *)obj->lst_head->content,
	2) != 0x0));
}

int	sh_parcer(t_shell *obj)
{
	int	info[5];

	info[3] = 0;
	info[2] = 0;
	obj->recycle = NULL;
	obj->is_export = 0;
	obj->lst_flag[1] = obj->lst_flag[0];
	if (obj->roll >= 0)
		obj->roll -= (obj->line[obj->roll] != ' ');
	while (obj->line[++obj->roll])
	{
		if (obj->line[obj->roll] == ' ')
			continue ;
		else
		{
			if (!sh_parcer_body(info, obj))
				break ;
		}
	}
	return (1);
}
