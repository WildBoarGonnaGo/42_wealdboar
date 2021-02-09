/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:12:18 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/09 21:23:17 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "srcs/libft/libft.h"

int			err_noarg_com(t_shell *obj)
{
	t_list	*grabber;
	int		state[2];

	grabber = obj->lst_start;
	state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
	!(ft_strncmp("|", (char *)grabber->content, 2)) ||
	!(ft_strncmp(">", (char *)grabber->content, 2)) ||
	!(ft_strncmp("<", (char *)grabber->content, 2)));
	if (!grabber)
		return (0);
	while (grabber->next)
	{
		state[0] = (!(ft_strncmp(";", (char *)grabber->content, 2)) ||
		!(ft_strncmp("|", (char *)grabber->content, 2)) ||
		!(ft_strncmp(">", (char *)grabber->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->content, 2)));
		state[1] = (!(ft_strncmp(";", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp("|", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp(">", (char *)grabber->next->content, 2)) ||
		!(ft_strncmp("<", (char *)grabber->next->content, 2)));
		if (state[0] && state[1])
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd((char *)grabber->content, 2);
			ft_putstr_fd("'\n", 2);
			return (0);
		}
		grabber = grabber->next;
	}
	if (grabber == obj->lst_start && state[0])
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd((char *)grabber->content, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}
	return (1);
}

int			no_alnum(char *str)
{
	if (ft_isalnum(*str))
		return (0);
	else if (*str)
		return (no_alnum(++str));
	return (1);
}

void		err_arrow_case(char *str, int count, char c)
{
	if (!*(str + count) || !(ft_strchr("<>", *(str + count))))
	{
		if (count == 5 && (*str + count - 1) == c && c == '<')
			ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
		else if (count == 6 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n", 2);
		else if (count == 6 && c == '<' && *(str + count - 1) == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `<>'\n", 2);
		else if (count >= 7 && c == '<' && *(str + count - 1) == c)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<<'\n", 2);
		else if (count == 4 && (*str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
		else if (count >= 5 && (*str + count - 1) == c && c == '>')
			ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n", 2);
		return ;
	}
	else if ((*str + count))
		err_arrow_case(str, ++count, c);
}

int			err_analisys(t_shell *obj)
{
	int i;
	if (no_alnum(obj->recycle) || ft_strlen(obj->recycle) == 1)
		return (0);
	if (!strncmp(";;", obj->recycle, 2) && ft_strlen(obj->recycle) >= 2)
		ft_putstr_fd("minishell: syntax error near unexpected token `;;'\n", 2);
	else if (!strncmp("|;", obj->recycle, 2))
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	else if (!strncmp("||", obj->recycle, 2) && ft_strlen(obj->recycle) >= 2)
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
	else if (!ft_strncmp("<<<", obj->recycle, 4) || !ft_strncmp("<<", obj->recycle, 3) ||
	!ft_strncmp(">>", obj->recycle, 3) || !ft_strncmp(">", obj->recycle, 2) || 
	!ft_strncmp("<", obj->recycle, 2))
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 1);
	else if (!ft_strncmp("<<<<", obj->recycle, 4) && ft_strlen(obj->recycle) >= 4)
			err_arrow_case(obj->recycle, 4, '<');
	else if (!ft_strncmp(">>>", obj->recycle, 3) && ft_strlen(obj->recycle) >= 3)
			err_arrow_case(obj->recycle, 3, '>');
	return (1);
}

void		find_elem(t_shell *obj, int st)
{
	if (!obj->recycle)
		obj->recycle = ft_strdup("");
	if (ft_strchr(";|<>", obj->line[obj->roll]) && !st)
	{
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
		st |= COMCHAR;
	}
	else if (obj->line[obj->roll] == '\'' && !(st & ISQUOTE))
		st |= 2;
	else if (obj->line[obj->roll] == '"' && !(st & ISQUOTE))
		st |= 1;
	else if (obj->line[obj->roll] == '"' && (st & DQUOTE))
	{
		st &= ~DQUOTE;
		if ((st & 0b1000) == 8)
		{
			obj->argstr = (char *)malloc(obj->roll - obj->readenv + 1);
			ft_strlcpy(obj->argstr, obj->line + obj->readenv, obj->roll - obj->readenv + 1);
			obj->clean = obj->recycle;
			obj->recycle = ft_strjoin(obj->recycle, sh_envp_search(obj->argstr, *obj));
			if (obj->clean)
			{
				free(obj->clean);
				obj->clean = NULL;
			}
		}
	}
	else if (obj->line[obj->roll] == '\'' && (st & SQUOTE))
		st &= ~SQUOTE;
	else if (obj->line[obj->roll] == '\\' && (!(st & (ESCCHAR | SQUOTE))))
		st |= ESCCHAR;
	else if ((obj->line[obj->roll] == '$' || obj->line[obj->roll] == '\\' ||
	obj->line[obj->roll] == '"') && ((st & (ESCCHAR | SQUOTE)) == ESCCHAR))
	{
		st &= ~ESCCHAR;
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
	}
	else if ((obj->line[obj->roll] == '$') && !(st & (ESCCHAR | SQUOTE)))
	{
		obj->readenv = (obj->roll + 1);
		st |= PARAMEXP;
	}
	else if (ft_strchr(";|<>", obj->line[obj->roll]) && !(st & ISQUOTE) && obj->roll)
	{
		--obj->roll;
		return ;
	}
	else if ((obj->line[obj->roll] == ' ' && !(st & 0b11)) || !obj->line[obj->roll])
	{
		if ((st & PARAMEXP) == PARAMEXP)
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
	else if ((st & PARAMEXP) != PARAMEXP)
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
	if ((st & ~COMCHAR) && (st & COMCHAR))
	{
		--obj->roll;
		return ;
	}
	++obj->roll;
	find_elem(obj, st);
}

int			sh_parcer(t_shell *obj, char *line)
{
	int	info[5];
	
	obj->lst_start = NULL;
	obj->roll = -1;
	info[3] = 0;
	info[2] = 0;
	obj->recycle = NULL;
	while (line[++obj->roll])
	{
		if (line[obj->roll] == ' ')
			continue ;
		else
		{
			info[1] = obj->roll;
			find_elem(obj, 0);
			if (!err_analisys(obj))
				return (0);
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
		}
		if (!err_noarg_com(obj))
			return (0);
	}
	return (1);
}
