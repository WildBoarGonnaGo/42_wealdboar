/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/01 21:21:16 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"
#include <stdlib.h>

void		find_elem(t_shell *obj, int pos, int *st)
{
	if (!st)
		obj->recycle = ft_strdup("");
	if (obj->line[pos] == '\'' && !(*st & 3))
		*st |= 2;
	else if (obj->line[pos] == '"' && !(*st & 3))
		*st |= 1;
	else if (obj->line[pos] == '"' && (*st & 1))
		*st &= 0b11111110;
	else if (obj->line[pos] == '\'' && (*st & 2))
		*st &= 0b11111101;
	else if (obj->line[pos] == '\\' && ((*st & 5) == 1))
		*st |= 4;
	else if ((obj->line[pos] == '\\' || obj->line[pos] == '$' 
	|| obj->line[pos] == '"') && ((*st & 5) == 5))
	{
		*st &= 0b11111011;
		obj->recycle = addchar(obj->recycle, obj->line[pos]);
	}
	else if (obj->line[pos[0]] == '$' !(obj))
		obj.st = pos[0]
	else if (obj->line[pos] == ' ' && !(*st & 0b11))
		return ;
	else
		obj->recycle = addchar(obj->recycle, obj->line[pos]);
	find_elem(obj, ++pos, st);
}

t_list	*sh_parcer(t_shell *obj, char *line)
{
	int	info[5];
	
	obj->lst_start = NULL;
	info[0] = -1;
	info[3] = 0;
	info[4] = 0;
	while (line[++info[0]])
	{
		if (line[info[0]] == ' ')
			continue ;
		else
		{
			info[1] = info[0];
			find_elem(obj, info[1], &info[4]);
			info[3] = info[2] - info[1];
			if (!obj->lst_head)
			{
				obj->lst_start = ft_lstnew(NULL);
				obj->lst_start->content = malloc(info[3] + 1);
				ft_memcpy(obj->lst_start->content, line + info[1], info[3] - 1);
				obj->lst_head = obj->lst_start;
			}
			else
			{
				obj->lst_head = ft_lstnew(NULL);
				obj->lst_head->content = malloc(info[3] + 1);
				ft_memcpy(obj->lst_start->content, line + info[1], info[3] - 1);
				ft_lstadd_back(&obj->lst_start, obj->lst_head);
			}
		}
	}
	return (obj->lst_start);
}
