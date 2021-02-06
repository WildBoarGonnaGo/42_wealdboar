/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/06 23:13:15 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"

int			err_analisys(t_shell *obj)
{
		
}

void		find_elem(t_shell *obj, int st)
{
	if (!obj->recycle)
		obj->recycle = ft_strdup("");
	if (obj->line[obj->len] == '\'' && !(st & 3))
		st |= 2;
	else if (obj->line[obj->len] == '"' && !(st & 3))
		st |= 1;
	else if (obj->line[obj->len] == '"' && (st & 1))
	{
		st &= 0b11111110;
		if ((st & 0b1000) == 8)
		{
			obj->argstr = (char *)malloc(obj->len - obj->readenv + 1);
			ft_strlcpy(obj->argstr, obj->line + obj->readenv, obj->len - obj->readenv + 1);
			obj->clean = obj->recycle;
			obj->recycle = ft_strjoin(obj->recycle, sh_envp_search(obj->argstr, *obj));
			if (obj->clean)
			{
				free(obj->clean);
				obj->clean = NULL;
			}
		}
	}
	else if (obj->line[obj->len] == '\'' && (st & 2))
		st &= 0b11111101;
	else if (obj->line[obj->len] == '\\' && (!(st & 0b110)))
		st |= 4;
	else if ((obj->line[obj->len] == '$' || obj->line[obj->len] == 92 ||
	obj->line[obj->len] == '"') && ((st & 6) == 4))
	{
		st &= 0b11111011;
		obj->recycle = addchar(obj->recycle, obj->line[obj->len]);
	}
	else if ((obj->line[obj->len] == '$') && !(st & 0b110))
	{
		obj->readenv = (obj->len + 1);
		st |= 8;
	}
	else if ((obj->line[obj->len] == ';') && !(st & 0b11))
	{
		--obj->len;
		return ;
	}
	else if ((obj->line[obj->len] == ' ' && !(st & 0b11)) || !obj->line[obj->len])
	{
		if ((st & 0b1000) == 8)
		{
			obj->argstr = (char *)malloc(obj->len - obj->readenv + 1);
			ft_strlcpy(obj->argstr, obj->line + obj->readenv, obj->len - obj->readenv + 1);
			obj->clean = obj->recycle;
			obj->recycle = ft_strjoin(obj->recycle, sh_envp_search(obj->argstr, *obj));
			if (obj->clean)
			{
				free(obj->clean);
				obj->clean = NULL;
			}
		}
		else
			obj->recycle = addchar(obj->recycle, 0);
		return ;
	}
	else if ((st & 0b1000) != 8)
	{
		if (ft_strchr("0123456789!;"))
			st |= 16;
		obj->recycle = addchar(obj->recycle, obj->line[obj->len]);
	}
	++obj->len;
	find_elem(obj, st);
}

void		sh_parcer(t_shell *obj, char *line)
{
	int	info[5];
	
	obj->lst_start = NULL;
	obj->len = -1;
	info[3] = 0;
	obj->recycle = NULL;
	while (line[++obj->len])
	{
		if (line[obj->len] == ' ')
			continue ;
		else
		{
			info[1] = obj->len;
			find_elem(obj, 0);
			info[3] = ft_strlen(obj->recycle) + 1;
			obj->lst_head = ft_lstnew(NULL);
			obj->lst_head->content = malloc(info[3]);
			ft_strlcpy(obj->lst_head->content, obj->recycle, info[3]);
			ft_lstadd_back(&obj->lst_start, obj->lst_head);
			if (obj->recycle)
			{
				free(obj->recycle);
				obj->recycle = NULL;
			}
		}
	}
}
