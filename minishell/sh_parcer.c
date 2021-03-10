/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/10 19:11:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"
#include <sys/fcntl.h>

int			sh_delims_override(t_shell *obj)
{
	int st;

	st = 0;
	obj->clean = obj->recycle;
	if ((st = ((!ft_strncmp(obj->line + obj->roll, "\";\"", 3) || 
	!ft_strncmp(obj->line + obj->roll, "';'", 3)) && (obj->line[obj->roll + 3] == ' ' 
	|| (obj->line[obj->roll + 3] == '\0')))))
		obj->recycle = ft_strjoin(obj->recycle, "\";\"");
	else if ((st = ((!ft_strncmp(obj->line + obj->roll, "\"|\"", 3) ||
	!ft_strncmp(obj->line + obj->roll, "'|'", 3)) && (obj->line[obj->roll + 3] == ' ' 
	|| (obj->line[obj->roll + 3] == '\0')))))
		obj->recycle = ft_strjoin(obj->recycle, "\"|\"");
	else if ((st = ((!ft_strncmp(obj->line + obj->roll, "\"<\"", 3) ||
	!ft_strncmp(obj->line + obj->roll, "'<'", 3)) && (obj->line[obj->roll + 3] == ' '
	|| (obj->line[obj->roll + 3] == '\0')))))		
		obj->recycle = ft_strjoin(obj->recycle, "\"<\"");
	else if ((st = ((!ft_strncmp(obj->line + obj->roll, "\">\"", 3) || 
	!ft_strncmp(obj->line + obj->roll, "'>'", 3)) && (obj->line[obj->roll + 3] == ' ' 
	|| (obj->line[obj->roll + 3] == '\0')))))
		obj->recycle = ft_strjoin(obj->recycle, "\">\"");
	else if ((st = ((!ft_strncmp(obj->line + obj->roll, "\">>\"", 4) || 
	!ft_strncmp(obj->line + obj->roll, "'>>'", 4)) && (obj->line[obj->roll + 4] == ' '
	|| (obj->line[obj->roll + 4] == '\0')))))
		obj->recycle = ft_strjoin(obj->recycle, "\">>\"");
	obj->roll += 3 * (st != 0) + ((!ft_strncmp(obj->line + obj->roll, "\">>\"", 4)
	|| !ft_strncmp(obj->line + obj->roll, "'>>'", 4)) && (obj->line[obj->roll + 4] == ' '
	|| (obj->line[obj->roll + 4] == '\0')));
	obj->clean = (st) ? obj->clean : 0x0;
	sh_free_str((char **)&obj->clean);
	return (st);
}

void		find_elem(t_shell *obj, int st)
{
	if (!obj->recycle)
		obj->recycle = ft_strdup("");
	sh_delims_override(obj);
	if (((st & (SQUOTE | PARAMEXP)) == PARAMEXP) && (!ft_isalnum(obj->line[obj->roll]) 
	|| obj->line[obj->roll] == '?'))
		obj->roll = sh_env_linefix(obj, &st);
	else if (ft_strchr(";|<>", obj->line[obj->roll]) && !ft_strncmp("", obj->recycle, 1)
	&& obj->line[obj->roll] && !(st & (ESCCHAR | SQUOTE)))
	{
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
		st |= COMCHAR;
	}
	else if (obj->line[obj->roll] == '\'' && !(st & (ISQUOTE | ESCCHAR)))
		st |= SQUOTE;
	else if (obj->line[obj->roll] == '"' && !(st & (ISQUOTE | ESCCHAR)))
		st |= DQUOTE;
	else if (obj->line[obj->roll] == '"' && ((st & (DQUOTE | ESCCHAR)) == DQUOTE))
		st &= ~DQUOTE;
	else if (obj->line[obj->roll] == '\'' && (st & SQUOTE))
		st &= ~SQUOTE;
	else if (obj->line[obj->roll] == '\\' && (!(st & (ESCCHAR | SQUOTE))))
		st |= ESCCHAR;
	else if ((st & (ESCCHAR | SQUOTE)) == ESCCHAR)
	{
		st &= ~ESCCHAR;
		if (obj->line[obj->roll] == 'n')
			obj->recycle = addchar(obj->recycle, '\n');
		else if (obj->line[obj->roll] == '$' || obj->line[obj->roll] == '\\' ||
		obj->line[obj->roll] == '"' || obj->line[obj->roll] == ' ' ||
		obj->line[obj->roll] == '\'' )
			obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
		else if (ft_strchr("<>|;", obj->line[obj->roll]))
		{
			obj->recycle = addchar(obj->recycle, '"');
			obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
			obj->recycle = addchar(obj->recycle, '"');
		}
		else
		{
			obj->recycle = addchar(obj->recycle, obj->line[obj->roll - 1]);
			obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
		}
	}
	else if ((obj->line[obj->roll] == '$') && !(st & (ESCCHAR | SQUOTE)))
	{
		obj->readenv = (obj->roll + 1);
		st |= PARAMEXP;
	}
	else if (ft_strchr(";|<>", obj->line[obj->roll]) && !(st & ISQUOTE) && obj->roll
	&& obj->line[obj->roll] != '>' && obj->line[obj->roll] != '<')
	{
		--obj->roll;
		return ;
	}
	else if ((obj->line[obj->roll] == ' ' && !(st & 0b11))
	|| !obj->line[obj->roll])
	{
		if ((st & PARAMEXP))
			obj->roll = sh_env_linefix(obj, &st);
		else
		{
			obj->recycle = addchar(obj->recycle, 0);
			return ;
		}
	}
	else if ((st & PARAMEXP) != PARAMEXP)
	{
		st |= ((obj->line[obj->roll] == '~') * TOKTWIDDLE);
		if (st & TOKTWIDDLE)
		{
			if (ft_strchr("\0 /.", obj->line[obj->len]))
				obj->recycle = ft_strjoin(obj->recycle, sh_envp_search("HOME", obj));
		}
		else
			obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
	}
	if (!(st & ~COMCHAR) && (st & COMCHAR) && obj->line[obj->roll])
	{
		if ((obj->line[obj->roll] == '>' || obj->line[obj->roll] == '<')
		&& ft_isalnum(obj->line[obj->roll + 1]))
			return ;
	}
	if (!(st & ENVSPACE))
		++obj->roll;
	else
		st &= ~ENVSPACE;
	find_elem(obj, st);
}

int			sh_parcer(t_shell *obj)
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
			info[1] = obj->roll;
			find_elem(obj, 0);
			++obj->lst_flag[0];
			info[3] = ft_strlen(obj->recycle) + 1;
			obj->lst_head = ft_lstnew(NULL);
			obj->lst_head->content = malloc(info[3]);
			ft_strlcpy(obj->lst_head->content, obj->recycle, info[3]);
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
			if (!(ft_strncmp(";", (char *)obj->lst_head->content, 2)))
				break ;
		}
	}
	return (1);
}
