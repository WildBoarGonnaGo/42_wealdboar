/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_line_err_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:21:10 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:23:59 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_err_parse_body(t_shell *obj, t_list **lst_start,
		int *info)
{
	if (!obj->recycle)
		obj->recycle = ft_strdup("");
	if (ft_strchr("><;|", obj->line[info[0]]) &&
	!(info[1] & (ISQUOTE | PARAMEXP)) && !ft_strncmp(obj->recycle, "", 1))
		sh_spec_char_handle(obj, PARAMEXP, info, sh_bitwise_or_stat_spec);
	else if (obj->line[info[0]] == '\'' && !(info[1] & ISQUOTE))
		sh_spec_char_handle(obj, SQUOTE, info, sh_bitwise_or_stat);
	else if (obj->line[info[0]] == '\'' && ((info[1] & ISQUOTE) == SQUOTE))
		sh_spec_char_handle(obj, ~SQUOTE, info, sh_bitwise_and_stat);
	else if (obj->line[info[0]] == '"' && !(info[1] & ISQUOTE))
		sh_spec_char_handle(obj, DQUOTE, info, sh_bitwise_or_stat);
	else if (obj->line[info[0]] == '"' && ((info[1] & ISQUOTE) == DQUOTE))
		sh_spec_char_handle(obj, ~DQUOTE, info, sh_bitwise_and_stat);
	else if ((obj->line[info[0]] == ' ' && !info[1]))
		sh_create_new_lst(lst_start, obj, info, sh_index_empty);
	else if (ft_strchr("><;|", obj->line[info[0]]) &&
	!(info[1] & (ISQUOTE | PARAMEXP)))
		sh_create_new_lst(lst_start, obj, info, sh_index_decr);
	else if ((info[1] & PARAMEXP) &&
	(!ft_strchr("><|;", obj->line[info[0]]) ||
	obj->line[info[0]] != obj->spec_char))
		sh_create_new_lst(lst_start, obj, info, sh_index_paramexp);
	else
		obj->recycle = addchar(obj->recycle, obj->line[info[0]]);
	info[0] += (obj->line[info[0]] == '\\');
}

void	sh_err_parse_init(t_shell *obj, t_list **lst_start,
		int *info)
{
	info[0] = -1;
	info[1] = 0;
	*lst_start = NULL;
	obj->recycle = ft_strdup("");
	obj->spec_char = 0;
	obj->err_status = 0;
}

int		sh_line_err_parse(t_shell *obj)
{
	t_list	*lst_start;
	t_list	*lst_new;
	int		info[3];

	sh_err_parse_init(obj, &lst_start, info);
	while (obj->line[++info[0]])
		sh_err_parse_body(obj, &lst_start, info);
	if (obj->recycle)
		sh_create_new_lst(&lst_start, obj, info, sh_index_empty);
	lst_new = lst_start;
	while (lst_new)
	{
		if (sh_err_analisys((char *)lst_new->content, obj))
			break ;
		lst_new = lst_new->next;
	}
	info[1] = sh_err_noarg_com(lst_start, obj);
	info[0] = (lst_new == NULL);
	ft_lstclear(&lst_start, null_lst_unit);
	sh_free_str(&obj->recycle);
	return (info[0] & info[1]);
}
