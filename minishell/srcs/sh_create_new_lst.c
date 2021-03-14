/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_new_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:21:00 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:21:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_index_decr(t_shell *obj, int *info)
{
	--info[0];
	obj->err_fst *= 1;
}

void	sh_index_paramexp(t_shell *obj, int *info)
{
	obj->err_fst *= 1;
	info[1] &= ~PARAMEXP;
	info[0] -= (obj->line[info[0]] != obj->spec_char &&
	ft_strchr("><|;", obj->line[info[0]]));
}

void	sh_index_empty(t_shell *obj, int *info)
{
	info[1] *= 1;
	info[0] *= 1;
	obj->err_fst *= 1;
}

void	sh_create_new_lst(t_list **src_lst, t_shell *obj,
		int *info, void (*func)(t_shell *, int *))
{
	t_list	*lst_new;

	func(obj, info);
	lst_new = ft_lstnew(NULL);
	lst_new->content = ft_strdup(obj->recycle);
	ft_lstadd_back(src_lst, lst_new);
	sh_free_str(&obj->recycle);
}
