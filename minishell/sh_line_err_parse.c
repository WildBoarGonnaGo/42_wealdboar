/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_err_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:21:10 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/10 18:49:14 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	sh_line_err_parse(t_shell *obj)
{
	t_list	*lst_start;
	t_list	*lst_new;
	int		info[3];

	info[0] = -1;
	info[1] = 0;
	lst_start = NULL;
	obj->recycle = ft_strdup("");
	obj->spec_char = 0;
	obj->err_status = 0;
	while (obj->line[++info[0]])
	{
		if (!obj->recycle)
			obj->recycle = ft_strdup("");
		if (ft_strchr("><;|", obj->line[info[0]]) &&
		!(info[1] & (ISQUOTE | PARAMEXP)) && !ft_strncmp(obj->recycle, "", 1))
		{
			info[1] |= PARAMEXP;
			obj->recycle = addchar(obj->recycle, obj->line[info[0]]);
			obj->spec_char = obj->line[info[0]];
		}
		else if (obj->line[info[0]] == '\'' && !(info[1] & ISQUOTE))
		{
			info[1] |= SQUOTE;
			obj->recycle = addchar(obj->recycle, '\'');
		}
		else if (obj->line[info[0]] == '\'' && ((info[1] & ISQUOTE) == SQUOTE))
		{
			info[1] &= ~SQUOTE;
			obj->recycle = addchar(obj->recycle, '\'');
		}
		else if (obj->line[info[0]] == '"' && !(info[1] & ISQUOTE))
		{
			info[1] |= DQUOTE;
			obj->recycle = addchar(obj->recycle, '"');
		}
		else if (obj->line[info[0]] == '"' && ((info[1] & ISQUOTE) == DQUOTE))
		{
			info[1] &= ~DQUOTE;
			obj->recycle = addchar(obj->recycle, '"');
		}
		else if ((obj->line[info[0]] == ' ' && !info[1]))
		{
			lst_new = ft_lstnew(NULL);
			lst_new->content = ft_strdup(obj->recycle);
			ft_lstadd_back(&lst_start, lst_new);
			sh_free_str(&obj->recycle);
		}
		else if (ft_strchr("><;|", obj->line[info[0]]) &&
		!(info[1] & (ISQUOTE | PARAMEXP)))
		{
			--info[0];
			lst_new = ft_lstnew(NULL);
			lst_new->content = ft_strdup(obj->recycle);
			ft_lstadd_back(&lst_start, lst_new);
			sh_free_str(&obj->recycle);
		}
		else if ((info[1] & PARAMEXP) &&
		(!ft_strchr("><|;", obj->line[info[0]]) ||
		obj->line[info[0]] != obj->spec_char))
		{
			info[1] &= ~PARAMEXP;
			info[0] -= (obj->line[info[0]] != obj->spec_char &&
			ft_strchr("><|;", obj->line[info[0]]));
			lst_new = ft_lstnew(NULL);
			lst_new->content = ft_strdup(obj->recycle);
			ft_lstadd_back(&lst_start, lst_new);
			sh_free_str(&obj->recycle);
		}
		else
			obj->recycle = addchar(obj->recycle, obj->line[info[0]]);
		info[0] += (obj->line[info[0]] == '\\');
	}
	if (obj->recycle)
	{
		lst_new = ft_lstnew(NULL);
		lst_new->content = ft_strdup(obj->recycle);
		ft_lstadd_back(&lst_start, lst_new);
		sh_free_str(&obj->recycle);	
	}
	lst_new = lst_start;
	while (lst_new)
	{
		if (sh_err_analisys((char *)lst_new->content, obj))
			break ;
		lst_new = lst_new->next;
	}
	info[1] = sh_err_noarg_com(lst_start, obj);
	info[0] = (lst_new == NULL);
	ft_lstclear(&lst_start, free);
	sh_free_str(&obj->recycle);
	return (info[0] & info[1]);
}
