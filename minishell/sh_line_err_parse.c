/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_err_parce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:21:10 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/07 02:53:21 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	sh_line_err_parse(t_shell *obj)
{
	t_list	*lst_start;
	t_list	*lst_new;
	int		info[2];

	info[0] = -1;
	info[1] = 0;
	lst_start = NULL;
	obj->recycle = ft_strdup("");
	while (obj->line[++info[0]])
	{
		if (ft_strchr("><;|", obj->line[info[0]]) &&
		!(info[1] & (ISQUOTE | PARAMEXP)) && !ft_strncmp(obj->recycle, "", 1))
		{
			info[1] |= PARAMEXP;
			obj->recycle = addchar(obj->recycle, obj->line[info[0]]);
		}
		if (obj->line[info[0]] == '\'' && !(info[1] & ISQUOTE))
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
		else if (obj->line[info[0]] == ' ' && !info[1])
		{
			lst_new = ft_lstnew(obj->recycle);
			ft_lstadd_back(&lst_start, lst_new);
			sh_free_str(&obj->recycle);
			obj->recycle = ft_strdup("");
		}
		else if (ft_strchr("><;|", obj->line[info[0]]) &&
		!(info[1] & (ISQUOTE | PARAMEXP)))
		{
			--info[0];
			lst_new = ft_lstnew(obj->recycle);
			ft_lstadd_back(&lst_start, lst_new);
			sh_free_str(&obj->recycle);
			obj->recycle = ft_strdup("");
		}
		else if ((info[1] & PARAMEXP) &&
		!ft_strchr("><|;", obj->line[info[0]]))
		{
			--info[0];
			lst_new = ft_lstnew(obj->recycle);
			ft_lstadd_back(&lst_start, lst_new);
			sh_free_str(&obj->recycle);
			obj->recycle = ft_strdup("");
		}
	}
	lst_new = lst_start;
	info[0] = 0;
	while (lst_new)
	{
		if (sh_err_analisys((char *)lst_new->content, obj))
			break ;
		lst_new = lst_new->next;
	}
	return (lst_new == NULL);
}
