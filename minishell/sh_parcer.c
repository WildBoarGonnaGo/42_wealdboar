/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/04 21:52:03 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"
#include <stdlib.h>

void		find_elem(t_shell *obj, int pos, int st)
{
	if (!st)
	{
		st |= 0b00010000;
		obj->recycle = ft_strdup("");
	}
	if (obj->line[pos] == '\'' && !(st & 3))
		st |= 2;
	else if (obj->line[pos] == '"' && !(st & 3))
		st |= 1;
	else if (obj->line[pos] == '"' && (st & 1))
	{
		st &= 0b11111110;
		if ((st & 0b1000) == 8)
		{
			obj->argstr = (char *)malloc(pos - obj->readenv);
			ft_strlcpy(obj->argstr, obj->line + obj->readenv, pos - obj->readenv);
			obj->clean = obj->recycle;
			obj->recycle = ft_strjoin(obj->recycle, sh_envp_search(obj->argstr, *obj));
			if (obj->clean)
			{
				free(obj->clean);
				obj->clean = NULL;
			}
		}
	}
	else if (obj->line[pos] == '\'' && (st & 2))
		st &= 0b11111101;
	else if (obj->line[pos] == '\\' && ((st & 5) == 1))
		st |= 4;
	else if ((obj->line[pos] == '\\' || obj->line[pos] == '$' 
	|| obj->line[pos] == '"') && ((st & 5) == 5))
	{
		st &= 0b11111011;
		obj->recycle = addchar(obj->recycle, obj->line[pos]);
	}
	else if ((obj->line[pos] == '$') && (!((st >> 4) & 1) || 
	!((st >> 2) & 1)))
	{
		obj->readenv = (pos + 1);
		st |= 8;
	}
	else if ((obj->line[pos] == ' ' && !(st & 0b11)) || !obj->line[pos])
	{
		obj->recycle = addchar(obj->recycle, 0);
		return ;
	}
	else if ((st & 0b1000) != 8)
		obj->recycle = addchar(obj->recycle, obj->line[pos]);
	find_elem(obj, ++pos, st);
}

t_list	*sh_parcer(t_shell *obj, char *line)
{
	int	info[5];
	
	obj->lst_start = NULL;
	obj->len = 0;
	info[0] = -1;
	info[3] = 0;
	info[4] = 0;
	while (line[++obj->len])
	{
		if (line[obj->len] == ' ')
			continue ;
		else
		{
			info[1] = obj->len;
			find_elem(obj, obj->len, 0);
			info[0] += ft_strlen(obj->recycle);
			info[3] = info[0] - info[1] + 1;
			if (!obj->lst_head)
			{
				obj->lst_start = ft_lstnew(NULL);
				obj->lst_start->content = malloc(info[3]);
				ft_strlcpy(obj->lst_start->content, obj->recycle, info[3]);
				obj->lst_head = obj->lst_start;
			}
			else
			{
				obj->lst_head = ft_lstnew(NULL);
				obj->lst_head->content = malloc(info[3]);
				ft_strlcpy(obj->lst_head->content, obj->recycle, info[3]);
				ft_lstadd_back(&obj->lst_start, obj->lst_head);
			}
			if (obj->recycle)
			{
				free(obj->recycle);
				obj->recycle = NULL;
			}
		}
	}
	return (obj->lst_start);
}
