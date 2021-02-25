/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/23 18:30:44 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"
#include <sys/fcntl.h>

int			err_noarg_com(t_shell *obj)
{
	t_list	*grabber;
	int		state[2];

	grabber = obj->lst_start;
	state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
	!(ft_strncmp("|", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">", (char *)grabber->content, 2)) ||
	!(ft_strncmp("<", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">>", (char *)grabber->content, 3)));
	if (!grabber)
		return (0);
	while (grabber->next)
	{
		state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
		!(ft_strncmp("|", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">", (char *)grabber->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">>", (char *)grabber->content, 3)));
		state[1] = (!(ft_strncmp(";", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp("|", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp(">", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp(">>", (char *)grabber->next->content, 3)));
		if (state[0] && state[1])
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd((char *)grabber->content, 2);
			ft_putstr_fd("'\n", 2);
			return (0);
		}
		/*if (!(ft_strncmp(">", (char *)grabber->content, 2)) && !state[1])
		{
			obj->fd_redir[1] = open((char *)grabber->next->content, 
			O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			dup2(obj->fd_redir[1], 1);
		}
		else if (!(ft_strncmp("<", (char *)grabber->content, 2)) && !state[1])
		{
			obj->fd_redir[0] = open((char *)grabber->next->content, O_RDONLY);
			dup2(obj->fd_redir[0], 1);
		}
		else if (!(ft_strncmp(">>", (char *)grabber->content, 2)) && !state[1])
		{
			obj->fd_redir[1] = open((char *)grabber->next->content, O_RDWR | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			dup2(obj->fd_redir[1], 1);
		}*/
		grabber = grabber->next;
	}
	/*if (grabber == obj->lst_start && state[0])
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd((char *)grabber->content, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}*/
	return (1);
}


void		find_elem(t_shell *obj, int st)
{
	if (!obj->recycle)
		obj->recycle = ft_strdup("");
	if (ft_strchr(";|<>", obj->line[obj->roll]) && !ft_strncmp("", obj->recycle, 1)
	&& obj->line[obj->roll])
	{
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
		st |= COMCHAR;
	}
	else if (obj->line[obj->roll] == '\'' && !(st & ISQUOTE))
		st |= SQUOTE;
	else if (obj->line[obj->roll] == '"' && !(st & ISQUOTE))
		st |= DQUOTE;
	else if (((st & (SQUOTE | PARAMEXP)) == PARAMEXP) && (!ft_isalnum(obj->line[obj->roll]) 
	|| obj->line[obj->roll] == '?'))
	{
		obj->argstr = (char *)malloc(obj->roll - obj->readenv + 1);
		ft_strlcpy(obj->argstr, obj->line + obj->readenv, obj->roll - obj->readenv + 1);
		obj->clean = obj->recycle;
		if (!ft_strncmp("$?", obj->line + obj->roll - 1, 2))
		{
			obj->clunit = ft_itoa(obj->status[0]);
			obj->recycle = ft_strjoin(obj->recycle, obj->clunit);
			if (obj->clunit)
			{
				free(obj->clunit);
				obj->clunit = 0x0;
			}
		}
		else
			obj->recycle = ft_strjoin(obj->recycle, sh_envp_search(obj->argstr, obj));
		if (obj->clean)
		{
			free(obj->clean);
			obj->clean = NULL;
		}
		st &= ~PARAMEXP;
		obj->roll -= (obj->line[obj->roll] != '?');
	}
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
		obj->line[obj->roll] == '"' || obj->line[obj->roll] == ' ')
			obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
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
	else if ((obj->line[obj->roll] == ' ' && !(st & 0b11)) || !obj->line[obj->roll])
	{
		if ((st & PARAMEXP))
		{
			obj->argstr = (char *)malloc(obj->len - obj->readenv + 1);
			ft_strlcpy(obj->argstr, obj->line + obj->readenv, obj->len - obj->readenv + 1);
			obj->clean = obj->recycle;
			obj->recycle = ft_strjoin(obj->recycle, sh_envp_search(obj->argstr, obj));
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
	if (!(st & ~COMCHAR) && (st & COMCHAR) && 
	obj->line[obj->roll] != '>' && obj->line[obj->roll] != '<')
		return ;
	++obj->roll;
	find_elem(obj, st);
}

int			sh_parcer(t_shell *obj, char *line)
{
	int	info[5];
	
	info[3] = 0;
	info[2] = 0;
	obj->recycle = NULL;
	obj->lst_flag[1] = obj->lst_flag[0];
	while (line[++obj->roll])
	{
		if (line[obj->roll] == ' ')
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
			if (obj->recycle)
			{
				free(obj->recycle);
				obj->recycle = NULL;
			}
			if (!(ft_strncmp(";", (char *)obj->lst_head->content, 2)))
				break ;
		}
	}
	return (err_noarg_com(obj));
}